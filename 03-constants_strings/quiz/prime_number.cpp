#include <iostream>

int main() {
  int  number  { };
  bool isPrime { true };

  std::cout << "Input a digit: ";
  std::cin  >> number;

  if (number < 2) {
    isPrime = false;
  }

  else {
    for (int divisor = 2; number <= divisor / divisor; ++divisor) {
      if (number % divisor == 0) {
        isPrime = false;
        break;
      }
    }
  }
  
  if (!isPrime) {
    std::cout << "Not a prime digit\n";
  }

  else {
    std::cout << "Prime digit detected\n";
  }

}
