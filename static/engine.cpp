#include "engine.h"

namespace standard {

    Engine::Engine(Agent_S* a0, Agent_S* a1, unsigned int seed)
        : a0_{a0}, a1_{a1}, generator_{seed}, dist_x_{1, 6}, dist_y_{1, 14}
    {
        a0_->Connect(board_.GetConnection0());
        a1_->Connect(board_.GetConnection1());
    }

    void Engine::Reset(base::Position a0_start_position){
        if(     a0_start_position.X() < 1 ||
                a0_start_position.X() > 6 ||
                a0_start_position.Y() < 1 ||
                a0_start_position.Y() > 14){

            std::string error_message = a0_start_position.ToString() + + " not a valid start position!";
            throw std::invalid_argument(error_message);
        }
        base::Position a1_start_position(WIDTH-1-a0_start_position.X(), a0_start_position.Y());
        board_.Reset(a0_start_position, a1_start_position);
    }

    void Engine::ResetRandom(){
        int16_t x = static_cast<int16_t>(dist_x_(generator_));
        int16_t y = static_cast<int16_t>(dist_y_(generator_));
        Reset(base::Position(x,y));
    }

    bool Engine::PerformTurn(){
        a0_->ChooseAction();
        a1_->ChooseAction();
        board_.PerformTurn();
        return board_.Agent0Alive() && board_.Agent1Alive();
    }

    int Engine::PerformRound(){
        int i = 0;
        while(PerformTurn()){
            ++i;
        }
        if(board_.Agent0Alive() && !board_.Agent1Alive()){
            ++a0_wins_;
        } else if(!board_.Agent0Alive() && board_.Agent1Alive()){
            ++a1_wins_;
        } else {
            ++draws_;
        }
        return i;
    }

    int Engine::A0Wins() const{
        return a0_wins_;
    }

    int Engine::A1Wins() const{
        return a1_wins_;
    }

    int Engine::Draws() const{
        return draws_;
    }

    Status_S Engine::GetStatus() const{
        return board_.GetStatus();
    }

    const Status_S* Engine::GetStatusPtr() const{
        return board_.GetStatusPtr();
    }
}
