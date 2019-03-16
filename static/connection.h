#ifndef CONNECTION_H
#define CONNECTION_H

#include "utility.h"
#include "status.h"

namespace base{

    template<int M, int N>
    class Connection{
    public:
        Connection(char name, Status<M,N>* status): name_{name}, status_{status} {}

        Status<M,N> ReceiveStatus();

        bool SendAction(Action action);
        bool ReceiveAction(Action& action);

        Position GetPosition() const;
    private:
        char name_;
        Status<M,N>* status_;
        Action action_;
    };

    template<int M, int N>
    Status<M,N> Connection<M,N>::ReceiveStatus(){
        return *status_;
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

    template<int M, int N>
    Position Connection<M,N>::GetPosition() const{
        return status_->GetPosition(name_);
    }
}

#endif // CONNECTION_H
