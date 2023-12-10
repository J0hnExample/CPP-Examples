// my_vector.h
#pragma once

#include <cassert>
#include <cstddef>  // for size_t anstelle fon std::size_t

namespace my {

template <typename ValueT>
class vector {
private:
    ValueT* data; // Zeiger auf das Array der Elemente
    size_t elements; // Anzahl der Elemente im Array

public:
    // 1. bool empty()
    bool empty() const {
        return elements == 0;
    }

    // 2. size_t size()
    size_t size() const {
        return elements;
    }

    // 3. Konstruktor
    vector() : data(nullptr), elements(0) {}

    vector(size_t count, const ValueT& value) : data(new ValueT[count]), elements(count) {
        for (size_t i = 0; i < count; ++i) {
            data[i] = value;
        }
    }

    // 4. Destruktor
    ~vector() {
        delete[] data;
    }

    // 5. clear()
    void clear() {
        delete[] data;
        data = nullptr;
        elements = 0;
    }

    // 6. push_back(const ValueT&)
    void push_back(const ValueT& value) {
        ValueT* newData = new ValueT[elements + 1];

    //
    std::copy(data, data + elements, newData);
     /*    for (size_t i = 0; i < elements; ++i) {
            newData[i] = data[i];
        } */

        newData[elements] = value;
        delete[] data;
        data = newData;
        ++elements;
    }

    // 7. pop_back()
    ValueT pop_back() {
        //assert(elements > 0);  // is not empty

        ValueT lastElement = data[elements - 1];
        ValueT* newData = new ValueT[elements - 1];

        std::copy(data, data + elements - 1, newData);
        /* for (size_t i = 0; i < elements - 1; ++i) {
            newData[i] = data[i];
        }
 */
        delete[] data;
        data = newData;
        --elements;

        return lastElement;
    }

    // 8. operator[](size_t)
    ValueT& operator[](size_t index) {
        //assert(index >= 0 && index < elements);  // in bounds
        return data[index];
    }

    // 9. at(size_t)
    ValueT& at(size_t index) {
        if (index >= elements) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // 10. Kopieren und Zuweisen verboten
    vector(const vector<ValueT>&) = delete;
    vector<ValueT>& operator=(const vector<ValueT>&) = delete;
};

}  // namespace my
