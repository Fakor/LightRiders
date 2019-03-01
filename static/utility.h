#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>

namespace base {

    class Position
    {
    public:
        Position(uint16_t x, uint16_t y): x_{x}, y_{y} {}

        uint16_t X() const {return x_;}
        uint16_t Y() const {return y_;}
    private:
        uint16_t x_;
        uint16_t y_;
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
