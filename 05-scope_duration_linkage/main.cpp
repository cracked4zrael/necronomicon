// +--------------------------------------------+
// |     CHAPTER 6: SCOPE, DURATION, LINKAGE    |
// +--------------------------------------------+

#include <iostream>

// +--------------------------------------------+
// |              GLOBAL VARIABLES              |
// +--------------------------------------------+

// Global variables: variables that exist outside any functions
int g;             // Zero-initialized
int g_x { };       // Value-initialized
int g_x_z { 0 };   // Explicitly initialized

// +--------------------------------------------+
// |             INTERNAL LINKAGE               |
// +--------------------------------------------+

// Internal linkage: keeps global variables or functions visible only within a single source file

static int priv { };     // Internal global variable
const int zz { };        // Internal global constant (const and constexpr have internal linkage by default)
constexpr int ye { };    // Internal global constexpr

// -- Internal linkage for functions --
// [add.cpp]: Use 'static' to make it callable only within the file itself
static int add(int x, int y) {
  return x + y;
}

// Modern approach: instead of using 'static', C++ prefers unnamed namespaces
namespace {
  int hiddenVar { 5 };
}

// +--------------------------------------------+
// |             EXTERNAL LINKAGE               |
// +--------------------------------------------+

// External linkage allows identifiers (variables or functions) to be accessed across multiple files

// -- Functions have external linkage by default --
void sayHi() {
  std::cout << "Hi!\n";
}

// You can call this in another main2.cpp by using a forward declaration, then calling sayHi().

// -- Global variables with external linkage --
// Non-const globals have external linkage by default.
// Const/constexpr is the opposite but can be explicitly made external using 'extern'.

// [add.cpp]
extern const int no { 3 };
extern constexpr int banana { 3 };

// To use this in another file, you must forward declare it in main.cpp.
// Note: Don't use 'extern' with a non-const global variable.
// 'constexpr' cannot be forward declared; use 'const' instead.
// Best practice: avoid global variables altogether — if necessary, place them inside namespaces.

namespace Gyat {
  int g_x { };           // Global variable inside a namespace to avoid name collisions
  const int g_y { };     // Constant global variable (prefer constants to prevent UB)
  constexpr int g_z { }; // Compile-time constant global variable
}


constexpr bool g_firstCall { true };

// -- Function demonstrating parameter-based state control --
int getInteger(bool bFirstCall) {
  int i { };

  if (bFirstCall)
    std::cout << "Enter an integer: ";
  else
    std::cout << "Enter another integer: ";

  std::cin >> i;
  return i;
}

// -- Passing state as parameters --
  int a { getInteger(g_firstCall) };
  int b { getInteger(!g_firstCall) };

// +--------------------------------------------+
// |                 NAMESPACES                 |
// +--------------------------------------------+

// Namespaces help avoid naming collisions.
// Each function lives in its own "box", preventing overlap.

namespace Foo {
  int doSomething(int x, int y) { return x + y; }
}

namespace Goo {
  int doSomething(int x, int y) { return x - y; }
}

  std::cout << Foo::doSomething(4, 3) << '\n';
  std::cout << Goo::doSomething(4, 3) << '\n';
  ::print(); // Refers to the global namespace

// -- Forward Declarations inside namespaces --
  /*
    [add.h]
      namespace BasicMath {
        int add(int x, int y);
      }

    [add.cpp]
      namespace BasicMath {
        int add(int x, int y) { return x + y; }
      }
  */

// -- Multiple namespace blocks --
// You can define a namespace in several places; all declarations are combined.
// [circle.h]
//   namespace BasicMath { constexpr double pi = 3.14; }
//
// [growth.h]
//   namespace BasicMath { constexpr double e = 2.7; }

// -- Nested Namespaces --
// Namespaces can live inside other namespaces
  namespace Foo::Goo {
    int subtract(int x, int y) { return x - y; }
  }

  std::cout << Foo::Goo::subtract(1, 2) << '\n';

