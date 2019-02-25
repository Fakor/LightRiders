#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "Position.h"

namespace base {

    template <int M, int N>
	class GridBoard
	{
	public:
        static const uint16_t BOARD_SIZE = N*M;

        GridBoard(Position p0, Position p1);
        virtual ~GridBoard() = default;

        char GetSquareValue(Position pos) const;

        std::string GameField() const;
	private:
        char squares_[M*N];

        void SetSquare(Position pos, char value);
	};


    template<int M, int N>
    GridBoard<M,N>::GridBoard(Position p0, Position p1)
    {
        memset(squares_, '.', BOARD_SIZE);
        SetSquare(p0, '0');
        SetSquare(p1, '1');
    }

    template<int M, int N>
    char GridBoard<M,N>::GetSquareValue(Position pos) const{
        return squares_[pos.Y()*N + pos.X()];
    }

    template<int M, int N>
    void GridBoard<M,N>::SetSquare(Position pos, char value){
        squares_[pos.Y()*N + pos.X()] = value;
    }

}

