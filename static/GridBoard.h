#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "Position.h"
#include "agent.h"

namespace base {

    template <int M, int N>
	class GridBoard
	{
	public:

        static const uint16_t BOARD_SIZE = N*M;

        GridBoard(Agent<M,N> &a0, Agent<M,N> &a1);
        virtual ~GridBoard() = default;

        char GetSquareValue(Position pos) const;

        const char* GetStatus() const;
        void SendStatus();
        void Run();
	private:
        char status_[BOARD_SIZE+1];

        Agent<M,N>& a0_;
        Agent<M,N>& a1_;

        void SetSquare(Position pos, char value);
	};


    template<int M, int N>
    GridBoard<M,N>::GridBoard(Agent<M,N> &a0, Agent<M,N> &a1)
        : a0_{a0}, a1_{a1}
    {
        memset(status_, '.', BOARD_SIZE);
        SetSquare(a0_.GetPos(), '0');
        SetSquare(a1_.GetPos(), '1');
        status_[BOARD_SIZE] = '\0';
    }

    template<int M, int N>
    char GridBoard<M,N>::GetSquareValue(Position pos) const{
        return status_[pos.Y()*N + pos.X()];
    }

    template<int M, int N>
    void GridBoard<M,N>::SetSquare(Position pos, char value){
        status_[pos.Y()*N + pos.X()] = value;
    }

    template<int M, int N>
    const char* GridBoard<M,N>::GetStatus() const{
        return status_;
    }

    template<int M, int N>
    void GridBoard<M,N>::SendStatus(){
        a0_.SetStatus(status_);
        a1_.SetStatus(status_);
    }
}

