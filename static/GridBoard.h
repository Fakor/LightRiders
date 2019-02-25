#pragma once

#include <cstdint>
#include <vector>

#include "Position.h"

namespace base {

	class GridBoard
	{
	public:
        GridBoard(uint16_t width, uint16_t height, Position p0, Position p1);
		virtual ~GridBoard();

        char GetSquareValue(Position pos) const;
	private:
        uint16_t width_;
        uint16_t height_;

        std::vector<char> squares_;

        void SetSquare(Position pos, char value);
	};

}

