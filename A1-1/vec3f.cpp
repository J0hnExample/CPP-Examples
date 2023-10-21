#include <array>
#include <vector>

namespace my
{
    class Vec3f
    {
    public:
        // std::array container
        std::array<float, 3> arr;

        // Constructors

        // floats the array
        Vec3f(float a = 0, float b = 0, float c = 0)
        {
            arr[0] = (a);
            arr[1] = (b);
            arr[2] = (c);
        }

        // Writes 0 to the array if no arg is given
        Vec3f(std::array<float, 3> arr) : arr(arr)
        {
            //
            this->arr[0] = (0);
            this->arr[1] = (0);
            this->arr[2] = (0);
        }
        size_t getSize()
        {
            return sizeof(arr) / sizeof(arr[0]);
        }

        // Operators

        // accessors
        // Read operator, takes number and gives back the float
        /*     float operator[](int i) {
                return arr[i];
            } */
        // Beachten Sie, dass der Subscript-Operator auch funktionieren soll, wenn das Objekt
        // schreibgeschützt (const) ist (Accessor)
        float operator[](int i) const
        {
            return arr[i];
        }

        // Mutators
        //
        //  set operator
        float &operator[](int i)
        {
            return arr[i];
        }
        // operator == and != to check two Vec3f objects
        bool operator==(const Vec3f &rhs) const
        {
            Vec3f temp(*this);
            if (temp[0] == rhs[0] && temp[1] == rhs[1] && temp[2] == rhs[2])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool operator!=(const Vec3f &rhs) const
        {
            Vec3f temp(*this);
            if (temp[0] == rhs[0] && temp[1] == rhs[1] && temp[2] == rhs[2])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        // += Operator
        Vec3f &operator+=(const Vec3f rhs)
        {
            arr[0] += rhs[0];
            arr[1] += rhs[1];
            arr[2] += rhs[2];
            return *this;
        }
        // + Operator
        Vec3f operator+(const Vec3f &rhs) const
        {
            Vec3f temp(*this);
            temp += rhs;
            return temp;
        }
        // - Operator
        Vec3f operator-(const Vec3f &rhs) const
        {
            Vec3f temp(*this);
            temp.arr[0] -= rhs.arr[0];
            temp.arr[1] -= rhs.arr[1];
            temp.arr[2] -= rhs.arr[2];
            return temp;
        }
        // -Pre Operator
        Vec3f operator-() const
        {
            Vec3f temp(*this);
            temp.arr[0] *= -1;
            temp.arr[1] *= -1;
            temp.arr[2] *= -1;
            return temp;
        }
    };
}