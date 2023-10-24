#include <iostream>
#include <array>
#include <string>

using namespace std;

template<typename T>
void print_type_info(T value)
{

}

template<>
void print_type_info<float>(float value)
{
    cout << "its a float" << endl;
}

template<>
void print_type_info<string>(string value)
{
    cout << "its a string" << endl;
}

template<>
void print_type_info<int>(int value)
{
    cout << "its a int" << endl;
}