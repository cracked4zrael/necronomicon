// +--------------------------------------------+
// |               DATA TYPES                   |
// +--------------------------------------------+
//
// Data types define what kind of data a variable can hold.
// They differ in size, range, and how they are stored in memory.

#include <iostream>
#include <cstdint> // for fixed-width integer types (int32_t, etc.)
#include <cstddef> // for std::size_t

// -- Fundamental Types --
//
// Floating point:  float, double, long double   (e.g. 3.14)
// Boolean:         true, false
// Character:       char, wchar_t, char8_t, char16_t, char32_t   (e.g. 'c')
// Integer:         short, int, long, long long   (e.g. 64)
// Void:            represents no type
// Null pointer:    std::nullptr_t

// +--------------------------------------------+
// |            FUNCTION EXAMPLES               |
// +--------------------------------------------+

void writeValue(int x) {
  std::cout << "The value of x is: " << x << '\n';
}

bool isEqual(int x, int y) {
  return x == y; // returns true if x and y are equal
}

// -- Conditional Statements Example --
int conditionalFunction() {
  int x{};
  std::cout << "Enter an integer: ";
  std::cin >> x;

  if (x > 0)
    std::cout << "The value is positive\n";
  else if (x < 0)
    std::cout << "The value is negative\n";
  else
    std::cout << "The value is zero\n";

  return 0;
}

// -- Boolean Return Example --
int booleanFunction() {
  int x{};
  int y{};

  std::cout << "Enter two integers: ";
  std::cin >> x >> y;

  std::cout << std::boolalpha; // prints true/false instead of 1/0
  std::cout << x << " and " << y << " are equal? ";
  std::cout << isEqual(x, y) << '\n';

  return 0;
}

// -- Working with Characters --
int chars() {
  char ch1{ 'a' };
  std::cout << ch1 << '\n'; // prints 'a'
  
  char userCharacter{};
  std::cout << "Input a keyboard character: ";
  std::cin >> userCharacter;

  // Note: std::cin ignores spaces, tabs, and newlines.
  // To read whitespace, use std::cin.get(userCharacter).
  return 0;
}

// -- Comparing Two Integers --
int conditionalFunction2() {
  int x{};
  int y{};

  std::cout << "Enter an integer: ";
  std::cin >> x;

  std::cout << "Enter another integer: ";
  std::cin >> y;

  if (isEqual(x, y))
    std::cout << x << " and " << y << " are equal\n";
  else
    std::cout << x << " and " << y << " are not equal\n";

  return 0;
}


// -- Measuring Sizes --
  int x{};
  std::cout << "bool: " << sizeof(bool) << " bytes\n";
  std::cout << "x is: " << sizeof(x) << " bytes\n";

// -- Signed and Unsigned Integers --
  int a{ -3 };
  int b{ 3 };

// Unsigned: non-negative only. 
// Prefer signed unless doing bit-level or low-level operations.
  unsigned short us{};
  unsigned int ui{};
  unsigned long ul{};
  unsigned long long ull{};

// -- Fixed-width Integers (from <cstdint>) --
  std::int32_t fixed{ 32767 };    // always 32 bits
  std::int_fast16_t fast{ 3 };    // fastest at least 16-bit type
  std::int_least16_t least{ 4 };  // smallest type with at least 16 bits

// -- Size Type (from <cstddef>) --
  std::size_t sizeOfX{ sizeof(x) };
  std::cout << "Size of x: " << sizeOfX << " bytes\n";

// -- Booleans --
  bool b1{ true };
  bool b2{ false };
  b1 = false;

  std::cout << true << '\n';  // prints 1
  std::cout << false << '\n'; // prints 0

  std::cout << std::boolalpha; // print "true"/"false"
  std::cout << true << '\n';

  bool choice{};
  std::cout << "Enter a boolean value (true/false): ";
  std::cin >> std::boolalpha >> choice;
  std::cout << "You entered: " << choice << '\n';

  booleanFunction();

// -- Conditional Example --
  if (0 == 0)
    std::cout << "0 is indeed equal to 0\n";
  else if (0 > 0)
    std::cout << "0 is larger than 0\n";
  else
    std::cout << "undefined\n";

