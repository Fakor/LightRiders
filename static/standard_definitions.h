#ifndef STANDARD_DEFINITIONS_H
#define STANDARD_DEFINITIONS_H

#include "GridBoard.h"

namespace standard {
    const int WIDTH = 16;
    const int HEIGHT = 16;

    using GridBoard = base::GridBoard<HEIGHT, WIDTH>;
}

#endif // STANDARD_DEFINITIONS_H
