// +--------------------------------------------+
// |               PART 1: THE BASICS           |
// +--------------------------------------------+

#include <iostream>   // Provides standard input/output (std::cout, std::cin)
#include <string>     // Provides std::string

// Just like in C, your program's entry point is a function called main() with an integer return type 
// The integer return type serves as the program's exit status

int main(int argc, char** argv) {
// Command line argument are passed in argc (number of args), and argv(array of C-style strings)



// +--------------------------------------------+
// |                  OUTPUT                    |
// +--------------------------------------------+

// -- Printing text --
    std::cout << "Hello world"; // Basic print statement
                                // In C++23, you can use std::println for convenience
                                // '//' is a single-line comment

/*
 * This is a multi-line comment.
 * Use it for longer explanations.
 */

// +--------------------------------------------+
// |    OBJECTS, VARIABLES, LITERALS & TYPES    |
// +--------------------------------------------+

// -- What they are --
    // Objects store data.
    // The actual values stored in them are called *literals*.

    int a { 4 };                  // Integer literal
    int b { 3.14 };               // Implicit conversion (3.14 → 3)
    char c { 'H' };               // Character literal
    std::string str { "Hello" };  // String object

// -- Printing multiple values --
    std::cout << 5 << -6.7 << 'H' << "Hello"; // Outputs everything in sequence

// +--------------------------------------------+
// |     VARIABLE ASSIGNMENT & INITIALIZATION   |
// +--------------------------------------------+

// -- Common ways to initialize variables --
    int variable;          // Declared but uninitialized (garbage value)
    int x { };             // Zero-initialization (sets to 0)
    int y { 1 };           // Direct list initialization
    int p, q;              // Declaring multiple variables
    int m { 1 }, n { 2 };  // Declaring and initializing multiple variables

// -- Copy assignment --
    int width;
    width = 7; // Assigns a new value to an existing variable

// +--------------------------------------------+
// |            IOSTREAM, COUT, CIN             |
// +--------------------------------------------+

// -- Basic output --
    std::cout << "Hello";
    int num { 5 };
    std::cout << num;                // Print variable value
    std::cout << "Hi!" << std::endl; // Prints with newline and flushes buffer
    std::cout << "Hi!\n";            // Prints with newline (preferred, faster)

// +--------------------------------------------+
// |              USER INPUT (CIN)              |
// +--------------------------------------------+

// -- Reading input --
    int value { };
    std::cout << "Enter a number: ";
    std::cin >> value; // Reads input from keyboard into 'value'

    std::cout << "You entered: " << value << '\n';

// -- Remember --
    // >> is for input (extracting data from keyboard)
    // << is for output (inserting data to console)

// +--------------------------------------------+
// |                 OPERATORS                  |
// +--------------------------------------------+

// -- Common operator categories --
    // Arithmetic: +, -, *, /
    // Assignment: =
    // I/O: << (output), >> (input)
    // Keywords: new, delete, throw (used for memory and error handling)

// -- Example --
    std::cout << 3 + 1; // Correct usage — use << for output, not >>

// +--------------------------------------------+
// |                  END MAIN                  |
// +--------------------------------------------+
  return 0; // tells the operating system that the program ran successfully.  
}
