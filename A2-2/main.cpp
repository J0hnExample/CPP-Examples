// Testtreiber für Aufgabe 2: my::vector 
// WS 2022 Edition
// Autor: Hartmut Schirmacher
//import std;

#include <iostream>
#include "my_vector.h"
#include "payload.h"


using namespace my;

int test_21();
int test_22();

int main()
{
    using std::cout;
    using std::endl;
    int testCount = 0;
    int testResults = 0;
    cout << "Starting tests (2.1) --------------------" << endl;

    testCount += test_21();
    testResults++;

    std::cout << "\nStarting tests (2.2) --------------------" << endl;
    
    testCount += test_22();
    testResults++;

    std::cout << "End of tests ----------------------------" << endl;
    std::cout << "  " << testResults << " Test Driver succeeded." << endl;
    std::cout << "Total tests Done: " << testCount << endl;
    
    return 0;
}
