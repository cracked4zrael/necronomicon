#include <iostream>
// +--------------------------------------------+
// |              HEADER FILE BASICS            |
// +--------------------------------------------+
//
// #include <...> → compiler searches system include directories
// #include "..." → compiler searches current directory first, 
//                  then system directories (use this for your own headers)
//

// +--------------------------------------------+
// |             WHY USE HEADER FILES?          |
// +--------------------------------------------+
//
// As programs grow and split across multiple files, 
// manually telling each file about functions or variables 
// in other files becomes tedious.
//
// Header files solve this by centralizing declarations.
//

// -- Forward Declaration Example --
// This tells main.cpp about add(), even though it's defined elsewhere.
// But if you had many functions, manually writing them all would get messy.
// Solution → use a header file (see Part 2 directory).
int add(int x, int y);

// +--------------------------------------------+
// |                 MAIN FUNCTION              |
// +--------------------------------------------+

int main() {
    std::cout << "Hello world"; 
    // We didn’t declare std::cout ourselves — it’s declared inside <iostream>.
    // When we include <iostream>, the compiler effectively "copy-pastes"
    // all of its declarations into our program.

    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

    return 0;
}
