// +--------------------------------------------+
// |          PART 2: FUNCTIONS & FILES         |
// +--------------------------------------------+
// Functions are modular sequences of statements that
// perform a specific task. They help organize and reuse code.

#include <iostream>
#include <cstdlib> // Provides EXIT_SUCCESS and EXIT_FAILURE status codes

// +--------------------------------------------+
// |              THE PREPROCESSOR              |
// +--------------------------------------------+

/*
 * The preprocessor runs before actual compilation.
 * It processes directives like #include and #define.
 *
 * #include → inserts the contents of another file.
 * #define  → creates a macro (a text replacement rule).
 */

#define MY_NAME "Alex" // Object-like macro example
// std::cout << "My name is " << MY_NAME;
// becomes -> std::cout << "My name is " << "Alex";

// +--------------------------------------------+
// |        CONDITIONAL COMPILATION (#if)       |
// +--------------------------------------------+
//
// Conditional compilation allows you to include or
// exclude parts of code depending on conditions.
//

#define BANANA // Define a macro for testing

void Preprocessor() {
#ifdef BANANA
    std::cout << "Hello\n"; // Will compile because BANANA is defined
#endif

#ifdef BANANA2
    std::cout << "Hello 2\n"; // Will NOT compile because BANANA2 isn’t defined
#endif

#ifndef BANANA2 // Opposite of #ifdef — executes only if not defined
    std::cout << "Hello 2\n"; // Will compile because BANANA2 doesn’t exist
#endif

#if 0 // Excludes this block from compilation (like a large comment)
    std::cout << "Yeah";
    std::cout << "Wow";
#endif // End of excluded block
}

// +--------------------------------------------+
// |            FORWARD DECLARATIONS            |
// +--------------------------------------------+
//
// Tell the compiler these functions exist before defining them.
// Avoid duplicating — it violates the One Definition Rule (ODR).
//

void doPrint();
void Yeah();
int  getValueFromUser();
void printDouble(int value);
int  add(int a, int b);

// +--------------------------------------------+
// |             FUNCTION DEFINITIONS           |
// +--------------------------------------------+

// -- Basic function --
void doPrint() {  // Use vooid if you dont want to return anything
    std::cout << "Hello world!\n";
}

// -- Calling another function --
void Yeah() { 
    doPrint(); // Calls doPrint()
}

// -- Function that returns a value --
int getValueFromUser() {
    int input{};

    std::cout << "Enter an integer: ";
    std::cin >> input;

    return input; // Return user input
}

// -- Function parameters and arguments --
void printDouble(int value) {
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

// -- Simple add function --
int add(int a, int b) {
    return a + b;
}

// +--------------------------------------------+
// |                MAIN FUNCTION               |
// +--------------------------------------------+

int main() {
    doPrint(); // Call a function
    Yeah();    // Calls another function that calls doPrint()

// -- Using return values --
    int num{ getValueFromUser() }; // Store return value
    std::cout << num << " doubled is: " << num * 2 << '\n';

// -- Passing arguments --
    printDouble(5);               // Pass literal
    printDouble(getValueFromUser()); // Pass return value

// -- Multiple parameters --
    std::cout << add(5, 3) << '\n';

    return EXIT_SUCCESS; // Indicates successful program execution

    // Refer to /headers for header guards and related topics.
}
