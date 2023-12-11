// Testtreiber für Aufgabe 2: my::vector 
// WS 2022 Edition
// Autor: Hartmut Schirmacher

#include <iostream>
#include "my_vector.h"

using namespace std;
using namespace my;

void test_21();

int main()
{
    //my tests
    vector<double> v2(3, 3.14);
            //Print out some vectors

    cout << "Vector 3x 3.41 " << v2[0] << v2[1] << v2[2] << endl;



    cout << "Starting tests (2.1) --------------------" << endl;

    test_21();

#if 0
    cout << "Starting tests (2.2) --------------------" << endl;
    test_22();
#endif

    cout << "End of tests ----------------------------" << endl;

    return 0;
}
