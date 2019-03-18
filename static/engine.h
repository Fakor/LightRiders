#pragma once

#include <string>

#include "standard_definitions.h"

namespace standard {

    class Engine
    {
    public:
        Engine(Agent_S* a0, Agent_S* a1);

        void SetLeftSideStartPosition(base::Position a0_start_position);
    private:
        Agent_S* a0_;
        Agent_S* a1_;

        GridBoard_S board_;
    };

}
