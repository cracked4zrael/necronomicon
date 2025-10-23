// +--------------------------------------------+
// |           HEADER GUARDS & ODR              |
// +--------------------------------------------+
//
// The One Definition Rule (ODR) states that every variable, function,
// or class can only have one definition across the entire program.
// Duplicating definitions (even in separate files) breaks this rule.
//
// Example:
//   int x;
//   int x; // ❌ violates ODR
//
// To prevent multiple inclusions of the same header file, 
// we use *header guards* or the modern shortcut `#pragma once`.
//

#ifndef ADD_H       // Check if ADD_H has already been defined
#define ADD_H       // Define ADD_H if it hasn’t been defined yet

// -- Function Declarations --
int add(int x, int y); // Function prototype

#endif // ADD_H

// #pragma once  // Modern shortcut — replaces the entire header guard block
