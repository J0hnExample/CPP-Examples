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
      
    my::vector<Payload> v;
    v.reserve(100);

    // Die Größe sollte nach dem Reservieren 0 sein
    assert(v.size() == 0);
    }
    {
        cout << "Construction/Destruction, size() ... ";
        vector<Payload> v0;
        assert(v0.size() == 0);
        assert(Payload::count() == 0);

        {
            // Are the elements created?
            vector<Payload> v1(3, Payload(-1, -1, -1));
            assert(v1.size() == 3);
            assert(Payload::count() == v1.size());
        }

        // Are the elements destroyed?
        assert(Payload::count() == 0);
        cout << "done." << endl;
    }
    {
        cout << "pop_back() with empty vector... ";
        vector<double> v;


        double lastElement = v.pop_back();
        assert(v.size() == 0);
        assert(lastElement == double()); // Default-constructed double
        cout << "done." << endl;
    }

/*     {
        cout << "multiple pop_back() calls... ";
        vector<std::string> v;
        v.push_back("one");
        v.push_back("two");
        v.push_back("three");

        std::string lastElement1 = v.pop_back();
        std::string lastElement2 = v.pop_back();
        std::string lastElement3 = v.pop_back();

        // Vector should be empty after multiple pop_back calls
        assert(v.size() == 0);

        // Check if the popped elements are correct
        assert(lastElement1 == "three");
        assert(lastElement2 == "two");
        assert(lastElement3 == "one");

        cout << "done." << endl;
    } */
}