#include <iostream>
#include "template.h"

int main() {
    std::cout << "FiFo Fubar" << std::endl;

    use_fifo();

    Fifo<float> f;
    f.put(5);
    Fifo<std::string> s;
    s.put("Hello");
    s.put("again");
    s.put("who");
    s.put("are");
    s.put("you");

    std::cout << f.get() << std::endl;
    std::cout << s.get() << std::endl;
    std::cout << s.get() << std::endl;
    std::cout << s.get() << std::endl;
    std::cout << s.get() << std::endl;
    std::cout << s.get() << std::endl;
    return 0;   
}