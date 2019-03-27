#ifndef BASIC_HELP_H
#define BASIC_HELP_H

#include <cstdlib>
#include <random>
#include <algorithm>

#include "status.h"
#include "utility.h"

namespace help {

base::Action NextActionClockwise(base::Action direction);


template<int M, int N>
bool PositionSafe(const base::Status<M,N>& status, base::Position position){
    if(position.X() < 0 || position.X() >= N || position.Y() < 0 || position.Y() >= M){
        return false;
    }
    return status.GetElement(position) == '.';
}


template<int M, int N>
bool DirectionSafe(const base::Status<M,N>& status, char name, base::Direction direction){
    base::Position current_position = status.GetPosition(name);
    base::Position new_position = base::PositionInDirection(current_position, direction);
    return PositionSafe(status, new_position);
}

template<int M, int N>
bool DirectionSafe(const base::Status<M,N>& status, base::Position position, base::Direction direction){
    base::Position new_position = base::PositionInDirection(position, direction);
    return PositionSafe(status, new_position);
}

template<int M, int N>
class RandomSafeActionGenerator{
public:
    RandomSafeActionGenerator(unsigned int seed)
        : generator_{seed}, dist_{0,3} {}
    base::Action GenerateAction(const base::Status<M,N>& status, const base::Position& pos);
private:
    std::default_random_engine generator_;
    std::uniform_int_distribution<int> dist_;
};

template<int M, int N>
base::Action RandomSafeActionGenerator<M,N>::GenerateAction(const base::Status<M,N>& status, const base::Position& pos){
    std::vector<int> tested_numbers;
    int number;
    while(tested_numbers.size() < 4){
        while(true){
            number = dist_(generator_);
            if(std::find(tested_numbers.begin(), tested_numbers.end(), number) == tested_numbers.end()){
                break;
            }
        }
        if(number == 0 && DirectionSafe(status, pos, base::Direction::UP)){
            return base::Action::UP;
        } else if(number == 1 && DirectionSafe(status, pos, base::Direction::DOWN)){
            return base::Action::DOWN;
        } else if(number == 2 && DirectionSafe(status, pos, base::Direction::LEFT)){
            return base::Action::LEFT;
        } else if(number == 3 && DirectionSafe(status, pos, base::Direction::RIGHT)){
            return base::Action::RIGHT;
        }
        tested_numbers.push_back(number);
    }
    return base::Action::PASS;
}


}


#endif // BASIC_HELP_H
