/*Shows how to use an Own Type
Unary arithmetic operators
try to modify Call By Value
*/

#include <iostream>
#include "vec2.h"
#include <assert.h>

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

//Shows the differenz in call by reference/Value
//Call By Value
//v is a copy of a
void try_to_modify(Vec2 v)
{
    //sets v.x to 3.14 
    v.set_x(3.14f);
}
//Call by reference
void try_to_modify_ref(Vec2& v)
{
    //sets v.x to 3.14 
    v.set_x(3.14f);
}
//Constant ref
void try_to_modify_const_ref(const Vec2& v)
{
    //sets v.x to 3.14 
   //Not allowed v.set_x(3.14f);
}
int main() {
    Vec2 a(2,2);
    //Copy 
    Vec2 b = a;
    //Try to Modify (no harm to a)
    try_to_modify_ref(a);
    //Testing assert
    assert(a.x() == 3.14f);
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