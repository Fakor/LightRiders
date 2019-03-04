#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>

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

    enum class Direction{
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    struct AgentState{
        AgentState(Position p, Direction d): pos{p}, dir{d} {}
        Position pos;
        Direction dir;
        bool alive = true;
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

    Position NewPositionFromDirection(const Position& pos, const Direction& dir){
        if(dir == Direction::UP){
            return Position(pos.X(), pos.Y()-1);
        } else if(dir == Direction::DOWN){
            return Position(pos.X(), pos.Y()+1);
        } if(dir == Direction::RIGHT){
            return Position(pos.X()+1, pos.Y());
        } else {
            return Position(pos.X()-1, pos.Y());
        }
    }

}


#endif // UTILITY_H
