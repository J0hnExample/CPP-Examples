#include <array>
#include <vector>


template<typename T, int N>
class Vec3f
    {
    public:
        // std::array container
        std::array<T, N> arr;

        // Constructors
        Vec3f()
        {
            for (int i = 0; i < N; i++)
            {
                arr[i] = 0;
            } 
        }
        
    template<typename... Args>
    Vec(Args... args) : arr{args...}
    {
        static_assert(sizeof...(args) == N, "Incorrect number of arguments");
    }

template<typename ... Args>
concept IntOrFloat = std::is_integral_v<Args> || std::is_floating_point_v<Args>;

    size_t getSize()
    {
        return arr.size();
    }

    // Operators
    T& operator[](int i)
    {
        return arr[i];
    }

    const T& operator[](int i) const
    {
        return arr[i];
    }

    bool operator==(const Vec& rhs) const
    {
        return arr == rhs.arr;
    }

    bool operator!=(const Vec& rhs) const
    {
        return arr != rhs.arr;
    }

    Vec& operator+=(const Vec& rhs)
    {
        for (int i = 0; i < N; i++)
        {
            arr[i] += rhs.arr[i];
        }
        return *this;
    }

    Vec operator+(const Vec& rhs) const
    {
        Vec temp(*this);
        temp += rhs;
        return temp;
    }

    Vec operator-(const Vec& rhs) const
    {
        Vec temp(*this);
        for (int i = 0; i < N; i++)
        {
            temp.arr[i] -= rhs.arr[i];
        }
        return temp;
    }

    Vec operator-() const
    {
        Vec temp(*this);
        for (int i = 0; i < N; i++)
        {
            temp.arr[i] *= -1;
        }
        return temp;
    }
};