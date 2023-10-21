//Test Template
#include <iostream>
#include <array>
#include <string>

template<typename T>
class Fifo{
    std::array<T, 100> data_;
    size_t begin_=0, ende_=0;
public:
    void put(T value){
        data_[ende_] = value;
        if(++ende_ == 100) ende_=0;
    }
    T get(){
        auto result=data_[begin_];
        if(++begin_ == 100) begin_=0;
        return result;
    }
};

void use_fifo(){
    Fifo<float> ff;
    //std::string is explecitly to use standard libary string type from std namespace
    Fifo<std::string> sf;
    ff.put(5.3);
    sf.put("Hello");
    std::cout << ff.get() << std::endl;
    std::cout << sf.get() << std::endl;
}