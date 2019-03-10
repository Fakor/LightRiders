#ifndef AGENT_H
#define AGENT_H

#include <sstream>
#include <thread>

#include "utility.h"
#include "status.h"
#include "connection.h"

namespace  base {

    template<int N>
    class Agent{
    public:
        Agent() {}

        void SetAction(Action action) {connection_->SendAction(action);}

        void Connect(Connection<N>* connection) {connection_ = connection;}

        Status<N> CurrentStatus() const {return connection_->ReceiveStatus();}
    private:
        Connection<N>* connection_;
    };

}



#endif // AGENT_H
