/*Shows how to use an Own Type
Unary arithmetic operators
*/

#include <iostream>
#include "vec2.h"

//Creating own Typ
Vec2::Vec2(float x, float y)
    : x_(x), y_(y)
    {}


void Vec2::set_x(float x) 
{
    x_ = x;
}
void Vec2::set_y(float y) 
{
    y_ = y;
}

int main() {
    Vec2 a(2,2);
    //Copy 
    Vec2 b = a;
    //Manipulating B
    b.set_x(3);
    //Vec2 c();

    //Auto typ with unary operator  test
    auto c = -b;

    Vec2 d = (a+c)*3;

    std::cout << a.x() << " " << a.y() << std::endl;
    std::cout << b.x() << " " << b.y() << std::endl;

    std::cout << c.x() << " " << c.y() << std::endl;
    std::cout << d.x() << " " << d.y() << std::endl;
    return 0;   
}