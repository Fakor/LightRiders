#ifndef AGENT_H
#define AGENT_H

#include <iostream> // REMOVE LATER

#include "Position.h"

const uint16_t BUFFER_SIZE = 256;

namespace  base {

    template <int M, int N>
    class Agent{
    public:
        static const uint16_t BOARD_SIZE = N*M;

        Agent(Position start_pos);

        Position& GetPos() {return pos_;}

        const char* CurrentStatus() const;
        void SetStatus(char* status);
    private:
        Position pos_;
        char status_[BOARD_SIZE];

        char buf_[BUFFER_SIZE];
    };

    template <int M, int N>
    Agent<M,N>::Agent(Position start_pos)
        : pos_{start_pos}
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

}



#endif // AGENT_H
