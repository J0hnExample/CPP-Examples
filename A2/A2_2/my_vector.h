// my_vector.h

#include <cassert>
#include <cstddef> // for size_t anstelle fon std::size_t

namespace my
{

    template <typename ValueT>
    class vector
    {
    private:
        ValueT *data;    // Zeiger auf das Array der Elemente
        size_t elements; // Anzahl der Elemente im Array
        size_t capacity_;

    public:
        // swapy
        friend void swap(vector &lhs, vector &rhs);

        // 1. bool empty()
        bool empty() const
        {
            return elements == 0;
        }

        //size_t size() gibt gültige elemente zurück
        size_t size() const
        {
            if ( data == nullptr )
            {
                return 0;
            }else
            {
                return elements;
            }
        }
        
        //liefert die Anzahl der reservierten Elemente zurück.
        size_t capacity() const
        {
            return capacity_;
                        
        }
        void shrink_to_fit()
        {
            reserve(elements);
        }
        //Konstruktor by the rule of three

        vector() : data(nullptr), elements(0) {}

        vector(size_t count, const ValueT &value = ValueT()) : elements(count)
        {
            data = new ValueT[elements];
            for (size_t i = 0; i < elements; ++i)
            {
                data[i] = value;
            }
        }
        /*
                // copy constructor
                vector(const vector &rhs) : elements(rhs.elements)
                {
                    data = new ValueT[elements];
                    for (size_t i = 0; i < elements; ++i)
                    {
                        data[i] = rhs.data[i];
                    }
                }

                //assignment constructor
                 vector& operator=(const vector& rhs) {
                     if (this != &rhs) {
                         delete[] data;
                         elements = rhs.elements;
                         data = new ValueT[elements];
                         for (size_t i = 0; i < elements; ++i) {
                             data[i] = rhs.data[i];
                         }
                     }
                     return *this;
                 }
                     //move zuweisung/constructor
                 vector& operator=(vector&& rhs) {
                     if (this != &rhs) {
                         delete[] data;
                         elements = rhs.elements;
                         data = rhs.data;
                         rhs.data = nullptr;
                         rhs.elements = 0;
                     }
                     return *this;
                 } */

        // move zuweisung/constructor jetzt mit swap geschmack

        // copy with swap
        vector operator=(vector rhs)
        {
            swap(*this, rhs);
            return *this;
        }

        /*         // swap assagnment constructor
                vector& operator=(vector rhs)
                {
                    vector temp(rhs);
                    temp.swap(*this);
                    swap(*this, rhs);
                } */
        // swap move constructor
        vector operator=(vector &&rhs)
        {
            : vector();
            /* swap(elements, rhs.elements);
            swap(data, rhs.data); */
            swap(*this, rhs);
            return *this;
        }

        // 4. Destruktor
        ~vector()
        {
            delete[] data;
        }
        //

        // clear() bleibt so
        void clear()
        {
            delete[] data;
            data = nullptr;
            elements = 0;
        }

        void reserve(size_t new_capacity)
        {
            if (new_capacity > capacity_)
            {
                ValueT *new_data = static_cast<ValueT *>(std::malloc(new_capacity * sizeof(ValueT)));

                // Kopiere die vorhandenen Daten in den neuen Speicher
                std::copy(data, data + elements, new_data);

                delete[] data;
                data = new_data;
                capacity_ = new_capacity;
            }
        }


        //  push_back jetzt mit extra speicher
        void push_back(const ValueT &value)
        {
            if (elements == capacity_)
            {
                
                size_t new_capacity = (capacity_ == 0) ? 1 : capacity_ * 2;
                ValueT *newData = new ValueT[new_capacity];

                // Kopierem der elemente
                for (size_t i = 0; i < elements; ++i)
                {
                    newData[i] = data[i];
                }

                // Freigebe den alten Speicher
                delete[] data;

                // 
                data = newData;
                capacity_ = new_capacity;
            }


            data[elements] = value;
            ++elements;
        }
        

        ValueT pop_back()
        {
            // Überprüfe, ob der Vektor nicht leer ist
            if (elements > 0)
            {
                // Hole das letzte Element
                ValueT lastElement = data[elements - 1];

                // Reduziere die Anzahl der Elemente
                --elements;

                // Gib das letzte Element zurück
                return lastElement;
            }
            else
            {
                return ValueT(); // Standardwert für den Fall, dass der Vektor leer ist
            }
        }

        // 8. operator[](size_t)
        ValueT &operator[](size_t index)
        {
            // assert(index >= 0 && index < elements);  // in bounds
            return data[index];
        }
        // operator für const objekte
        const ValueT &operator[](size_t index) const
        {
            return data[index];
        }

        // 9. at(size_t)
        ValueT &at(size_t index)
        {
            if (index >= elements)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }
        // at für const objekte
        const ValueT &at(size_t index) const
        {
            if (index >= elements)
            {
                throw std::out_of_range("Index out of range");
            }
            return data[index];
        }

        // 10. Kopieren und Zuweisen verboten
        /*     vector(const vector<ValueT>&) = delete;
            vector<ValueT>& operator=(const vector<ValueT>&) = delete; */
    };

} // namespace my

// swap
namespace my
{

    template <typename ValueT>
    void swap(vector<ValueT> &lhs, vector<ValueT> &rhs)
    {
        swap(lhs.data, rhs.data);
        swap(lhs.elements, rhs.elements);
    }

} // namespace my