#include "basic_help.h"

namespace help {

base::Action NextActionClockwise(base::Action direction){
    if(direction == base::Action::UP){
        return base::Action::RIGHT;
    } else if(direction == base::Action::RIGHT){
        return base::Action::DOWN;
    } else if(direction == base::Action::DOWN){
        return base::Action::LEFT;
    } else if(direction == base::Action::LEFT){
        return base::Action::UP;
    } else {
        return base::Action::UP;
    }
}

}
