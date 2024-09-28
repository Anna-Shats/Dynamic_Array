#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream> 

namespace oop {

/**
 * @class DynamicArray
 * @brief A dynamic array class that stores integers.
 *
 * The DynamicArray class provides functionalities to create, copy, move,
 * and perform operations on a dynamic array of integers.
 */
class DynamicArray {
private:
    int* data;      ///< Pointer to the dynamically allocated array.
    int length;     ///< Size of the array.

public:
    /**
     * @brief Constructs a DynamicArray with a specified size, initializing all elements to 0.
     * @param size The number of elements in the array.
     */
    DynamicArray(int size);

    /**
     * @brief Constructs a DynamicArray with a specified size and initial value for all elements.
     * @param size The number of elements in the array.
     * @param value The initial value to assign to all elements.
     */
    DynamicArray(int size, int value);

    /**
     * @brief Copy constructor for DynamicArray to perform a deep copy with a new array.
     * @param other The DynamicArray to copy from.
     */
    DynamicArray(const DynamicArray& other);

    /**
     * @brief Move constructor for DynamicArray to transfer resources from another array.
     * @param other The DynamicArray to move from.
     */
    DynamicArray(DynamicArray&& other) noexcept;

    /**
     * @brief Copy assignment operator that performs a deep copy with a new array
     * @param other The DynamicArray to copy .
     * @return Reference to the assigned DynamicArray.
     */
    DynamicArray& operator=(DynamicArray other);

    /**
     * @brief Destructor for DynamicArray.
     */
    ~DynamicArray();

    /**
     * @brief Overloaded operator [] for accessing/modifying elements.
     * @param index The index of the element to access.
     * @return Reference to the integer at the specified index.
     * @throws std::out_of_range if index is invalid.
     */
    int& operator[](int index);

    /**
     * @brief Overloaded operator [] for accessing elements in const contexts.
     * @param index The index of the element to access.
     * @return Const reference to the integer at the specified index.
     * @throws std::out_of_range if index is invalid.
     */
    const int& operator[](int index) const;

    /**
     * @brief Overloaded operator + to concatenate two DynamicArrays.
     * @param other The array to concatenate.
     * @return A new array containing elements of both arrays.
     */
    DynamicArray operator+(const DynamicArray& other) const;

    /**
     * @brief Retrieves the size of the DynamicArray.
     * @return The number of elements in the array.
     */
    int size() const;

    /**
     * @brief Overloaded operator<< to output the DynamicArray.
     * @param os The output stream.
     * @param arr The DynamicArray to output.
     * @return Reference to the output stream.
     */
    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& arr);

    /**
     * @brief Swaps the contents of two DynamicArrays.
     * @param first The first DynamicArray.
     * @param second The second DynamicArray.
     */
    friend void swap(DynamicArray& first, DynamicArray& second) noexcept;
};

} 

#endif // DYNAMICARRAY_H

