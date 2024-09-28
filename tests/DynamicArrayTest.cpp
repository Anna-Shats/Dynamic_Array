#include "oop/dynamic.h"
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace oop;

// class for testing DynamicArray
class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArrayTest() {
    }

    ~DynamicArrayTest() override {
    }

    void SetUp() override {
    }

    void TearDown() override {
    }
};

/**
 * @brief Tests the constructor that initializes the array with a specified size and initial value.
 */
TEST_F(DynamicArrayTest, ConstructorSizeAndValue) {
    int size = 10;
    int value = 7;
    DynamicArray arr(size, value);
    EXPECT_EQ(arr.size(), size);
    for(int i = 0; i < size; ++i) {
        EXPECT_EQ(arr[i], value);
    }
}

/**
 * @brief Tests the copy constructor to ensure a copy is made.
 */
TEST_F(DynamicArrayTest, CopyConstructor) {
    int size = 5;
    int value = 3;
    DynamicArray original(size, value);
    DynamicArray copy(original);

    EXPECT_EQ(copy.size(), original.size());

    for(int i = 0; i < size; ++i) {
        EXPECT_EQ(copy[i], original[i]);
    }
    original[0] = 100;
    EXPECT_EQ(copy[0], value);
    EXPECT_EQ(original[0], 100);
}

/**
 * @brief Tests the move constructor to ensure resources are transferred correctly.
 */
TEST_F(DynamicArrayTest, MoveConstructor) {
    int size = 5;
    int value = 4;
    DynamicArray original(size, value);
    DynamicArray moved(std::move(original));

    EXPECT_EQ(moved.size(), size);
    for(int i = 0; i < size; ++i) {
        EXPECT_EQ(moved[i], value);
    }

    EXPECT_EQ(original.size(), 0);
    EXPECT_THROW(original[0], std::out_of_range);
}



/**
 * @brief Tests the move assignment operator to ensure transfers are made correctly.
 */
TEST_F(DynamicArrayTest, MoveAssignmentOperator) {
    int size = 6;
    int value = 5;
    DynamicArray original(size, value);
    DynamicArray moved(3, 10); 

    moved = std::move(original);

    EXPECT_EQ(moved.size(), size);
    for(int i = 0; i < size; ++i) {
        EXPECT_EQ(moved[i], value);
    }

    EXPECT_EQ(original.size(), 0);
    EXPECT_THROW(original[0], std::out_of_range);
}

/**
 * @brief Tests the operator [] to access and modify elements in the array.
 */
TEST_F(DynamicArrayTest, SubscriptOperator) {
    int size = 4;
    int value = 1;
    DynamicArray arr(size, value);

    for(int i = 0; i < size; ++i) {
        arr[i] = i * 10;
    }

    for(int i = 0; i < size; ++i) {
        EXPECT_EQ(arr[i], i * 10);
    }
}

/**
 * @brief Tests the operator + to concatenate two DynamicArrays.
 */
TEST_F(DynamicArrayTest, AdditionOperator) {
    DynamicArray arr1(3, 2); 
    DynamicArray arr2(2, 5); 

    DynamicArray arr3 = arr1 + arr2; 

    EXPECT_EQ(arr3.size(), 5);
    EXPECT_EQ(arr3[0], 2);
    EXPECT_EQ(arr3[1], 2);
    EXPECT_EQ(arr3[2], 2);
    EXPECT_EQ(arr3[3], 5);
    EXPECT_EQ(arr3[4], 5);
}



