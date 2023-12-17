// Testtreiber für Aufgabe 2.2: my::vector


#include <iostream>
#include <cassert>
#include "my_vector.h"
#include "payload.h"
#include "trackmymoves.h"


void test_22()
{


    
    using my::vector;
    using std::cout;
    using std::endl;
;

    {
        cout << "construction/destruction, size() ... \n";
        //Creating default vector
        vector<Payload> v0;
        assert(v0.size() == 0);
        assert(Payload::count() == 0);
        //creating vector with 3 elements
        vector<Payload> v1(3, Payload(-1,-1,-1));
        assert(v1.size() == 3);
        assert(Payload::count() == v1.size());
        cout << "Default Constructor Done ..." << endl;
        
    }
    //Copy Constructor test
    {
        cout << "Copy Constructor/size test ... " << endl;
        vector<Payload> v2(3, Payload(-1,-1,-1));
        assert(v2.size() == 3);
        assert(Payload::count() == v2.size());
        //Copy the vector v2 to v3  
        vector<Payload> v3(v2);
        cout << "Copy test ... " << endl;
        assert(v3.size() == 3);
        assert(v2.size() == v3.size());
        //Check for Values
        assert(v3[0] == v2[0]);
        assert(v3[1] == v2[1]);
        assert(v3[2] == v2[2]);
        cout << "Copy Value test ... " << endl;
        //set different values to v3
        v3[0] = Payload(0,0,0);
        v3[1] = Payload(1,1,1);
        v3[2] = Payload(2,2,2);
        //Check if v3 values are different from v2
        assert(v3[0] != v2[0]);
        assert(v3[1] != v2[1]);
        assert(v3[2] != v2[2]);
        cout << "Copy Tests done!" << endl;
    }
    //Move Constructor Move the vector v3 to v4
    {
        cout << "Move Constructor/size test ... " << endl;
        vector<Payload> v3(3, Payload(-1,-1,-1));
        assert(v3.size() == 3);
        assert(Payload::count() == v3.size());
        //Move the vector v3 to v4
        vector<Payload> v4(std::move(v3));
        assert(v3.size() == 0); //rip v3
        assert(v4.size() == 3);
        cout << "Move Destructor/Size test ... " << endl;
        //check if the v4 value as the same in payload
        assert(v4[0] == Payload(-1,-1,-1));
        assert(v4[1] == Payload(-1,-1,-1));
        assert(v4[2] == Payload(-1,-1,-1));
        cout << "Move Value test ... "  << endl;
        cout << "Move Tests done!" << endl;
    }
    //Assignment Operator test
    {
        cout << "Assignment Operator/size test ... " << endl;
        vector<Payload> v5(3, Payload(-1,-1,-1));
        assert(v5.size() == 3);
        assert(Payload::count() == v5.size());
        //Create v6 
        vector<Payload> v6(3, Payload(2,2,2));
        //Assign v5 to v6
        v6 = v5;
        //check if v6 values are the same as v5
        assert(v6[0] == v5[0]);
        assert(v6[1] == v5[1]);
        assert(v6[2] == v5[2]);
        assert(v6.size() == v5.size());
        cout << "Assignment Operator/size test ... " << endl;
        // Change Values in v6
        v6[0] = Payload(5,5,5);
        v6[1] = Payload(6,6,6);
        v6[2] = Payload(7,7,7);
        cout << "Assignment Value test ... " << endl;
        // Check if v6 not changeing the v5
        assert(v6[0] != v5[0]);
        assert(v6[1] != v5[1]);
        assert(v6[2] != v5[2]);
        cout << "Assignment Value change test ... " << endl;
        cout << "Assignment Tests done!" << endl;
    }


}