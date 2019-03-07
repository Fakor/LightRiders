#ifndef AGENT_H
#define AGENT_H

#include <sstream>
#include <thread>

#include "utility.h"

const uint16_t BUFFER_SIZE = 256;

namespace  base {

    template <int M, int N>
    class Agent{
    public:
        static const uint16_t BOARD_SIZE = N*M;

        Agent(Position start_pos, char name);

        AgentState GetState() {return state_;}
        char GetName() {return name_;}

        const char* CurrentStatus() const;
        void ReadStatus();

        void SetDesiredDirection(Direction dir);
        Direction GetDesiredDirection() const;

        bool FirstMove() const {return first_move_;}
        void FirstMoveDone() {first_move_=false;}

        void SetStatusStream(std::stringstream* status_stream);
    private:
        AgentState state_;
        char name_;

        char status_[BOARD_SIZE];

        char buf_[BUFFER_SIZE];
        Direction desired_direction_{Action::UP};
        bool first_move_{true};

        std::stringstream* status_stream_;


    };

    template <int M, int N>
    Agent<M,N>::Agent(Position start_pos, char name)
        :state_{start_pos, Direction::UP}, name_{name}
    {
    }

    template <int M, int N>
    const char* Agent<M,N>::CurrentStatus() const {
        return status_;
    }

    template <int M, int N>
    void Agent<M,N>::ReadStatus(){
        *status_stream_ >> buf_;
        strcpy(status_, buf_);
    }

    template <int M, int N>
    void Agent<M,N>::SetDesiredDirection(Direction dir){
        desired_direction_ = dir;
    }

    template <int M, int N>
    Direction Agent<M,N>::GetDesiredDirection() const{
        return desired_direction_;
    }

    template <int M, int N>
    void Agent<M,N>::SetStatusStream(std::stringstream* status_stream){
        status_stream_ = status_stream;
    }
}



#endif // AGENT_H
