#include <iostream>

int firstStage() {
  int value1 { };

  std::cout << "Enter an integer: ";
  std::cin  >> value1;

  return value1;
}

int secondStage() { 
  int value2 { };

  std::cout << "Enter a larger integer: ";
  std::cin  >> value2;

  return value2;
}

int main() {
  int value1 { firstStage  () };
  int value2 { secondStage () };

  if (value1 > value2) {
    std::cout << "The smaller number is: " << value2 << '\n';
    std::cout << "The larger number is: "  << value1 << '\n';
  }

  else {
    std::cout << "The smaller number is: " << value1 << '\n';
    std::cout << "The larger number is: "  << value2 << '\n';
  }

  return 0;
}
