#ifndef BASIC_HELP_H
#define BASIC_HELP_H

#include "status.h"
#include "utility.h"

namespace help {

template<int M, int N>
bool PositionSafe(base::Status<M,N> status, base::Position position){
    if(position.X() < 0 || position.X() >= N || position.Y() < 0 || position.Y() >= M){
        return false;
    }
    return status.GetElement(position) == '.';
}



}


#endif // BASIC_HELP_H
