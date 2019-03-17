#ifndef UTILITY_H
#define UTILITY_H

#include <cstdint>
#include <string.h>
#include <stdexcept>
#include <ostream>

namespace base {

    class Position
    {
    public:
        Position(int16_t x, int16_t y): x_{x}, y_{y} {}

        int16_t X() const {return x_;}
        int16_t Y() const {return y_;}
    private:
        int16_t x_;
        int16_t y_;
    };

    bool operator==(const Position& lhs, const Position& rhs);
    bool operator!=(const Position& lhs, const Position& rhs);
    std::ostream& operator<<(std::ostream& out, const Position& position);


    enum class Action {
        UP,
        DOWN,
        RIGHT,
        LEFT,
        PASS
    };

    enum class Direction{
        UP,
        DOWN,
        RIGHT,
        LEFT
    };

    struct AgentState{
        Position pos{0,0};
        Direction dir{Direction::UP};
        bool alive{true};
        char name{'0'};
        bool first_move{true};
    };

    Position PositionInDirection(base::Position position, base::Direction direction);
    Direction GetOpositeDirection(Direction dir);
    Direction DirectionFromAction(Action action, Direction default_dir);
    void SetDirectionFromAction(Action action, AgentState& state);
    Position NewPositionFromAction(AgentState& state, Action action);
    char* ActionToString(const Action& action, char *buf);
    Action StringToAction(char *buf);

}


#endif // UTILITY_H
