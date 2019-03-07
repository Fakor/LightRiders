#ifndef CONNECTION_H
#define CONNECTION_H

#include <sstream>

#include "utility.h"

namespace base{

    class Connection{
    public:
        bool SendStatus(const char* new_status);
        bool ReceiveStatus(char *new_status);

        bool SendAction(Action action);
        bool ReceiveAction(Action& action);
    private:
        std::stringstream status_;
        std::stringstream actions_;

        Action action_;
    };

    bool Connection::SendStatus(const char* new_status){
        status_ << new_status;
        return true;
    }

    bool Connection::ReceiveStatus(char *new_status){
        status_ >> new_status;
        return true;
    }

    bool Connection::SendAction(Action action){
        action_ = action;
        return true;
    }

    bool Connection::ReceiveAction(Action &action){
        action = action_;
        return true;
    }
}

#endif // CONNECTION_H
