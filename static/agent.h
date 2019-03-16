#ifndef AGENT_H
#define AGENT_H

#include <sstream>
#include <thread>

#include "utility.h"
#include "status.h"
#include "connection.h"

namespace  base {

    template<int M, int N>
    class Agent{
    public:
        Agent() {}

        virtual void ChooseAction() {}

        void SetAction(Action action) {connection_->SendAction(action);}

        void Connect(Connection<M,N>* connection) {connection_ = connection;}

        Position GetPosition() const {return connection_->GetPosition();}
        Status<M,N> CurrentStatus() const {return connection_->ReceiveStatus();}
    private:
        Connection<M,N>* connection_;
    };

}



#endif // AGENT_H
