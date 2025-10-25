// +--------------------------------------------+
// |               CHAPTER 5: OPERATORS         |
// +--------------------------------------------+
// Operators are mathematical or logical processes that take one or more
// inputs (operands) and produce an output value. The operator is the
// symbol that tells what operation to perform.

#include <iostream>
#include <cmath>

// +--------------------------------------------+
// |      PRECEDENCE AND ASSOCIATIVITY          |
// +--------------------------------------------+
//
// Determines how C++ decides which operation to perform first.

  int x = 7 - 4 - 1;

// Subtraction has left-to-right associativity, so the compiler groups
// it as (7 - 4) - 1.
// Reference: https://www.learncpp.com/cpp-tutorial/operator-precedence-and-associativity/

// Using parentheses to control order of operations
  int y = 4 + 2 * 3;       // C++ sees it as 4 + (2 * 3)
  int y_new = (4 + 2) * 3; // Explicitly control the order

  int a = a * b + c * d;   // This computes (a * b) + (c * d), but the compiler
// can evaluate operands in any order. Use parentheses
// to make evaluation order clear.

// +--------------------------------------------+
// |           ORDER OF EVALUATION              |
// +--------------------------------------------+

// Be careful with function calls that have side effects.
// Example: The order in which arguments are evaluated depends on the compiler.
// Clang evaluates left-to-right, while GCC does it right-to-left.
  printCalculation(getValue(), getValue(), getValue()); // Bad practice

// Best practice
  int a_val { getValue() };
  int b_val { getValue() };
  int c_val { getValue() };

// +--------------------------------------------+
// |           ARITHMETIC OPERATORS             |
// +--------------------------------------------+
//
// Operators: +, -, *, /

// -- Unary Operators --
  +x; // Returns the value of x
  -x; // Returns the negative of x

// Be careful not to confuse the unary minus with the binary subtraction operator.
  int x2 = 5 - -3;

// -- Binary Operators --
  int x1 { 3 };
  int y2 { 3 };

  std::cout << x1 + y2; // Addition
  std::cout << x1 - y2; // Subtraction
  std::cout << x1 * y2; // Multiplication
  std::cout << x1 / y2; // Division
  std::cout << x1 % y2; // Modulus (remainder of x1 divided by y2)

// Getting floating-point results from integers
  std::cout << "double / int: " << static_cast<double>(x1) / y2 << '\n';

// +--------------------------------------------+
// |     ARITHMETIC ASSIGNMENT OPERATORS        |
// +--------------------------------------------+
//
// These are shorthand for basic arithmetic combined with assignment.

  x = x + 4;
  x += 4;

  x = x - 4;
  x -= 4;

  x = x * 4;
  x *= 4;

  x = x / 4;
  x /= 4;

  x = x % 4;
  x %= 4;

// +--------------------------------------------+
// |    MODIFYING AND NON-MODIFYING OPERATORS   |
// +--------------------------------------------+
//
// Main modifying operators:
// - Assignment operators: =, +=, etc.
// - Bitwise assignment operators: <<=, >>=, &=, |=, ^=
// - Increment/decrement operators: ++ and --

// +--------------------------------------------+
// |     REMAINDER AND EXPONENTIATION           |
// +--------------------------------------------+

  int a_in {}, b_in {};

  std::cout << "Enter an integer: ";
  std::cin >> a_in;

  std::cout << "Enter another integer: ";
  std::cin >> b_in;

// Uses the % (modulo) operator to check the remainder and divisibility
  std::cout << "The remainder is: " << a_in % b_in << '\n';

// Check if evenly divisible
  if ((a_in % b_in) == 0) {
    std::cout << a_in << " is evenly divisible by " << b_in << '\n';
  } else {
    std::cout << a_in << " isn't evenly divisible by " << b_in << '\n';
  }

// The ^ operator is bitwise XOR, not exponentiation.
// To raise numbers to a power, use pow() from <cmath>.
  double result = std::pow(3.0, 4.0); // 3 to the 4th power

// +--------------------------------------------+
// |     INCREMENT AND DECREMENT OPERATORS      |
// +--------------------------------------------+
//
// ++ and -- are used to quickly add or subtract 1 from a variable.
// Prefix updates before use, postfix updates after.

  int value { 3 };

// Prefix Increment (++value)
  int result1 = ++value; // Increments first, returns new value (4)

// Prefix Decrement (--value)
  int result2 = --value; // Decrements first, returns new value (3)

// Postfix Increment (value++)
  int result3 = value++; // Returns old value (3), increments after

// Postfix Decrement (value--)
  int result4 = value--; // Returns old value (4), decrements after

// Final results
// value   = 3
// result1 = 4
// result2 = 3
// result3 = 3
// result4 = 4

// Tip: Prefer prefix — it's faster and clearer.

// +--------------------------------------------+
// |              COMMA OPERATOR                |
// +--------------------------------------------+

  std::cout << (++x, ++y) << '\n'; // Returns the value of the right operand.

// Rarely used as an operator — more common as a separator, e.g. in for-loops.
  for (int val = 1; val <= 5; val++) {
    std::cout << "Hello\n";
  }

// +--------------------------------------------+
// |           CONDITIONAL OPERATOR             |
// +--------------------------------------------+
//
// ?: is a shorthand for choosing between two expressions.
// Syntax: condition ? expression1 : expression2

  int max = (x > y) ? x : y;

// Equivalent to:
  if (x > y)
    max = x;
  else
    max = y;

// Personal preference: traditional if-else is clearer,
// but ternary is great inside expressions.

  constexpr bool inBigClassroom { false };
  constexpr int classSize { inBigClassroom ? 30 : 20 };

// Be careful with precedence — always use parentheses.
  int z { 10 - (x > y ? x : y) };

  std::cout << ((x < 0) ? "negative" : "non-negative");

// The second and third operands must be the same type or convertible.
  std::cout << (true ? 1 : 2) << '\n';    // OK: both int
  std::cout << (false ? 1 : 2.2) << '\n'; // OK: int -> double
  std::cout << (true ? -1 : 2u) << '\n';  // Risky: -1 converts to unsigned

// If no common type is found, you'll get a compile error.
  constexpr int x_const { 5 };
// std::cout << ((x_const != 5) ? x_const : "x is 5"); // error
  std::cout << ((x_const != 5)
                  ? std::to_string(x_const)
                  : std::string{"x is 5"});

// +--------------------------------------------+
// |           RELATIONAL OPERATORS             |
// +--------------------------------------------+
//
// Used to compare values: ==, !=, >, <, >=, <=

  int u, g;

  std::cout << "Enter two integers: ";
  std::cin >> u >> g;

  if (u == g)
    std::cout << u << " equals " << g << '\n';
  else if (u != g)
    std::cout << u << " is not equal to " << g << '\n';
  else if (u > g)
    std::cout << u << " is greater than " << g << '\n';
  else if (u < g)
    std::cout << u << " is less than " << g << '\n';
  else if (u >= g)
    std::cout << u << " is greater than or equal to " << g << '\n';
  else if (u <= g)
    std::cout << u << " is less than or equal to " << g << '\n';

// Tip: you don't need to write `if (condition == true)`.
// Just use `if (condition)` or `if (!condition)`.

// +--------------------------------------------+
// |             LOGICAL OPERATORS              |
// +--------------------------------------------+

  if (!(x > y))                   // If x is not greater than y
  if (value == 0 || value == 1)   // If value is 0 or 1
  if ((value1 && value2) || (value3 && value4)) // (v1 AND v2) OR (v3 AND v4)
