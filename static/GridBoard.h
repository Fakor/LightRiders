#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "agent.h"
#include "utility.h"

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
        bool PerformTurn();

        bool WithinBoarders(Position pos) const;
        bool BlockedSquare(Position pos) const;
        void AgentsSameSquare();

        bool Agent0Alive() const {return a0_state_.alive;}
        bool Agent1Alive() const {return a1_state_.alive;}
	private:
        char status_[BOARD_SIZE+1];

        Agent<M,N>& a0_;
        Agent<M,N>& a1_;

        AgentState a0_state_;
        AgentState a1_state_;

        void SetSquare(Position pos, char value);
        void UpdateAgentState(AgentState& state, Agent<M,N>& agent);
	};


    template<int M, int N>
    GridBoard<M,N>::GridBoard(Agent<M,N> &a0, Agent<M,N> &a1)
        : a0_{a0}, a1_{a1}, a0_state_{a0.GetState()}, a1_state_{a1.GetState()}
    {
        memset(status_, '.', BOARD_SIZE);
        SetSquare(a0_state_.pos, a0_.GetName());
        SetSquare(a1_state_.pos, a1_.GetName());
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

    template<int M, int N>
    bool GridBoard<M,N>::PerformTurn(){
        UpdateAgentState(a0_state_, a0_);
        UpdateAgentState(a1_state_, a1_);

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
    void GridBoard<M,N>::UpdateAgentState(AgentState& state, Agent<M,N>& agent){
        if(agent.FirstMove()){
            state.dir = agent.GetDesiredDirection();
            agent.FirstMoveDone();
        } else if(GetOpositeDirection(state.dir) != agent.GetDesiredDirection()){
            state.dir = agent.GetDesiredDirection();
        }
        SetSquare(state.pos, 'x');
        Position new_square = NewPositionFromDirection(state.pos, state.dir);
        if(!WithinBoarders(new_square)){
            state.alive = false;
            return;
        } else if(BlockedSquare(new_square)){
            state.alive = false;
        }
        state.pos = new_square;
        SetSquare(new_square, agent.GetName());
    }

}

