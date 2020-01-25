#pragma once

/**
 * Data Stucture Review. Understand the 4 basic data structures
 *
 * sets, unordered_set, maps and unordered_map are all c++ container types
 * http://www.cplusplus.com/reference/stl/
 */

// C is a B is an A
namespace MyNameSpace {
    class MyClass {
        int population;
        int get_population() { return population; }
    };
}

class A {
private:
    int j = 0;
};
class B : public A {};
class C : public B {};

// Vectors, static casting and dynamic casting
#include <vector>
#include <type_traits>
inline void e0() {
    // 1. Create a vector that contains 2 class A*, 2 class B*, 2 class C*
    MyNameSpace::MyClass a;
    int ints_c[8];
    std::vector<int> ints;
    ints.push_back(3);
    ints.insert(ints.begin(), 3);
    std::vector<float> floats;
    std::cout << *ints.begin() << std::endl;

    A a1;
    A a2;
    B b1;
    B b2;
    C c1;
    C c2;

    A* stara = new A(); // Create a floating data structure

    std::vector<A*> array;
    array.push_back(&a1);
    array.push_back(&a2);
    array.push_back(&b1);
    array.push_back(&b2);
    array.push_back(&c1);
    array.push_back(&c2);

    // 2. Iterate through the vector and print "True" if type of class is a type B (Use std::base_of)
    // print "False if class is type B but not type C (Use typeof())
    // There are 3 ways of iterating through a vector.
    // for (size_t i = 0; i < vector.size(); ++i) vector[i];
    // for (const int& i : vector) vector[i];
    // for (auto it = vector.begin(); it != vector.end(); ++it) { *it }
    // Note that the ampersand after the type in the 2nd and 3rd way tell us whether to copy or use the reference
    // Use the 3rd way to iterate through a vector for this example, using const&
    for (size_t i = 0; i < array.size(); ++i) array[i];
    for (const auto a : array) {
//        std::cout << a->j << std::endl;
//        a->j = 4;
    }

    //&ints_c equivalent to array.begin()
    //&ints_c[8] equivalent to array.end()
    for (auto it = array.begin(); it != array.end(); ++it) {
        *it;
    }

    // 3. Use the 2nd way to iterate the vector
    for (const auto a : array) {

    }

    // 4. Loop over the vector and dynamically up cast all of the class B* into class C*

    // 5. Loop over the vector and statically downcast all of the class C* to class A*

}

// A set is binary tree that reorganizes itself overtime, it is useful when you want to store things in alphabetical order without using sort
#include <set>
inline void e1() {
    // Create a set of chars, and in them put the characters z to a in the order
    std::set<char> characters;
    int a = static_cast<int>('a');
    for (int i = 0; i < 26; ++i) {
        characters.insert(static_cast<char>(a + i));
    }
    // Print out the chars, notice that they are in alphabetical order
    for (char c : characters) {
        std::cout << c << std::endl;
    }
}

// Basically a hashtable with O(1) insert, delete and remove, useful for literally everything
#include <unordered_set>
inline void e2() {
    // Repeat the same as e1, now notice they are not in alphabetical order
    std::unordered_set<char> characters;
    int a = static_cast<int>('a');
    for (int i = 0; i < 26; ++i) {
        characters.insert(static_cast<char>(a + i));
    }
    // Print out the chars, notice that they are in alphabetical order
    for (char c : characters) {
        std::cout << c << std::endl;
    }
}

// Basically a set, but with a mapping to a value
#include <map>
inline void e3() {
    // Create a Map of class A -> class B mappings, notice that you need to create the comparison operator in order for this to work because the class needs to be sorted. Use j as the comparison
    // Create a set of chars, and in them put the characters z to a in the order
    std::map<char, char> characters;
    int a = static_cast<int>('a');
    for (int i = 0; i < 26; ++i) {
        characters.insert({static_cast<char>(a + i), static_cast<char>(25 - i + a)});
    }
    for (auto c : characters) {
        std::cout << c.first << " " << c.second << std::endl;
    }
}


#include <unordered_map>
inline void e4() {
    // Create a Unordered Map of class A -> class B mappings, notice that you need to create the hash operator in order for this to work because the class needs to be sorted. Use j as the hash value
    std::unordered_map<char, char> characters;
    int a = static_cast<int>('a');
    for (int i = 0; i < 26; ++i) {
        characters.insert({static_cast<char>(a + i), static_cast<char>(25 - i + a)});
    }
    for (auto c : characters) {
        std::cout << c.first << " " << c.second << std::endl;
    }
}

#include <stack>
#include <queue>
inline void e5() {
    // Create a stack of queues of stacks of class A. And insert into that stack of queues of stacks. Used abundantly in sorting algorithms
    std::stack<int> mystack;
    std::queue<int> myqueue;

    mystack.push(3);
    mystack.push(4);
    myqueue.push(3);
    myqueue.push(4);

    int a = mystack.top(); // yield 4
    int b = myqueue.front(); // yield 3
    mystack.pop();
    myqueue.pop();
}