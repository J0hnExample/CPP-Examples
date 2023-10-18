#include <iostream>
#include "test11.h"
#include "vec3f.h"


int main()
{
    std::cout << "Hello, World!" << std::endl;


    // Test vector a
    my::Vec3f a;
    my::Vec3f s;

    // Test vector b
    const my::Vec3f b(1, 2, 3);
    const my::Vec3f c(1, 2, 3);

    std::cout << "b == c is " << (b == c) << std::endl;

    my::Vec3f y = b - c;

    size_t size = a.getSize();

    a[1] = 4;

    std::cout << "Array Size: " << size << std::endl;
    std::cout << "default_werte a " << a[1] << std::endl;
    std::cout << "default_werte const " << b[0] << std::endl;
    return 0;
}
    // free funktion dot() calculates the scalar product of two Vectors
    // Use: float s = dot(Vec3f a, Vec3f b);
    float dot(const Vec3f &v1, const Vec3f &v2)
    {
        return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
    }