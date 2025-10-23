#include <iostream>
#include <string>

std::string askName() {
  std::string name { };

  std::cout    << "What's your name lil bro?: ";
  std::getline  ( std::cin >> std::ws, name );

  return name;
}

int askAge () {
  unsigned int age { };

  std::cout << "How old are you lil bro?: ";
  std::cin  >> age;

  return age;
}

int main() {
  std::string name1 { askName() };
  int age1 { askAge() };

  std::string name2 { askName() };
  int age2 { askAge() };

  if (age1 > age2) {
    std::cout << name1 << " is older than " << name2 << "\n";
  }

  else if (age2 > age1) {
    std::cout << name2 << " is older than " << name1 << "\n";
  }

  else {
    std::cout << "They're equal blud";
  }
}
