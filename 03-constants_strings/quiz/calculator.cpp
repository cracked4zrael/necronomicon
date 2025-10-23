#include <iostream>

int add(int a, int b) {
  return a + b; 
}

int subtract(int a, int b) { 
  return a - b; 
}

int divide(double a, double b) { 
  return a / b; 
}

int multiply(int a, int b) { 
  return a * b; 
}

void ask(int &x, int &y) {
  std::cout << "Enter 2 numbers\n";
  std::cin  >> x >> y;
}

int main() {

  int x { }, y { }, choice{ };

  std::cout << R"(Choose operation 
                [1] Addition
                [2] Subtraction
                [3] Divison
                [4] Multiplication: )";
  
  std::cin >> choice;

  ask(x, y);

  switch (choice)
  {
    case 1:
      std::cout << add(x, y);
      break;

    case 2:
      std::cout << subtract(x, y);
      break;

    case 3:
      if (y == 0) {
        std::cout << "u stupid lil bro?\n";
        break;
      }

      std::cout << divide(x, y);

    case 4:
      std::cout << multiply(x, y);
      break;

    default:
      std::cout << "shut your bitch ass up lil bro\n";
      break;
  } 
  
  return 0;
}
