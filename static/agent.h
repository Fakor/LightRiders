#ifndef AGENT_H
#define AGENT_H

#include <iostream> // REMOVE LATER

#include "utility.h"

const uint16_t BUFFER_SIZE = 256;

namespace  base {

    struct AgentState{
        AgentState(Position p, Direction d): pos{p}, dir{d} {}
        Position pos;
        Direction dir;
    };


    template <int M, int N>
    class Agent{
    public:
        static const uint16_t BOARD_SIZE = N*M;

        Agent(Position start_pos, char name);

        AgentState GetState() {return state_;}
        char GetName() {return name_;}

        const char* CurrentStatus() const;
        void SetStatus(char* status);

        void SetDesiredDirection(Direction dir);
        Direction GetDesiredDirection() const;
    private:
        AgentState state_;
        char name_;

        char status_[BOARD_SIZE];

        char buf_[BUFFER_SIZE];
        Direction desired_direction_{Direction::UP};
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
    void Agent<M,N>::SetStatus(char* status){
        strcpy(status_, status);
    }

    template <int M, int N>
    void Agent<M,N>::SetDesiredDirection(Direction dir){
        desired_direction_ = dir;
    }

    template <int M, int N>
    Direction Agent<M,N>::GetDesiredDirection() const{
        return desired_direction_;
    }
}



#endif // AGENT_H
