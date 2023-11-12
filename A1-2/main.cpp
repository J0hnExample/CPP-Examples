#include <iostream>

#include "testvec.h"

using namespace my;

int main()
{
    std::cout << "Generic Templat Tests\n\n" << std::endl;


    std::cout << "Float Tests\n" << std::endl;
    testVec<float, 3>();
    std::cout << "Int Tests\n" << std::endl;
    testVec<int, 4>();
    std::cout << "Long Tests\n" << std::endl;
    testVec<long, 5>();
    std::cout << "Double Tests\n" << std::endl;
    testVec<double, 4>();
    std::cout << "Short Tests\n" << std::endl;
    testVec<short, 1>();

    std::cout << "Tests finished\n" << std::endl;
    return 0;
}
