#ifndef CONNECTION_H
#define CONNECTION_H

#include "utility.h"
#include "status.h"

namespace base{

    template<int STATUS_N>
    class Connection{
    public:
        void SendStatus(Status<STATUS_N> new_status);
        Status<STATUS_N> ReceiveStatus();

        bool SendAction(Action action);
        bool ReceiveAction(Action& action);
    private:
        Status<STATUS_N> status_;

        Action action_;
    };

    template<int STATUS_N>
    void Connection<STATUS_N>::SendStatus(Status<STATUS_N> new_status){
        status_ = new_status;
    }

    template<int STATUS_N>
    Status<STATUS_N> Connection<STATUS_N>::ReceiveStatus(){
        return status_;
    }

    template<int STATUS_N>
    bool Connection<STATUS_N>::SendAction(Action action){
        action_ = action;
        return true;
    }

    template<int STATUS_N>
    bool Connection<STATUS_N>::ReceiveAction(Action &action){
        action = action_;
        return true;
    }
}

#endif // CONNECTION_H
