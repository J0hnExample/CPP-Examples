// Testtreiber für Aufgabe 2.2: my::vector


#include <iostream>
#include <cassert>
#include "my_vector.h"
#include "payload.h"


void test_22()
{


    
    using my::vector;
    using std::cout;
    using std::endl;

    {

        //Creating default vector
        vector<Payload> v0;
        assert(v0.size() == 0);
        assert(Payload::count() == 0);
        //creating vector with 3 elements
        vector<Payload> v1(3, Payload(-1,-1,-1));
        assert(v1.size() == 3);
        assert(Payload::count() == v1.size());
        
    }
    //Copy Constructor test
    {
        cout << "Copy Constructor/size test ... ";
        vector<Payload> v2(3, Payload(-1,-1,-1));
        assert(v2.size() == 3);
        assert(Payload::count() == v2.size());
        //Copy the vector v2 to v3 
        vector<Payload> v3 = v2;
        cout << "Copy" << endl;
        assert(v3.size() == 3);
        assert(v2.size() == v3.size());
        //Check for Values
        assert(v3[0] == v2[0]);
        assert(v3[1] == v2[1]);
        assert(v3[2] == v2[2]);
        cout << "Value test ... ";
        cout << " done." << endl;
    }
    //Move Constructor Move the vector v3 to v4
    {
        cout << "Move Constructor/size test ... ";
        vector<Payload> v3(3, Payload(-1,-1,-1));
        assert(v3.size() == 3);
        assert(Payload::count() == v3.size());
        //Move the vector v3 to v4
        vector<Payload> v4(std::move(v3));
        assert(v3.size() == 0);
        cout << "Destructor test ... ";
        //check if the v4 value as the same in payload
        assert(v4[0] == Payload(-1,-1,-1));
        assert(v4[1] == Payload(-1,-1,-1));
        assert(v4[2] == Payload(-1,-1,-1));
        cout << "Value test ... ";
        cout << " done." << endl;
    }
}