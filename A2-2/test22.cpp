// Testtreiber für Aufgabe 2.2: my::vector


#include <iostream>
#include <cassert>
#include "my_vector.h"
#include "payload.h"
#include "trackmymoves.h"


int test_22()
{

    int testCount = 0;
    
    using my::vector;
    using std::cout;
    using std::endl;


    {   
        testCount++;
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
        testCount++;
        cout << "Copy Constructor/size test ... " << endl;
        vector<Payload> v2(3, Payload(-1,-1,-1));
        assert(v2.size() == 3);
        assert(Payload::count() == v2.size());
        //Copy the vector v2 to v3  

        vector<Payload> v3(v2);
        // Check the addresses of v2 and v3
        cout << "Copy Address of v2: &" << &v2 << " cD:" << v2.currentdataAdress() << endl;
        cout << "Copy Address of v3: &" << &v3 << " cD:" << v3.currentdataAdress() << endl;
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
        cout << "Copy Address end of Test of v2: &" << &v2 << " cD:" << v2.currentdataAdress() << endl;
        cout << "Copy Address end of Test of v3: &" << &v3 << " cD:" << v3.currentdataAdress() << endl;
        cout << "Copy Tests done!" << endl;
    }
    //Move Constructor Move the vector v3 to v4
    {   
        testCount++;
        cout << "Move Constructor/size test ... " << endl;
        vector<Payload> v3(3, Payload(-1,-1,-1));
        assert(v3.size() == 3);
        assert(Payload::count() == v3.size());
        //save payload count
        int countPayload = Payload::count();
        //Move the vector v3 to v4 and check the v3 adress
        cout << "Move v3 Address: &" << &v3 << " cD:" << v3.currentdataAdress() << endl;
        vector<Payload> v4(std::move(v3));
        cout << "Move v4 Address: &" << &v4 << " cD:" << v4.currentdataAdress() << endl;
        assert(v3.size() == 0); //rip v3
        assert(v4.size() == 3);
        cout << "Move v3 Address after move: &" << &v3 << " cD:" << v3.currentdataAdress() << endl;
        cout << "Move v4 Address after move: &" << &v4 << " cD:" << v4.currentdataAdress() << endl;
        //Check that Payload is not changed
        assert(Payload::count() == countPayload);
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
        //Adresses
        cout << "Assignment v5 Address: &" << &v5 << " cD:" << v5.currentdataAdress() << endl;
        cout << "Assignment v6 Address: &" << &v6 << " cD:" << v6.currentdataAdress() << endl;
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
    //Reserve Tests
    {   
        testCount++;
        cout << "Reserve Tests ... " << endl;
        vector<Payload> v7(3, Payload(-1,-1,-1));
        assert(v7.size() == 3);
        assert(Payload::count() == v7.size());
        cout << "Reserve Adress before reserve v7: &" << &v7 << " cD:" << v7.currentdataAdress() << endl;
        //save the adress to a vector
        vector<Payload> v8 = v7;
        
        //v7.reserve(100);
        cout << "Reserve Adress after reserve v7: &" << &v7 << " cD:" << v7.currentdataAdress() << endl;
        cout << "Reserve Tests done!" << endl;
    }

    //Shrinke to fit test
    {   
        testCount++;
        cout << "Shrinke to fit Tests ... " << endl;
        vector<Payload> v9(10);
        cout << "Shrinke to fit Actual adress v9: &" << &v9 << " cD:" << v9.currentdataAdress() << endl;
        cout << "Shrinke to fit Before Shrinke to fit Size: " << v9.size() << " ";
        cout << "Before Shrinke to  fit Capacity: " << v9.capacity() << endl;
        v9.pop_back();
        v9.shrink_to_fit();
        cout << "Shrinke to fit After Shrinke to fit Size:  " << v9.size() << " ";
        cout << "After Shrinke to fit Capacity:  " << v9.capacity() << endl;
        cout << "Shrinke to fit New adress: &" << &v9 << " cD:" << v9.currentdataAdress() << endl;
        cout << "Shrinke to fit Tests done!" << endl;
    }

    //Test Clear
    {   
        testCount++;
        cout << "Clear Tests ... " << endl;
        vector<Payload> v10(10);
        cout << "Clear Actual adress v10: &" << &v10 << " cD:" << v10.currentdataAdress() << endl;
        cout << "Clear Before Clear Size: " << v10.size() << " ";
        cout << "Before Clear Capacity: " << v10.capacity() << endl;
        v10.clear();
        cout << "Clear After Clear Size: " << v10.size() << " ";
        cout << "After Clear Capacity: " << v10.capacity() << endl;
        cout << "Clear New adress: &" << &v10 << " cD:" << v10.currentdataAdress() << endl;
        assert(v10.size() == 0);
        assert(v10.capacity() >= 0);
        cout << "Clear Tests done!" << endl;
    }

    {   
        testCount++;
        //Push_back test
        cout << "Push_back Tests ... " << endl;
        vector<Payload> v9(3, Payload(-1,-1,-1));
        //Push_back and Check for Payload count increased by 1
        cout << "Push_back before push_back Adress v9: &" << &v9 << " cD:" << v9.currentdataAdress() << endl;
        cout << "Push_back before push_back Size: " << v9.size() << " ";
        cout << "Push_back before push_back Capacity: " << v9.capacity() << endl;
        assert(v9.size() == 3);
        assert(Payload::count() == v9.size());
        v9.push_back(Payload(9,9,9));
        assert(Payload::count() == 4);
        cout << "Push_back Adress after push_back v9: &" << &v9 << " cD:" << v9.currentdataAdress() << endl;
        cout << "Push_back after push_back Size: " << v9.size() << " ";
        cout << "Push_back after push_back Capacity: " << v9.capacity() << endl;
        
        cout << "Push_back Tests done!" << endl;
        
    }
    {
        testCount++;
        //Pop_back test
        cout << "Pop_back Tests ... " << endl;
        vector<Payload> v9(3, Payload(-1,-1,-1));
        cout << "Pop_back before pop_back Adress v9: &" << &v9 << " cD:" << v9.currentdataAdress() << endl;
        cout << "Pop_back before pop_back Size: " << v9.size() << " ";
        cout << "Pop_back before pop_back Capacity: " << v9.capacity() << endl;
        assert(v9.size() == 3);
        assert(Payload::count() == v9.size());
        v9.pop_back();
        assert(Payload::count() == 2);
        cout << "Pop_back Adress after pop_back v9: &" << &v9 << " cD:" << v9.currentdataAdress() << endl;
        cout << "Pop_back after pop_back Size: " << v9.size() << " ";
        cout << "Pop_back after pop_back Capacity: " << v9.capacity() << endl;

        cout << "Pop_back Tests done!" << endl;
    }
    return testCount;

}