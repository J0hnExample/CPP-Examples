#include <iostream>
#include <random>
#include <chrono>
#include <vector>
#include "vec.h"


using namespace my;
using namespace std;

//To_DO aufgabe 5
int main()
{
    
    //Create random seed
    random_device rd;
    //mix some hardware entrophy with the system time
    unsigned int seed = rd() ^ static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());

    //print out the random number
    cout << seed << endl;
    mt19937_64 gen(seed);
    //print out the random number
    cout << gen() << endl;


    //Create vector
    vector<Vec<float, 3>> vectors;
    //stick 10 random floats beetween 0 and 100 in the vector
    for (int i = 0; i < 10; i++)
    {
        vectors.push_back(Vec<float, 3>(gen() % 100, gen() % 100, gen() % 100));
    }
    //Test no dingens schleife
/*     generate_n(back_inserter(vectors), 10, []() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return my::Vec<float, 3>(gen() % 100, gen() % 100, gen() % 100);
    });
 */
    //print out the vector
    for (int i = 0; i < 10; i++)
    {
        cout << vectors[i] << endl;
    }

    //std::transform to increase every value in the vector by1
    //Vector range, start vector range, end vector range, lambda function                       
    transform(vectors.begin(), vectors.end(), vectors.begin(), [](Vec<float, 3> v) {
        return v + Vec<float, 3>(1, 1, 1);
    });

    
    //print out the vector
    for (int i = 0; i < 10; i++)
    {
        cout << "Increase: " << vectors[i] << endl;
    }

    return 0;
}
