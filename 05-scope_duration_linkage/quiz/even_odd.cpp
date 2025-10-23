#include <iostream>

bool isEven(int value) {
  return (value % 2 == 0);
}

int main() {
  int value { };
  
  std::cout << "Enter an integer: ";
  std::cin  >> value;

  if ( isEven (value) ) {
    std::cout << value << " is even" << "\n";
  }

  else {
    std::cout << value << " is odd" << "\n";
  }

}
