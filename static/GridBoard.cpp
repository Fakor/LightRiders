#include "GridBoard.h"

namespace base {
    GridBoard::GridBoard(uint16_t width, uint16_t height, Position p0, Position p1)
		: width_{ width }, height_{height}
	{
        for(uint16_t y = 0; y < height; ++y){
            for(uint16_t x = 0; x < width_; ++x){
                squares_.emplace_back('.');
            }
        }

        SetSquare(p0, '0');
        SetSquare(p1, '1');
	}


	GridBoard::~GridBoard()
	{
	}

    char GridBoard::GetSquareValue(Position pos) const{
        return squares_[pos.Y()*width_ + pos.X()];
    }

    void GridBoard::SetSquare(Position pos, char value){
        squares_[pos.Y()*width_ + pos.X()] = value;
    }

}
