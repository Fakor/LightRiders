#include "Position.h"

namespace base{

    Position::Position(uint16_t x, uint16_t y)
        : x_{x}, y_{y}
    {

    }

    uint16_t Position::X() const{
        return x_;
    }

    uint16_t Position::Y() const{
        return y_;
    }

    bool operator==(const Position& lhs, const Position& rhs){
        return lhs.X() == rhs.X() && lhs.Y() == rhs.Y();
    }

    bool operator!=(const Position& lhs, const Position& rhs){
        return !(lhs==rhs);
    }
}
