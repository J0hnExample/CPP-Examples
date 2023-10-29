#include <iostream>
#include <cassert>
#include <typeinfo>

using namespace std;

#include "vec.h"
using namespace my;

void test_Vec() {

#ifndef NDEBUG
    cout << "======================" << endl;
    cout << "     Testing Vec    " << endl;
    cout << "======================" << endl;

    {
        // do not tolerate any memory overhead
        cout << "  sizeof(Vec) == 3 bytes: ";
        assert( sizeof(Vec) == 3*sizeof(float) );
        cout << "passed." << endl;
    }

    {
        cout << "  constructor & index operator: ";
        Vec a;
        assert( a[0] == 0 && a[1] == 0 && a[2] == 0 );
        Vec b(1, 2, 3);
        assert( b[0] == 1 && b[1] == 2 && b[2] == 3 );
        cout << "passed." << endl;
    }

    {
        cout << "  read-only access to const object: ";
        const Vec a(1,2,3);
        // the next line will throw a compiler error if there is no proper "operator[] const"
        assert( a[1] == 2 );
        cout << "passed." << endl;
    }

    {
        cout << "  write access to a non-const object: ";
        Vec a(1,2,3);
        a[1] = 4;
        assert( a[0] == 1 && a[1] == 4 && a[2] == 3 );
        cout << "passed." << endl;
    }

    {
        cout << "  comparison: ";        
        Vec a(1,2,3), b(1,2,3), c(1,2,9), d(4,5,6);
        assert( a == b );
        assert( a == a );
        assert( a != c );
        assert( b != d );
        assert( !(a != b) );
        cout << "passed." << endl;
    }
    
    {
        // should work out of the box when using std container (!)
        cout << "  assignment: "; 
        Vec a(1,2,3);
        cout << a[0] << " "; // to make sure these values are not optimized away! 
        a = Vec(4,5,6);
        assert( a[0] == 4 && a[1] == 5 && a[2] == 6 );
        cout << "passed." << endl;
    }
    
    {
        cout << "  addition: ";
        Vec a(1,2,3), b(4,5,6);
        a += b;
        assert( a == Vec(5,7,9) );
        auto c = a + Vec(1,1,1);
        assert( c == Vec(6,8,10) );
        Vec one(1,1,1), four(4,4,4);
        one += one+one+one;
        assert( one == four);
        Vec x(0,0,0), y(1,1,1), z(2,2,2);
        x += y += z;
        assert( y == Vec(3,3,3) );
        assert( x == y );
        cout << "passed." << endl;
    }
    
    {
        cout << "  unary minus: ";
        Vec a(1,2,3);
        assert( -a == Vec(-1,-2,-3) );
        cout << "passed." << endl;
    }
    
    {
        cout << "  dot product: ";
        Vec a(1,2,3);
        assert(( dot(a,a) == 1*1+2*2+3*3 ));
        cout << "passed." << endl;
    }

    {
        // these tests will not compile if you forgot to declare 
        // some methods const
        cout << "  constness: ";
        const Vec a(1,2,3);
        assert( a[1] == 2 );
        assert( a == a );
        assert( ! (a != a) );
        assert( a+a == Vec(2,4,6) );
        assert( -a == Vec(-1,-2,-3) );
        assert(( dot(a,a) == 1*1+2*2+3*3 ));
        cout << "passed." << endl;
    }

    cout << "all Vec tests passed." << endl << endl;   

#endif // not NDEBUG

}
