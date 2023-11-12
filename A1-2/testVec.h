// testVec.h
#include <cassert>
#include "vec.h"
using namespace my;
using namespace std;

template <typename T, int N>
void testVec()
{
    // Erstellt einen Vektor vec
    Vec<T, N> vec;
    Vec<T, N> vec2 = vec;
    Vec<T, N> vec3 = vec + vec2;
    // Test auf Gleichheit und Ungleichheit

    /* assert(vec == vec2); // Überprüft, ob die beiden Vektoren gleich sind
    assert(!(vec != vec2)); // Überprüft, ob die beiden Vektoren ungleich sind */

    // Testkonstruktion und Zugriff auf Elemente

    for (int i = 0; i < N; i++)
    {
        vec[i] = static_cast<T>(i);          // Füllt den Vektor mit aufsteigenden Werten
        assert(vec[i] == static_cast<T>(i)); // Überprüft, ob die Werte korrekt gesetzt sind
    }

    {
        cout << "  constructor & index operator: ";
        Vec<T, N> a;
        for (int i = 0; i < N; ++i)
        {
            assert(a[i] == static_cast<T>(0));
        }
        // Initialize b with N values
        Vec<T, N> b;
        for (int i = 0; i < N; ++i)
        {
            b[i] = static_cast<T>(i + 1);
        }
        for (int i = 0; i < N; ++i)
        {
            assert(b[i] == static_cast<T>(i + 1));
        }

        cout << "passed." << endl;
    }
    {
        cout << "  read-only access to const object: ";
        const Vec<float, 3> a(1, 2, 3);
        // the next line will throw a compiler error if there is no proper "operator[] const"
        assert(a[1] == 2);
        cout << "passed." << endl;
    }
        {
        cout << " short read-only access to const object: ";
        const Vec<short, 3> a(1, 2, 3);
        // the next line will throw a compiler error if there is no proper "operator[] const"
        assert(a[1] == 2);
        cout << "passed." << endl;
    }
    {
        cout << "  write access to a non-const object: ";
        Vec<float, 3> a(1, 2, 3);
        a[1] = 4;
        assert(a[0] == 1 && a[1] == 4 && a[2] == 3);
        cout << "passed." << endl;
    }
    {
        cout << "  comparison: ";
        Vec<float, 4> a(1, 2, 3), b(1, 2, 3), c(1, 2, 9), d(4, 5, 6);
        assert(a == b);
        assert(a == a);
        assert(a != c);
        assert(b != d);
        assert(!(a != b));
        cout << "passed." << endl;
    }
        {
        cout << " long comparison: ";
        Vec<long, 4> a(1, 2, 3), b(1, 2, 3), c(1, 2, 9), d(4, 5, 6);
        assert(a == b);
        assert(a == a);
        assert(a != c);
        assert(b != d);
        assert(!(a != b));
        cout << "passed." << endl;
    }
    {
        // should work out of the box when using std container (!)
        cout << "  assignment: ";
        Vec<float, 3> a(1, 2, 3);
        cout << a[0] << " "; // to make sure these values are not optimized away!
        a = Vec<float, 3>(4, 5, 6);
        assert(a[0] == 4 && a[1] == 5 && a[2] == 6);
        cout << "passed." << endl;
    }
    {
        cout << "  addition: ";
        Vec<float, 3> a(1, 2, 3), b(4, 5, 6);
        a += b;
        assert((a == Vec<float, 3>{5, 7, 9}));
        auto c = a + Vec<float, 3>(1, 1, 1);
        assert((c == Vec<float, 3>(6, 8, 10)));
        Vec<float, 3> one(1, 1, 1), four(4, 4, 4);
        one += one + one + one;
        assert(one == four);
        Vec<float, 3> x(0, 0, 0), y(1, 1, 1), z(2, 2, 2);
        x += y += z;
        assert((y == Vec<float, 3>(3, 3, 3)));
        assert(x == y);
        cout << "passed." << endl;
    }
        {
        cout << " double addition: ";
        Vec<double, 3> a(1, 2, 3), b(4, 5, 6);
        a += b;
        assert((a == Vec<double, 3>{5, 7, 9}));
        auto c = a + Vec<double, 3>(1, 1, 1);
        assert((c == Vec<double, 3>(6, 8, 10)));
        Vec<double, 3> one(1, 1, 1), four(4, 4, 4);
        one += one + one + one;
        assert(one == four);
        Vec<double, 3> x(0, 0, 0), y(1, 1, 1), z(2, 2, 2);
        x += y += z;
        assert((y == Vec<double, 3>(3, 3, 3)));
        assert(x == y);
        cout << "passed." << endl;
    }
    {
        cout << "  unary minus: ";
        const Vec<float, 3> a(1, 2, 3);
        assert((-a == Vec<float, 3>(-1, -2, -3)));
        cout << "passed." << endl;
    }
    {
        cout << "  dot product: ";
        Vec<float, 3> a(1, 2, 3);
        assert((dot(a, a) == 1 * 1 + 2 * 2 + 3 * 3));
        cout << "passed." << endl;
    }

    {
        // these tests will not compile if you forgot to declare
        // some methods const
        cout << "  constness: ";
        const Vec<float, 3> a(1, 2, 3);
        assert(a[1] == 2);
        assert(a == a);
        assert(!(a != a));
        assert((a + a == Vec<float, 3>(2, 4, 6)));
        //set braces
        assert((-a == Vec<float, 3>{-1, -2, -3}));
        assert((dot(a, a) == 1 * 1 + 2 * 2 + 3 * 3));
        cout << "passed." << endl;
    }

    cout << "all Vec tests passed." << endl
         << endl;
}
