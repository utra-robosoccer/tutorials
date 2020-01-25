#pragma once

/**
 * How to work with classes. Use alt -> Insert to create things
 */

// Classes can be declared anywhere, inside functions, inside classes, and inside classes inside function inside classes
// There is no difference between a struct and a class. The only difference is public vs private variables
class C1 {
    int a;
    char c;
public:
    C1(int a) : a(a) {}
    C1() = default;
    ~C1() = default;

    // Constructor
    C1(int a_in, char c_in)
    : a(a_in), c(c_in) {
        std::cout << c_in << std::endl;
    }

    // Getters and Setters
    int getA() const {
        return a;
    }

    void setA(int a) {
        C1::a = a;
    }

    // Comparison operators
    bool operator<(const C1 &rhs) const {
        return a < rhs.a;
    }

    bool operator>(const C1 &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const C1 &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const C1 &rhs) const {
        return !(*this < rhs);
    }
};

// Constructors, getters, setters and comparisons
inline void e6() {
    C1 c1(3, 'c');

    // Create a constructor in the class C1 that initializes the integer i. So that the constructor is C1(c) will set the int i to c;
    // Remember that constructors and destructors need to be public

    // Implement the get function C1.get_i(i);
    std::cout << c1.getA() << std::endl;
    // Implement the set function C1.set_i(i);
    c1.setA(4);
    std::cout << c1.getA() << std::endl;


    // Create a comparison function
    C1 c2(5, 'f');

    if (c1 < c2) {
        std::cout << "c1's a is smaller than c2's a" << std::endl;
    } else {
        std::cout << "c1's a is greater than c2's a" << std::endl;
    }

}

// Implicit construction and default destruction
inline void e7() {
//    C1 c1;
    // Implicit construction. If you have created a constructor with a single argument, you automatically have an implicit construction ability
    // Create a vector of C1 and insert the number 0 into the vector. You will automatically create an object of type C1
    // To disable this ability of implicit construction using c++, simply use the explicit keyword before the constructor to prevent this from happening
    C1 c1 = 3;
    std::cout << c1.getA() << std::endl;

    // Default destruction: If you use a default destructor it will automatically clean up all non-pointer types. Implement a default destructor in the class C1

}

// C0 is a type of C1
class C0 : public C1 {
private:

    int k = 3;
};

// Inheritance
inline void e8() {
    // Create a class C0 inside this function that inherits from C1. This class will have a constructor with zero arguments and initialize the value i to 7
    C0 c0;
    c0.getA(); // originally was in C1, is now also in C0 because C0 is a type of C1;

    // Print out this class C0 c0; c0.print_i();

    // Add a print_type to the C0 class, and print out C0 instead of C1

    // Now call the C0 static implementation of print_type. so print C1. Using something like C0::C1::print_type();

    // Turn the print_zed function into a virtual one. Now create an override function in class C0 which prints zee instead of zed
}