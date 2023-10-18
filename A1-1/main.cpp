#include <iostream>
#include "test11.h"
#include "vec3f.cpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    //Test vector a
    Vec3f a;
    //Test vector b
    const Vec3f b(1,2,3);
    
    size_t size = a.getSize();

    a[1] = 4;

    std::cout << "Array Size: "<< size  << std::endl;
    std::cout << "default_werte a "<< a[1]  << std::endl;
    std::cout << "default_werte const "<< b[0]  << std::endl;
    return 0;   
}