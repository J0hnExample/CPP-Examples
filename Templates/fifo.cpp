//Test Template
#include <iostream>
#include <array>
#include <string>
#include <concepts>

//This part creats no code
//Default value for the template <typename T = float>
//Setting a default parameter N = 100
//Set a second parameter N = 100 while instantiating
template<typename T = float, int N = 100> 

class Fifo{
    //array with the size N
    std::array<T, N> data_;
    size_t begin_=0, ende_=0;
public:
    void put(T value){
        data_[ende_] = value;
        if(++ende_ == N) ende_=0;
    }
    T get(){
        auto result=data_[begin_];
        if(++begin_ == N) begin_=0;
        return result;
    }
};
//template<auto T, int N = 100>
class Fifo{
    //array with the size N
    std::array<T, N> data_;
    size_t begin_=0, ende_=0;
public:
    void put(T value){
        data_[ende_] = value;
        if(++ende_ == N) ende_=0;
    }
    T get(){
        auto result=data_[begin_];
        if(++begin_ == N) begin_=0;
        return result;
    }
};
//this part creats code into the template

void use_fifo(){
    //Creating instances of the template class
    //for float
    Fifo<float> ff;
    //for string
    //std::string is explecitly to use standard libary string type from std namespace
    Fifo<std::string> sf;
    //putting values into the fifos
    ff.put(5.3);
    sf.put("Hello");
    std::cout << ff.get() << std::endl;
    std::cout << sf.get() << std::endl;
}