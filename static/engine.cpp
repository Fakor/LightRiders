#include "engine.h"

namespace standard {

    Engine::Engine(Agent_S* a0, Agent_S* a1)
        : a0_{a0}, a1_{a1}
    {
        a0_->Connect(board_.GetConnection0());
        a1_->Connect(board_.GetConnection1());
    }

    void Engine::SetLeftSideStartPosition(base::Position a0_start_position){
        if(     a0_start_position.X() < 1 ||
                a0_start_position.X() > 6 ||
                a0_start_position.Y() < 1 ||
                a0_start_position.Y() > 14){

            std::string error_message = a0_start_position.ToString() + + " not a valid start position!";
            throw std::invalid_argument(error_message);
        }
        base::Position a1_start_position(WIDTH-1-a0_start_position.X(), a0_start_position.Y());
        board_.SetStartPosition(a0_start_position, a1_start_position);
    }

    void Engine::PerformTurn(){
        a0_->ChooseAction();
        a1_->ChooseAction();
        board_.PerformTurn();
    }

    int Engine::PerformRound(){
        int i = 0;
        while(board_.Agent0Alive() && board_.Agent1Alive()){
            ++i;
            PerformTurn();
        }
        if(board_.Agent0Alive() && !board_.Agent1Alive()){
            ++a0_wins_;
        } else if(!board_.Agent0Alive() && board_.Agent1Alive()){
            ++a1_wins_;
        }
        return i;
    }

    int Engine::A0Wins() const{
        return a0_wins_;
    }

    int Engine::A1Wins() const{
        return a1_wins_;
    }

}
