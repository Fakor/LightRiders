#ifndef STATUS_H
#define STATUS_H

#include <array>
#include <algorithm>
#include <ostream>

#include "utility.h"

namespace base {

    template <int M, int N> class Status;

    template<int M, int N>
    bool operator==(const Status<M,N>& lhs, const Status<M,N>& rhs);
    template<int M, int N>
    bool operator!=(const Status<M,N>& lhs, const Status<M,N>& rhs);
    template<int M, int N>
    std::ostream& operator<<(std::ostream& out, const Status<M,N> status);

    template <int M, int N>
    class Status{
    public:
        static const uint16_t STATUS_SIZE=N*M;

        Status();
        Status(std::string init);
        void SetElement(int index, char value);
        char GetElement(int index) const;

        Position GetPosition(char agent_name) const;

        friend bool operator==<M,N>(const Status<M,N>& lhs, const Status<M,N>& rhs);
        friend bool operator!=<M,N>(const Status<M,N>& lhs, const Status<M,N>& rhs);
        friend std::ostream& operator<< <M,N>(std::ostream& out, const Status<M,N> status);
    private:
        std::array<char, STATUS_SIZE> status_;
    };

    template<int M, int N>
    bool operator==(const Status<M,N>& lhs, const Status<M,N>& rhs){
        return std::equal(lhs.status_.begin(), lhs.status_.end(), rhs.status_.begin());
    }

    template<int M, int N>
    bool operator!=(const Status<M,N>& lhs, const Status<M,N>& rhs){
        return !(lhs==rhs);
    }

    template<int M, int N>
    inline std::ostream& operator<<(std::ostream& out, const Status<M,N> status){
        for (auto& el: status.status_) {
            out << el;
        }
        return out;
    }

    template <int M, int N>
    Status<M,N>::Status(){
        status_.fill('.');
    }

    template <int M, int N>
    Status<M,N>::Status(std::string init){
        for(int i = 0; i < STATUS_SIZE; ++i){
            status_[i] = init[i];
        }
    }

    template <int M, int N>
    void Status<M,N>::SetElement(int index, char value){
        status_[index] = value;
    }

    template <int M, int N>
    char Status<M,N>::GetElement(int index) const{
        return status_[index];
    }

    template <int M, int N>
    Position Status<M,N>::GetPosition(char agent_name) const{
        int i = 0;
        for (auto value: status_) {
            if(value == agent_name){
                int16_t x = i%N;
                int16_t y = i/M;
                return Position{x,y};
            }
            ++i;
        }
        std::string error_message = "[" + std::to_string(agent_name) + "] not found on map";
        throw std::invalid_argument(error_message);
    }

}

#endif // STATUS_H
