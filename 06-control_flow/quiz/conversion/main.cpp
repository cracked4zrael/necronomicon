#include <iostream>

int main() {
  int num { };

  std::cout << "Enter a positive number: ";
  std::cin  >> num;

  if (num < 0) {
    std::cout << "[!] Negative number detected: " << '\n';
    std::cout << "[+] Converted digit: " << -num << '\n';
  }

  else {
    std::cout << "[+] You entered: " << num << '\n';
  }

  return 0;
}
