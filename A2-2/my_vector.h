// my_vector.h

#include <cassert>
#include <utility>
#include "trackmymoves.h"

namespace my
{

    template <typename ValueT>
    class vector
    {
    private:
        ValueT *data_;             // Zeiger auf das Array der Elemente
        std::size_t valid_elements_;    // Anzahl der gueltigen Elemente im Array
        std::size_t reserved_elements_; // Anzahl der reservierten Elemente

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
        // Move
        vector(vector &&rhs) noexcept
        {
            std::cout << "Move Constructor used\n" << std::endl;
            data_ = std::exchange(rhs.data_, nullptr);
            valid_elements_ = std::exchange(rhs.valid_elements_, 0);
            reserved_elements_ = std::exchange(rhs.reserved_elements_, 0);
        }
        // Assignment Operator
        vector& operator=(vector copy) noexcept
        {
            copy.swap(*this);
            return *this;
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
        //Reserve
        void reserve(size_t new_reserved_elements)
        {
             
            ValueT *new_data_ = static_cast<ValueT *>(std::malloc(new_reserved_elements * sizeof(ValueT)));
            if (data_ != nullptr)
            {
                
                for (size_t i = 0; i < valid_elements_; ++i)
                {
                    new (&new_data_[i]) ValueT(std::move(data_[i]));//mit und ohne std::move
                    data_[i].~ValueT();
                }
                //ohne std::move copy 89 move 13
                //mit std::move copy 71 move 31
                
            }
            free(data_);
            data_ = new_data_;
            reserved_elements_ = new_reserved_elements;
        }
        //
        void shrink_to_fit()
        {
            if (valid_elements_ < reserved_elements_)
            {
                reserve(valid_elements_);
            }
        }
        // Returns Size with valid elements
        size_t size() const { return valid_elements_; }
        // Retunrs capacity
        size_t capacity() const { return reserved_elements_; }
        //pop_back return last element
        ValueT pop_back()
        {   
            //Schönes Beispiel wann pre-increment oder postincrement verwendet werden kann
            //valid_elements_--;
            ValueT &last_element = data_[--valid_elements_];
            ValueT temp_element = last_element;
            last_element.~ValueT();
            return temp_element;              
        }
        //push_back
        void push_back(const ValueT &value)
        {
            if (valid_elements_ >= reserved_elements_ )
            {
                size_t new_capacity = (reserved_elements_ == 0) ? 1 : reserved_elements_ * 2;
                reserve(new_capacity);
            }
            new (&data_[valid_elements_]) ValueT(value); //Hier war ein ++ zu viel und alles explodiert
            valid_elements_++;
        }
        //CLear
        void clear()
        {
            for (size_t i = 0; i < valid_elements_; ++i)
            {
                data_[i].~ValueT();
            }
            valid_elements_ = 0;
            //data_ = nullptr;
        }
        //at operator
        ValueT &operator[](size_t index)
        {
            return data_[index];
        }

        const ValueT &operator[](size_t index) const
        {
            return data_[index];
        }
        ValueT &at(size_t index)
        {
            if (index >= valid_elements_)
            {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }

        const ValueT &at(size_t index) const
        {
            if (index >= valid_elements_)
            {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }

        bool empty() const
        {
            return valid_elements_ == 0;
        }

        void swap(vector &rhs) noexcept
        {
            std::swap(data_, rhs.data_);
            std::swap(valid_elements_, rhs.valid_elements_);
            std::swap(reserved_elements_, rhs.reserved_elements_);
        }
        ValueT *currentdataAdress()
        {
            return data_;
        }

        // Friend Declaration
        friend void swap(vector &lhs, vector &rhs);
    };

    template <typename ValueT>
    void swap(vector<ValueT> &lhs, vector<ValueT> &rhs) noexcept
    {
        lhs.swap(rhs);
    }

} // namespace my
