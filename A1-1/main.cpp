#include <iostream>
#include "test11.h"
#include "vec3f.cpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Vec3f a;
    
    size_t size = a.getSize();

    auto f = a[1];

    std::cout << "Array Size: "<< size  << std::endl;
    return 0;   
}