#include <array>
#include <type_traits>

// C++20 concept rulz
template <typename T>
concept Numeric = std::is_arithmetic_v<T>;

//Todo irgenwas mit generischem testtreiber aufgabe4 
namespace my
{
    template <typename T, int N>

    class Vec
    {
    public:
        // std::array for Vec elements
        std::array<T, N> arr;

        // Constructor for N args of type T
        //Variadic Template
        template <typename... Args>
        Vec(Args... args) : arr{args...}
        {
            static_assert(sizeof...(args) == N, "Vec: wrong type of arguments");
        }

        // Returns the size of the array
        size_t getSize() const
        {
            return N;
        }
        // floats the array
/*         Vec(float a = 0, float b = 0, float c = 0)
        {
            arr[0] = (a);
            arr[1] = (b);
            arr[2] = (c);
        } */

/*         // Writes 0 to the array if no arg is given
        Vec(std::array<float, 3> arr) : arr(arr)
        {
            //
            this->arr[0] = (0);
            this->arr[1] = (0);
            this->arr[2] = (0);
        } */

       // Subscript operator (accessor) to access elements
        T operator[](int i) const
        {
            return arr[i];
        }

        // Subscript operator (mutator) to modify elements
        T &operator[](int i)
        {
            return arr[i];
        }

        // operator == and != to check two Vec objects
        bool operator==(const Vec<T, N> &rhs) const
        {
            return arr == rhs.arr;
        }
        bool operator!=(const Vec<T, N> &rhs) const
        {
            return !(*this == rhs);
        }
        // += Operator
        Vec<T, N> &operator+=(const Vec<T, N> &rhs)
        {
            for( int i = 0; i < N; i++)
            {
                arr[i] += rhs.arr[i];
            }
            return *this;
        }
        // + Operator
        Vec<T, N> operator+(const Vec<T, N> &rhs) const
        {
            Vec<T, N> temp(*this);
            temp += rhs;
            return temp;
        }
        // - Operator
        Vec<T, N> operator-(const Vec<T, N> &rhs) const
        {
            Vec<T, N> temp(*this);
            for (int i = 0; i < N; i++)
            {
                temp.arr[i] -= rhs.arr[i]; 
            } 
            return temp;
        }
        // -Pre Operator
        Vec<T, N> operator-() const
        {
            Vec<T, N> temp(*this);
            for (int i = 0; i < N; i++)
            {
                temp.arr[i] = -temp.arr[i];
            }
            return temp;
        }
    };
}