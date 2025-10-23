#include <iostream>

int accumulate(int number) {
  static bool alreadyran { false };
  static int  total      { 0 };

  if (!alreadyran) {
    alreadyran = true;
    total = number; 
    return total;
  } 

  // total = total + number 
  total += number;
  return total;
}

int main() {
    std::cout << accumulate(4) << '\n'; // prints 4
    std::cout << accumulate(3) << '\n'; // prints 7
    std::cout << accumulate(2) << '\n'; // prints 9
    std::cout << accumulate(1) << '\n'; // prints 10

    return 0;
}
