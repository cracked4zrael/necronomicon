// +--------------------------------------------+
// |              INCLUDING HEADERS             |
// +--------------------------------------------+
// #include "add.h" → Includes your own header file.
// Never include `.cpp` files — it can cause multiple definition errors
// and undefined behavior during linking.

#include <iostream>
#include "add.h" 

int main() {
    std::cout << "Hello world";

    // Using add() defined in add.cpp and declared in add.h
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << '\n';

    return 0;
}
