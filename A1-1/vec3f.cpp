#include <array>
#include <vector>

class Vec3f {
public:
    //std::array container
    std::array<float, 3> arr;

    //Constructors

    //floats the array
    Vec3f(float a=0, float b=0, float c=0) {
        arr[0]=(a);
        arr[1]=(b);
        arr[2]=(c);
    }

    //Writes 0 to the array if no arg is given
    Vec3f(std::array<float, 3> arr) : arr(arr) {
        // 
        this->arr[0]=(0);
        this->arr[1]=(0);
        this->arr[2]=(0);
    }
    size_t getSize(){
        return sizeof(arr)/sizeof(arr[0]);
    }
    

    //Operators

    //accessors
    //Read operator, takes number and gives back the float
/*     float operator[](int i) {
        return arr[i];
    } */
    //Beachten Sie, dass der Subscript-Operator auch funktionieren soll, wenn das Objekt
    //schreibgeschützt (const) ist (Accessor)
    float operator[](int i) const {
        return arr[i];
    }

    //Mutators
    //
  float& operator[](int i) {
    return arr[i];
}
   
};