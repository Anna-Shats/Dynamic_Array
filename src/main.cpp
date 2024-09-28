// main.cpp
#include "dynamic.h"
#include <iostream>
#include <random>

using namespace std;
using namespace oop;

// function to create a random array for testing 
DynamicArray createRandomArray() {
    static default_random_engine generator(static_cast<unsigned int>(random_device{}()));
    static uniform_int_distribution<int> distribution(1, 100);
    DynamicArray a(10);
    for(int i = 0; i < 10; i++) {
        a[i] = distribution(generator);
    }
    return a;
}

int main(){
    try {
        // creating an array with size and value (10 elements, all initialized to 1)
        DynamicArray a(10, 1); 
        a[0] = 2; 
        a[1] = 3;

        // constructors for copying
        DynamicArray b = a;
        DynamicArray c = createRandomArray();  
        DynamicArray d(b); 

        // move constructor
        DynamicArray e(createRandomArray());

        // Display arrays
        cout << "Array a: " << a << endl;
        cout << "Array b (copy of a): " << b << endl;
        cout << "Array c (random): " << c << endl;
        cout << "Array d (copy of b): " << d << endl;
        cout << "Array e (random): " << e << endl;

        // concatenating two arrays using operator +
        DynamicArray f = a + b; 
        cout << "Array f (a + b): " << f << endl;

        // checking for size of f
        if(f.size() != a.size() + b.size()){
            cerr << "Error: size of f is not the sum of sizes of a and b" << endl;
        } else {
            cout << "Concatenation successful. Size of f is correct." << endl;
        }

    // this catches out of range errors
    } catch (const std::out_of_range& e) {
        cerr << "Exception caught: " << e.what() << endl;
    } catch (...) {
        cerr << "An unexpected exception occurred." << endl;
    }

    return 0; 
}