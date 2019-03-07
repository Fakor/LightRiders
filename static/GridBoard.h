#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <sstream>

#include "agent.h"
#include "utility.h"
#include "connection.h"

namespace base {

    template <int M, int N>
	class GridBoard
	{
	public:

        static const uint16_t BOARD_SIZE = N*M;

        GridBoard(Connection &c0, Connection &c1);
        virtual ~GridBoard() = default;

        void SetStartPosition(Position pos0, Position pos1);

        char GetSquareValue(Position pos) const;

        const char* GetStatus() const;
        void UpdateStatus();
        bool PerformTurn();

        bool WithinBoarders(Position pos) const;
        bool BlockedSquare(Position pos) const;
        void AgentsSameSquare();

        bool Agent0Alive() const {return a0_state_.alive;}
        bool Agent1Alive() const {return a1_state_.alive;}
	private:
        char status_[BOARD_SIZE+1];

        Connection& c0_;
        Connection& c1_;

        AgentState a0_state_;
        AgentState a1_state_;

        void SetSquare(Position pos, char value);
        void UpdateAgentState(AgentState& state, Connection& connection);
	};


    template<int M, int N>
    GridBoard<M,N>::GridBoard(Connection &c0, Connection &c1)
        : c0_{c0}, c1_{c1}
    {
        a0_state_.name = '0';
        a1_state_.name = '1';

        memset(status_, '.', BOARD_SIZE);
        status_[BOARD_SIZE] = '\0';
    }

    template<int M, int N>
    void GridBoard<M,N>::SetStartPosition(Position pos0, Position pos1){
        a0_state_.pos = pos0;
        a0_state_.alive = true;

        a1_state_.pos = pos1;
        a1_state_.alive = true;

        SetSquare(a0_state_.pos, a0_state_.name);
        SetSquare(a1_state_.pos, a1_state_.name);
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
    void GridBoard<M,N>::UpdateStatus(){
        c0_.SendStatus(status_);
        c1_.SendStatus(status_);
    }

    template<int M, int N>
    bool GridBoard<M,N>::PerformTurn(){
        UpdateAgentState(a0_state_, c0_);
        UpdateAgentState(a1_state_, c1_);

        AgentsSameSquare();

        return !a0_state_.alive || !a1_state_.alive;
    }

    template<int M, int N>
    bool GridBoard<M,N>::WithinBoarders(Position pos) const{
        return pos.X() >= 0 && pos.X() < N && pos.Y() >= 0 && pos.Y() < M;
    }

    template<int M, int N>
    bool GridBoard<M,N>::BlockedSquare(Position pos) const{
        return GetSquareValue(pos) != '.';
    }

    template<int M, int N>
    void GridBoard<M,N>::AgentsSameSquare(){
        if(a0_state_.pos == a1_state_.pos){
            a0_state_.alive = false;
            a1_state_.alive = false;
        }
    }

    template<int M, int N>
    void GridBoard<M,N>::UpdateAgentState(AgentState& state, Connection& connection){
        Action action;
        connection.ReceiveAction(action);
        SetSquare(state.pos, 'x');
        Position new_square = NewPositionFromAction(state, action);
        if(!WithinBoarders(new_square)){
            state.alive = false;
            return;
        } else if(BlockedSquare(new_square)){
            state.alive = false;
        }
        state.pos = new_square;
        SetSquare(new_square, state.name);
    }

}

