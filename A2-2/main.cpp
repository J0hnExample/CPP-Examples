// Testtreiber für Aufgabe 2: my::vector 
// WS 2022 Edition
// Autor: Hartmut Schirmacher
//import std;

#include <iostream>
#include "my_vector.h"
#include "payload.h"


using namespace my;

void test_21();
void test_22();

int main()
{
    using std::cout;
    using std::endl;


    cout << "Starting tests (2.1) --------------------" << endl;

    test_21();


    std::cout << "\nStarting tests (2.2) --------------------" << endl;
    
    test_22();


    std::cout << "End of tests ----------------------------" << endl;

    return 0;
}
