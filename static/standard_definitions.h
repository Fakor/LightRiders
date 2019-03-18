#ifndef STANDARD_DEFINITIONS_H
#define STANDARD_DEFINITIONS_H

#include "agent.h"
#include "simple_agents.h"
#include "GridBoard.h"

namespace standard {
    const int WIDTH = 16;
    const int HEIGHT = 16;

    using Agent_S = base::Agent<HEIGHT, WIDTH>;
    using SameCommandAgent_S = agents::SameCommandAgent<HEIGHT, WIDTH>;
    using GridBoard_S = base::GridBoard<HEIGHT, WIDTH>;
    using Status_S = base::Status<HEIGHT, WIDTH>;
}

#endif // STANDARD_DEFINITIONS_H
