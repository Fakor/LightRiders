#pragma once

#include <string>

#include "standard_definitions.h"

namespace standard {

    class Engine
    {
    public:
        Engine(Agent_S* a0, Agent_S* a1);

        void SetLeftSideStartPosition(base::Position a0_start_position);
        void PerformTurn();
        int PerformRound();

        int A0Wins() const;
        int A1Wins() const;
    private:
        Agent_S* a0_;
        Agent_S* a1_;

        int a0_wins_{0};
        int a1_wins_{0};

        GridBoard_S board_;
    };

}
