#ifndef STATUS_H
#define STATUS_H

#include <array>
#include <algorithm>
#include <ostream>

namespace base {

    template <int N> class Status;

    template<int N>
    bool operator==(const Status<N>& lhs, const Status<N>& rhs);
    template<int N>
    bool operator!=(const Status<N>& lhs, const Status<N>& rhs);
    template<int N>
    std::ostream& operator<<(std::ostream& out, const Status<N> status);

    template <int N>
    class Status{
    public:
        Status();
        Status(std::string init);
        void SetElement(int index, char value);
        char GetElement(int index) const;

        friend bool operator==<N>(const Status<N>& lhs, const Status<N>& rhs);
        friend bool operator!=<N>(const Status<N>& lhs, const Status<N>& rhs);
        friend std::ostream& operator<< <N>(std::ostream& out, const Status<N> status);
    private:
        std::array<char, N> status_;
    };

    template<int N>
    bool operator==(const Status<N>& lhs, const Status<N>& rhs){
        return std::equal(lhs.status_.begin(), lhs.status_.end(), rhs.status_.begin());
    }

    template<int N>
    bool operator!=(const Status<N>& lhs, const Status<N>& rhs){
        return !(lhs==rhs);
    }

    template<int N>
    inline std::ostream& operator<<(std::ostream& out, const Status<N> status){
        for (auto& el: status.status_) {
            out << el;
        }
        return out;
    }


    template <int N>
    Status<N>::Status(){
        status_.fill('.');
    }

    template <int N>
    Status<N>::Status(std::string init){
        for(int i = 0; i < N; ++i){
            status_[i] = init[i];
        }
    }

    template <int N>
    void Status<N>::SetElement(int index, char value){
        status_[index] = value;
    }

    template <int N>
    char Status<N>::GetElement(int index) const{
        return status_[index];
    }
}

#endif // STATUS_H
