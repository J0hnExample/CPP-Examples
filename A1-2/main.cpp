#include <iostream>
#include "test11.h"
#include "vec.h"


int main()
{
    std::cout << "Hello, World!" << std::endl;

    my::Vec<float, 3> vec(1.0f, 2.0f, 3.0f);

    my::Vec<int,5> vec2(1, 2, 3,4,5);
    std::cout << vec[0] << std::endl;
    std::cout << vec2[0] << vec2[2] << std::endl;
    return 0;
}
    // free funktion dot() calculates the scalar product of two Vectors
    // Use: float s = dot(Vec3f a, Vec3f b);
 /*    float dot(const my::Vec3f &v1, const my::Vec3f &v2)
    {
        return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    } */