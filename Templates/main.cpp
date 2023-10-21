#include <iostream>
#include "template.h"

int main() {
    std::cout << "FiFo Fubar" << std::endl;

    use_fifo();

    //Default value for the template <typename T = float>
    Fifo<> f;
    f.put(5);
    //String fifo
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

    std::cout << mult<int>(1,4) << std::endl;
    std::cout << mult<>(6.5,4.5) << std::endl;

    //Weiter mit template merhoden 2. video 14 min

    return 0;   
}