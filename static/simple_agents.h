#ifndef SIMPLE_AGENTS_H
#define SIMPLE_AGENTS_H

#include "utility.h"
#include "agent.h"
#include "basic_help.h"

namespace agents{

    template <int M, int N>
    class SameCommandAgent: public base::Agent<M,N>{
    public:
        SameCommandAgent(base::Action action): action_{action} {}
        void ChooseAction() override {this->SetAction(action_);}
    private:
        base::Action action_;
    };

    template <int M, int N>
    class SafeClockwiseBias: public base::Agent<M,N>{
    public:
        SafeClockwiseBias(base::Action bias): bias_{bias} {}
        void ChooseAction() override;
    private:
        base::Action bias_;
    };

    template <int M, int N>
    void SafeClockwiseBias<M,N>::ChooseAction(){
        base::Action candidate = bias_;
        for (int i = 0; i < 4; ++i) {
            base::Direction dir_candidate = base::DirectionFromAction(candidate, base::Direction::UP);
            if(help::DirectionSafe(this->CurrentStatus(), this->GetPosition(), dir_candidate)){
                this->SetAction(candidate);
                return;
            }
            candidate = help::NextActionClockwise(candidate);
        }
    }

    template <int M, int N>
    class RandomSafeAgent: public base::Agent<M,N>{
    public:
        RandomSafeAgent(unsigned int seed): gen_{seed} {}
        void ChooseAction() override;
    private:
        help::RandomSafeActionGenerator<M,N> gen_;
    };

    template <int M, int N>
    void RandomSafeAgent<M,N>::ChooseAction(){
        this->SetAction(gen_.GenerateAction(this->CurrentStatus(), this->GetPosition()));
    }

}

#endif // SIMPLE_AGENTS_H
