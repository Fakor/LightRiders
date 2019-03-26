#ifndef BASIC_HELP_H
#define BASIC_HELP_H

#include <cstdlib>
#include <random>

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

template<int M, int N>
class RandomSafeActionGenerator{
public:
    RandomSafeActionGenerator(unsigned int seed)
        : generator_{seed}, dist_{0,3} {}
    base::Action GenerateAction();
private:
    std::default_random_engine generator_;
    std::uniform_int_distribution<int> dist_;
};

template<int M, int N>
base::Action RandomSafeActionGenerator<M,N>::GenerateAction(){
    int number = dist_(generator_);
    if(number == 0){
        return base::Action::UP;
    } else if(number == 1){
        return base::Action::DOWN;
    } else if(number == 2){
        return base::Action::LEFT;
    } else if(number == 3){
        return base::Action::RIGHT;
    } else {
        return base::Action::PASS;
    }
}


}


#endif // BASIC_HELP_H
