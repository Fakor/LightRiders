#ifndef CONNECTION_H
#define CONNECTION_H

#include "utility.h"
#include "status.h"

namespace base{

    template<int M, int N>
    class Connection{
    public:
        void SendStatus(Status<M,N> new_status);
        Status<M,N> ReceiveStatus();

        bool SendAction(Action action);
        bool ReceiveAction(Action& action);
    private:
        Status<M,N> status_;

        Action action_;
    };

    template<int M, int N>
    void Connection<M,N>::SendStatus(Status<M,N> new_status){
        status_ = new_status;
    }

    template<int M, int N>
    Status<M,N> Connection<M,N>::ReceiveStatus(){
        return status_;
    }

    template<int M, int N>
    bool Connection<M,N>::SendAction(Action action){
        action_ = action;
        return true;
    }

    template<int M, int N>
    bool Connection<M,N>::ReceiveAction(Action &action){
        action = action_;
        return true;
    }
}

#endif // CONNECTION_H
