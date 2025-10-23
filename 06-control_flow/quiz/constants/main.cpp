#include "constants.h"
#include <iostream>

int main() {
  int students{};

	std::cout << "How many students are in your class? ";
	std::cin  >> students;

	if (students > Constants::maxClassSize) {
    std::cout << "There are too many students in this class";
  }

	else { 
    std::cout << "This class isn't too large";
  }

	return 0;
}
