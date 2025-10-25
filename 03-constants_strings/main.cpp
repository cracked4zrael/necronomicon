// +--------------------------------------------+
// |            CONSTANTS & STRINGS             |
// +--------------------------------------------+

#include <iostream>
#include <string>
#include <string_view>
#include <bitset>
#include <format>


// -- Example functions --
void printStringBad(std::string str) { 
    std::cout << str << '\n';
}

void printStringGood(std::string_view str) {
    std::cout << str << '\n';
}

int main() {

// +--------------------------------------------+
// |                 CONSTANTS                  |
// +--------------------------------------------+

// -- What are constants --
    // Constants are values in a program that cannot change once set.
    // They help prevent mistakes and can optimize performance.
    const double gravity { 9.8 }; // must be initialized
    const int age { 3 };
    const int eggs { age };       // can be initialized from another variable

    // Tip: prefer `camelCase` (e.g., eggsCount) over `ALL_CAPS`.
    // Macros can act as constants but are not recommended.

// +--------------------------------------------+
// |                 LITERALS                   |
// +--------------------------------------------+

// -- Integer literals --
    std::cout << 5 << '\n';   // int literal
    std::cout << 5L << '\n';  // long literal
    std::cout << 5u << '\n';  // unsigned int literal

// -- Type conversions --
    int a          { 5 };
    unsigned int b { 6 };
    long c         { 7 };

// -- Floating point literals --
    float f  { 4.1f }; // float literal
    double d { 4.1 };  // double literal (default)
    
// -- Scientific notation --
    double avogadro     { 6.02e23 };   // 6.02 × 10^23
    double protonCharge { 1.6e-19 };   // 1.6 × 10^-19

// +--------------------------------------------+
// |            NUMERAL SYSTEMS (BASES)         |
// +--------------------------------------------+

// -- Integer representations --
    int dec  { 12 };             // decimal (base 10)
    int bin  { 0b1010 };         // binary (base 2)
    int bin2 { 0b1111'0000 };    // binary with digit separators
    int oct  { 012 };            // octal (base 8)
    int hex  { 0xF };            // hexadecimal (base 16)

// -- Outputting numbers in different bases --
    int example { 12 };
    std::cout << example << '\n';       // decimal
    std::cout << std::hex << example << '\n'; // hexadecimal
    std::cout << std::oct << example << '\n'; // octal
    std::cout << std::dec << example << '\n'; // back to decimal

// -- Binary output with std::bitset --
    std::bitset<8> b { 0b1100'0101 };
    std::cout << b << '\n'; // prints 11000101

// -- Binary output with std::format (C++20+) --
    std::cout << std::format("{:b}\n", 0b1010);   // prints 1010
    std::cout << std::format("{:#b}\n", 0b1010);  // prints 0b1010

// +--------------------------------------------+
// |            CONSTANT EXPRESSIONS            |
// +--------------------------------------------+

// -- constexpr variables --
    constexpr int sexy { 3 * 2 }; // evaluated at compile time = 6
    constexpr double g { 9.8 };   // known at compile time

    // const  = cannot change after initialization
    // constexpr = must be known at compile time

// -- constexpr function example --
    constexpr int maxValue(int a, int b) {
        return (a > b) ? a : b;
    }

    constexpr int result = maxValue(5, 6); // evaluated at compile time

// +--------------------------------------------+
// |                  STRINGS                   |
// +--------------------------------------------+

// -- std::string --
    std::string name { "Azrael" };
    name = "Lattice"; // dynamic memory handles larger strings
    std::cout << name << '\n';

// -- Getting input --
    std::cin >> name; // stops reading at whitespace
    std::getline(std::cin >> std::ws, name); // reads entire line

// -- Checking string length --
    std::cout << name << " has " << name.length() << " characters\n";

    // .length() returns an unsigned value
    std::cout << name << " has "
              << static_cast<int>(name.length())
              << " characters (signed)\n";

// +--------------------------------------------+
// |               STRING_VIEW                  |
// +--------------------------------------------+

// -- Passing std::string by value (bad) --
    std::string s { "Hello, World!" };
    printStringBad(s); // copies twice (inefficient)

// -- Using std::string_view (good) --
    printStringGood(s); // views string without copying

// -- Converting between std::string and std::string_view --
    std::string_view sv { "Hello" };
    std::string s1 { sv };
    std::string s2 = static_cast<std::string>(sv);

// -- Reassigning views --
    std::string realName { "Azrael" };
    std::string_view view { realName };

    std::cout << view << '\n'; // prints "Azrael"
    view = "Yes";              // now views "Yes", doesn't modify realName
    std::cout << realName << '\n'; // still "Azrael"

// -- constexpr std::string_view --
    constexpr std::string_view compileMsg { "Hello, world!" };
    std::cout << compileMsg << '\n';

// std::string_view is great for performance and safety
// Use it when you need to *view* a string, not own it.
