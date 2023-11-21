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
/*     
    //Create random seed
    random_device rd;
    //mix some hardware entrophy with the system time
    unsigned int seed = rd() ^ static_cast<unsigned int>(chrono::system_clock::now().time_since_epoch().count());

    //print out the random number
    cout << seed << endl;
    mt19937_64 gen(seed);
    //print out the random number
    cout << gen() << endl;
 */

    //Create vector
    std::vector<my::Vec<float, 3>> vectors;
    generateRandomVectors(vectors, 10);

    
    //stick 10 random floats beetween 0 and 100 in the vector
/*     for (int i = 0; i < 10; i++)
    {
        vectors.push_back(Vec<float, 3>(gen() % 100, gen() % 100, gen() % 100));
    } */
    //Test no dingens schleife mit random generator and funky seeds


    //print out the vectors normal
    for (int i = 0; i < 10; i++)
    {
        cout << vectors[i] << endl;
        
    }

    //std::transform to increase every value in the vector by1
    //Vector range, start vector range, end vector range, lambda function
        transform(vectors.begin(), vectors.end(), vectors.begin(), [](Vec<float, 3> v) {
        return v + Vec<float, 3>(1, 1, 1);
    });

    //Sort the vector by <90.0 degree angle and >= 90.0 degree angle
    std::stable_partition(vectors.begin(), vectors.end(), [](Vec<float, 3> vec) {
        return length(vec) < 90.0f;
    });
    //print out the vector
    for (const auto& vec : vectors) {
        printVec(vec);
        std::cout << "-------------" << std::endl;  // Separate vectors
    } 
    //sort by length with std::sort
    sortVectors(vectors);

    //print out the vector
    for (const auto& vec : vectors) {
        printVec(vec);
        std::cout << "-------------" << std::endl;  // Separate vectors
    }                   

    //get the median
    
    //printVec((vectors[vectors.size() / 2]+vectors[vectors.size() / 2])/2);
        size_t size = vectors.size();
    if (size % 2 == 0)
    {
        // If the size is even, take the average of the two middle elements
        auto median = (length(vectors[size / 2 - 1]) + length(vectors[size / 2])) / 2.0f;
        std::cout << "Median Length: " << median << "\n";
    }
    else
    {
        // If the size is odd, take the middle element
        auto median = length(vectors[size / 2]);
        std::cout << "Median Length: " << median << "\n";
    }
    
/*     //print out the vector increased
    for (int i = 0; i < 10; i++)
    {
        cout << "Increase: " << vectors[i] << endl;
    } */

    //Copy all vectors <80 into a new vector
    std::vector<my::Vec<float, 3>> newVector;
    std::copy_if(vectors.begin(), vectors.end(), std::back_inserter(newVector), [](my::Vec<float, 3> vec) {
        return length(vec) < 80.0f;
    });
    //print out the new vector
    std::cout << "New Vector: " << std::endl;
    for (const auto& vec : newVector) {
        printVec(vec);
        std::cout << "-------------" << std::endl;
    }

    return 0;
}
