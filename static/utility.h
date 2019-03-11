#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>
#include <string.h>
#include <stdexcept>
#include <ostream>

namespace base {

    class Position
    {
    public:
        Position(int16_t x, int16_t y): x_{x}, y_{y} {}

        int16_t X() const {return x_;}
        int16_t Y() const {return y_;}
    private:
        int16_t x_;
        int16_t y_;
    };

    bool operator==(const Position& lhs, const Position& rhs){
        return lhs.X() == rhs.X() && lhs.Y() == rhs.Y();
    }

    bool operator!=(const Position& lhs, const Position& rhs){
        return !(lhs==rhs);
    }

    std::ostream& operator<<(std::ostream& out, const Position& position){
        out << "[" << position.X() << "," << position.Y() << "]";
        return out;
    }

    enum class Action {
        UP,
        DOWN,
        RIGHT,
        LEFT,
        PASS
    };

    enum class Direction{
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    struct AgentState{
        Position pos{0,0};
        Direction dir{Direction::UP};
        bool alive{true};
        char name{'0'};
        bool first_move{true};
    };

    Direction GetOpositeDirection(Direction dir){
        if(dir == Direction::UP){
            return Direction::DOWN;
        } else if (dir == Direction::DOWN) {
            return Direction::UP;
        } else if (dir == Direction::LEFT){
            return Direction::RIGHT;
        } else {
            return Direction::LEFT;
        }
    }

    void SetDirectionFromAction(Action action, AgentState& state){
        Direction desired_direction;
        if(action == Action::UP){
            desired_direction = Direction::UP;
        } else if (action == Action::DOWN) {
            desired_direction = Direction::DOWN;
        } else if (action == Action::RIGHT){
            desired_direction = Direction::RIGHT;
        } else if (action == Action::LEFT){
            desired_direction = Direction::LEFT;
        } else {
            return;
        }

        if(state.first_move){
            state.first_move = false;
        } else if(desired_direction == GetOpositeDirection(state.dir)){
            return;
        }
        state.dir = desired_direction;
    }

    Position NewPositionFromAction(AgentState& state, Action action){
        SetDirectionFromAction(action, state);
        if(state.dir == Direction::UP){
            return Position(state.pos.X(), state.pos.Y()-1);
        } else if(state.dir == Direction::DOWN){
            return Position(state.pos.X(), state.pos.Y()+1);
        } if(state.dir == Direction::RIGHT){
            return Position(state.pos.X()+1, state.pos.Y());
        } else {
            return Position(state.pos.X()-1, state.pos.Y());
        }
    }

    char* ActionToString(const Action& action, char *buf){
        if(action == Action::UP){
            strcpy(buf, "up");
        } else if (action == Action::DOWN) {
            strcpy(buf, "down");
        } else if (action == Action::LEFT){
            strcpy(buf, "left");
        } else if (action == Action::RIGHT){
            strcpy(buf, "right");
        } else if (action == Action::PASS){
            strcpy(buf, "pass");
        }
        throw std::invalid_argument("Not a known action");
    }

    Action StringToAction(char *buf){
        if(strcmp(buf, "up")){
            return Action::UP;
        } else if (strcmp(buf, "down")) {
            return Action::DOWN;
        } else if (strcmp(buf, "left")){
            return Action::LEFT;
        } else if (strcmp(buf, "right")){
            return Action::RIGHT;
        } else {
            return Action::PASS;
        }
    }

}


#endif // UTILITY_H
