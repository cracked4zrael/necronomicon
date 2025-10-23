#include <iostream>

int main() {
  char character;

  std::cout << "?: ";
  std::cin  >> character;

  std::cout << "User input: " << character << " ASCII Code Representation: " << static_cast<int>(character) << '\n';

  return 0;
}
