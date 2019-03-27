#pragma once

#include <string>
#include <random>

#include "standard_definitions.h"

namespace standard {

    class Engine
    {
    public:
        Engine(Agent_S* a0, Agent_S* a1, unsigned int seed=0);

        void Reset(base::Position a0_start_position);
        void ResetRandom();
        bool PerformTurn();
        int PerformRound();

        int A0Wins() const;
        int A1Wins() const;
        int Draws() const;

        void Reset();

        Status_S GetStatus() const;
        const Status_S* GetStatusPtr() const;
    private:
        Agent_S* a0_;
        Agent_S* a1_;

        int a0_wins_{0};
        int a1_wins_{0};
        int draws_{0};

        GridBoard_S board_;

        std::default_random_engine generator_;
        std::uniform_int_distribution<int> dist_x_;
        std::uniform_int_distribution<int> dist_y_;
    };

}
