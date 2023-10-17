#include <array>
#include <vector>

class Vec3f {
public:
    std::array<std::vector<float>, 3> arr;

    //Default construktor with d. values
    Vec3f(float a=1, float b=1, float c=1) {
        arr[0].push_back(a);
        arr[1].push_back(b);
        arr[2].push_back(c);
    }

    
    Vec3f(std::array<std::vector<float>, 3> arr) : arr(arr) {
        // 
        this->arr[0].push_back(1);
        this->arr[1].push_back(1);
        this->arr[2].push_back(1);
    }
    size_t getSize(){
        return sizeof(arr)/sizeof(arr[0]);
    }

    //Operators
    Vec3f Vec3f::operator[]
};