#ifndef BASIC_HELP_H
#define BASIC_HELP_H

#include "status.h"
#include "utility.h"

namespace help {

base::Action NextActionClockwise(base::Action direction);

template<int M, int N>
bool PositionSafe(base::Status<M,N> status, base::Position position){
    if(position.X() < 0 || position.X() >= N || position.Y() < 0 || position.Y() >= M){
        return false;
    }
    return status.GetElement(position) == '.';
}



template<int M, int N>
bool DirectionSafe(base::Status<M,N> status, char name, base::Direction direction){
    base::Position current_position = status.GetPosition(name);
    base::Position new_position = base::PositionInDirection(current_position, direction);
    return PositionSafe(status, new_position);
}

template<int M, int N>
bool DirectionSafe(base::Status<M,N> status, base::Position position, base::Direction direction){
    base::Position new_position = base::PositionInDirection(position, direction);
    return PositionSafe(status, new_position);
}

base::Action NextActionClockwise(base::Action direction);


}


#endif // BASIC_HELP_H
