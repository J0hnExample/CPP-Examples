// my_vector.h

#include <cassert>
#include <cstddef> // for size_t anstelle fon std::size_t

namespace my
{

    template <typename ValueT>
    class vector
    {
    private:
        ValueT *data_;             // Zeiger auf das Array der Elemente
        size_t valid_elements_;    // Anzahl der gueltigen Elemente im Array
        size_t reserved_elements_; // Anzahl der reservierten Elemente

    public:
        // Constuktors

        // Default Constructor
        vector() : data_(nullptr), valid_elements_(0), reserved_elements_(0) {}

        vector(size_t count, const ValueT &value = ValueT()) : valid_elements_(count), reserved_elements_(count)
        {
            data_ = static_cast<ValueT *>(malloc(reserved_elements_ * sizeof(ValueT)));
            for (size_t i = 0; i < reserved_elements_; ++i)
            {
                new (&data_[i]) ValueT(value);
            }
        }
        // Copy Constructor
        vector(const vector &rhs) : valid_elements_(rhs.valid_elements_), reserved_elements_(rhs.reserved_elements_)
        {
            data_ = static_cast<ValueT *>(malloc(reserved_elements_ * sizeof(ValueT)));
            for (size_t i = 0; i < valid_elements_; ++i)
            {
                new (&data_[i]) ValueT(rhs.data_[i]);
            }
        }
        // Move/Assign Constructor
        vector(vector &&rhs)
        {
            data_ = std::exchange(rhs.data_, nullptr);
            valid_elements_ = std::exchange(rhs.valid_elements_, 0);
            reserved_elements_ = std::exchange(rhs.reserved_elements_, 0);
        }


        

        // Destructor
        ~vector()
        {
            for (size_t i = 0; i < valid_elements_; ++i)
            {
                data_[i].~ValueT();
            }
            free(data_);
        }
        // Returns Size with valid elements
        size_t size() const { return valid_elements_; }

        //at operator
        ValueT &operator[](size_t index)
        {
            return data_[index];
        }

        const ValueT &operator[](size_t index) const
        {
            return data_[index];
        }
        
        void swap(vector &rhs)
        {
            std::swap(data_, rhs.data_);
            std::swap(valid_elements_, rhs.valid_elements_);
            std::swap(reserved_elements_, rhs.reserved_elements_);
        }


        // Friend Declaration
        friend void swap(vector &lhs, vector &rhs);
    };

    template <typename ValueT>
    void swap(vector<ValueT> &lhs, vector<ValueT> &rhs)
    {
        lhs.swap(rhs);
    }

} // namespace my
