#include "utility.h"

namespace base{


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

    Position PositionInDirection(base::Position position, base::Direction direction){
        if(direction == base::Direction::UP){
            return Position(position.X(), position.Y()-1);
        } else if(direction == base::Direction::DOWN){
            return Position(position.X(), position.Y()+1);
        } if(direction == base::Direction::RIGHT){
            return Position(position.X()+1, position.Y());
        } else {
            return Position(position.X()-1, position.Y());
        }
    }

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

    Direction DirectionFromAction(Action action, Direction default_dir){
        if(action == Action::UP){
            return Direction::UP;
        } else if (action == Action::DOWN) {
            return Direction::DOWN;
        } else if (action == Action::RIGHT){
            return Direction::RIGHT;
        } else if (action == Action::LEFT){
            return Direction::LEFT;
        } else {
            return default_dir;
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
        return PositionInDirection(state.pos, state.dir);
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
