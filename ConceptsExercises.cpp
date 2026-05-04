#include <iostream>
#include <string>
#include <vector>
#include <concepts>
#include <array>
#include <list>

/*
==============================================================================
EXERCISE 1: Using Standard Concepts
==============================================================================
Write a template function named "multiply" that takes two parameters of the same type and returns their product.
Use the existing standard library concept to ensure this function ONLY accepts floating-point numbers (float, double etc.)
*/



/*
==============================================================================
EXERCISE 2: Creating a Custom Concept
==============================================================================
Part 1:
Create a custom concept named "HasName".
A type satisfies HasName if it has a member function called .get_name()
HINT: make sure it returns a type convertible to std::string.

Define the HasName concept here...*/

struct Player {
    int get_health() const { return 100; }
    std::string get_name() const { return "Jeffrey"; }
};

struct Enemy {
    int get_health() const { return 100; }
    int get_attack() const { return 10; }
};

struct Dog {
    const char* get_name() const { return "Rex"; }
};

struct Robot {
    std::string get_model() const { return "A-100"; }
    int get_name() const { return 100001; }
};

/*
Part 2:
Write a function named "print_name" that takes a parameter of type T.
Constrain this function using your HasName concept so it only accepts types that have a .get_name() method.
The function should simply print the name using std::cout

Write your print_name function here...
*/

/*
==============================================================================
EXERCISE 3: Compound Requirements
==============================================================================
Part 1:
Create a concept named "NumericContainer".
A type satisfies NumericContainer if:
    1. It has a .size() method returning a size_t.
    2. It has a .clear() method.
    3. The elements stored inside the container are of an arithmetic type 

HINT: You can access the underlying type of standard containers using T::value_type

Define the NumericContainer concept here...*/


//Part 2:
//Write a function named "process_container" that accepts a NumericContainer and prints its size.
//Write your process_container function here...


//We provide some ways of testing your code here, you are welcome to add your own
//But generally if it passes our tests, it means your solution is correct
int main() {
    std::cout << "--- Testing Exercise 1 ---" << '\n';
    int a = 3;
    int b = 4;

    //Those should compile
    //std::cout << multiply(5.5, 2.0) << '\n'; //11
    //std::cout << multiply(5.5f, 3.0f) << '\n'; //16.5
    //std::cout << multiply(static_cast<float>(a), static_cast<float>(b)) << '\n'; //12
    
    //Those should cause a compilation error
    //std::cout << multiply(5, 2) << '\n';
    //std::cout << multiply(5.5f, 2.0) << '\n';

    std::cout << "\n--- Testing Exercise 2 ---" << '\n';
    Player p;
    Enemy e;
    Robot r;
    Dog d;

    //Those should compile
    //print_name(p);
    //print_name(d);
    
    //Those should cause a compilation error
    //print_name(e);
    //print_name(r);

    std::cout << "\n--- Testing Exercise 3 ---" << '\n';
    std::vector<int> int_vec = { 1, 2, 3 };
    std::vector<std::string> string_vec = { "hello", "world" };
    std::list<float> float_list = { 1.1f, 2.2f, 3.3f , 4.4f};
    std::array<int, 5> int_array = { 1, 2, 3, 4, 5 };
    
    //Those should compile
    //process_container(int_vec);
    //process_container(float_list);
     
    //Those should cause a compilation error
    //process_container(string_vec); //string is not an arithmetic type
    //process_container(int_array); //array doesn't have .clear()


    return 0;
}