// Namespace aliases
  namespace Yeah = Foo::Goo;
  std::cout << Yeah::subtract(1, 2) << '\n';

// +--------------------------------------------+
// |            LOCAL VARIABLES                 |
// +--------------------------------------------+

// Local variables are created inside functions.
// They are destroyed once the function or block ends.
// They also have no linkage.

  {
    int yeah { 5 };
  } // Destroyed after this block

// +--------------------------------------------+
// |         STATIC LOCAL VARIABLES             |
// +--------------------------------------------+

// If you want a variable inside a function to keep its value even after the function ends,
// use static local variables (their lifetime lasts until the program ends).

  static int s_value { 1 }; // Created once and persists between function calls
// Best practice: always initialize static locals explicitly.

// -- Static Local Constants --
// Useful when creating a value is expensive (e.g., loading from a file or database)
// and you only want to do it once.
  const static int importantKey { 32 }; // Created once and reused in all future calls

// Refer to the getInteger() function for paramter-based state control using static variable

  /* Best Practices:
   * Prefer const static locals when possible.
   * Avoid non-constant static locals unless the variable should never be reset.
   * Use the 's_' prefix to mark static local variables.
   */

// +--------------------------------------------+
// |                   SCOPE                    |
// +--------------------------------------------+

// -- Block (Local) Scope --
  int x { 5 }; // Local variable inside main
  {
    int y { 10 };
    std::cout << "y: " << y << '\n'; // Accessible here
  }
// std::cout << y; // ERROR: y is out of scope here

// -- Global Scope --
  int globalVar { 100 }; // Global variable accessible anywhere in the file
  std::cout << "Global Var: " << globalVar << '\n';

// +--------------------------------------------+
// |                 DURATION                   |
// +--------------------------------------------+

// -- Automatic Duration (local variables and parameters) --
  {
    int temp { 5 }; // Created on block entry
  } // Destroyed here

// -- Static Duration (globals and static locals) --
  static int staticVar { 10 }; // Keeps value between calls

// -- Dynamic Duration (manual using new/delete) --
  int* dynamicVar = new int(20);
  std::cout << "Dynamic Var: " << *dynamicVar << '\n';
  delete dynamicVar;

// +--------------------------------------------+
// |                 LINKAGE                    |
// +--------------------------------------------+

// -- No Linkage --
  {
    int localVar { 42 };
    std::cout << "Local Var: " << localVar << '\n';
  }
// std::cout << localVar; // ERROR: out of scope

// -- Internal Linkage --
  static int internalVar { 50 }; // Visible only in this file

// -- External Linkage --
  extern int externalVar; // Declaration for variable defined elsewhere
  std::cout << "External Var: " << externalVar << '\n';

// +--------------------------------------------+
// |       STORAGE CLASS SPECIFIERS             |
// +--------------------------------------------+

// static       → persists between function calls
// extern       → declared elsewhere
// thread_local → each thread gets its own instance

extern int globalVar;
std::cout << "Global Var Extern: " << globalVar << '\n';

// +--------------------------------------------+
// |          FORWARD DECLARATIONS              |
// +--------------------------------------------+

// -- Forward declaration of functions --
extern void forwardDeclaredFunction();
forwardDeclaredFunction();

// -- Forward declaration of variables --
extern int declaredVar;

// +--------------------------------------------+
// |          INLINE NAMESPACES & ALIASES       |
// +--------------------------------------------+

using int_vec = std::vector<int>; // Type alias

// Inline namespaces: used for versioning without breaking existing code
inline namespace V1 {
  void doSomething() {
    std::cout << "V1\n";
  }
}

namespace V2 {
  void doSomething() {
    std::cout << "V2\n";
  }
}

V1::doSomething(); // V1
V2::doSomething(); // V2
doSomething();     // V1 (default version)

