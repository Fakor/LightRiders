#ifndef SIMPLE_AGENTS_H
#define SIMPLE_AGENTS_H

#include "utility.h"
#include "agent.h"

namespace agents{

    template <int M, int N>
    class SameCommandAgent: public base::Agent<M,N>{
    public:
        SameCommandAgent(base::Action action): action_{action} {}
        void ChooseAction() override {this->SetAction(action_);}
    private:
        base::Action action_;
    };


}

#endif // SIMPLE_AGENTS_H
