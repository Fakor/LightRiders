#include "engine.h"

namespace standard {

    Engine::Engine(Agent_S* a0, Agent_S* a1)
        : a0_{a0}, a1_{a1}
    {
        a0_->Connect(board_.GetConnection0());
        a1_->Connect(board_.GetConnection1());
    }

    void Engine::SetLeftSideStartPosition(base::Position a0_start_position){
        base::Position a1_start_position(WIDTH-1-a0_start_position.X(), a0_start_position.Y());
        board_.SetStartPosition(a0_start_position, a1_start_position);
    }

}
