#include "oop/dynamic.h"
#include <stdexcept>
#include <utility>   

namespace oop {

// Constructor: Initializes array with 'size' elements set to 0
DynamicArray::DynamicArray(int size) : length(size), data(new int[size]()) {}

/**
 * @brief Constructs a DynamicArray with a specified size and initial value.
 * @param size The number of elements in the array.
 * @param value The initial value to assign to all elements.
 */
DynamicArray::DynamicArray(int size, int value) : length(size), data(new int[size]) {
    for(int i = 0; i < size; ++i) {
        data[i] = value;
    }
}

// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray& other) : length(other.length), data(new int[other.length]) {
    for(int i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

// Move Constructor
DynamicArray::DynamicArray(DynamicArray&& other) noexcept : length(other.length), data(other.data) {
    other.length = 0;
    other.data = nullptr;
}

// Copy Assignment Operator 
DynamicArray& DynamicArray::operator=(DynamicArray other) {
    swap(*this, other);
    return *this;
}

// Destructor
DynamicArray::~DynamicArray() {
    delete[] data;
}

// Overloaded [] Operator for non-const objects
int& DynamicArray::operator[](int index) {
    if(index < 0 || index >= length) throw std::out_of_range("Index out of range");
    return data[index];
}

// Overloaded [] Operator for const objects
const int& DynamicArray::operator[](int index) const {
    if(index < 0 || index >= length) throw std::out_of_range("Index out of range");
    return data[index];
}

// Overloaded + Operator
DynamicArray DynamicArray::operator+(const DynamicArray& other) const {
    DynamicArray result(this->length + other.length);
    for(int i = 0; i < this->length; ++i) {
        result.data[i] = this->data[i];
    }
    for(int i = 0; i < other.length; ++i) {
        result.data[this->length + i] = other.data[i];
    }
    return result;
}

int DynamicArray::size() const {
    return length;
}

// Overloaded << Operator
std::ostream& operator<<(std::ostream& os, const DynamicArray& arr) {
    for(int i = 0; i < arr.length; ++i) {
        os << arr.data[i];
        if(i != arr.length - 1) {
            os << " ";
        }
    }
    return os;

} 
// Swap function for copy-and-swap
void swap(DynamicArray& first, DynamicArray& second) noexcept {
    using std::swap;
    swap(first.data, second.data);
    swap(first.length, second.length);
}
}