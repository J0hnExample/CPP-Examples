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
        Vec(Args... args) : arr{static_cast<T>(args)...}
        {
            //static_assert(sizeof...(args) == 0 || sizeof...(args) == N, "Vec: wrong type of arguments");
        }

        // Returns the size of the array
        size_t getSize() const
        {
            return N;
        }

       // Subscript operator (accessor) to access elements
        T operator[](const int i) const
        {
            return arr[i];
        }

        // Subscript operator (mutator) to modify elements
        T &operator[](const int i)
        {
            return arr[i];
        }

        // operator == and != to check two Vec objects
        bool operator==(const Vec<T, N>& rhs) const
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
            Vec<T, N> temp( *this);
            for (int i = 0; i < N; i++)
            {
                temp.arr[i] = -temp.arr[i];
            }
            return temp;
        }
    };
}
//Template dot funktion
  template <typename T, int N>
T dot(const my::Vec<T, N> &v1, const my::Vec<T, N> &v2)
{
    T result = 0;
    for (int i = 0; i < N; i++)
    {
        result += v1[i] * v2[i];
    }
    return result;
}