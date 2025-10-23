#include <iostream>

// Write the function getQuantityPhrase() here
std::string_view getQuantityPhrase(unsigned int numApples) {
  if (numApples < 0) {
    return "negative";
  }
  
  else if (numApples == 0) {
    return "no";
  }

  else if (numApples == 1) {
    return "a single";
  }

  else if (numApples == 2) {
    return "a couple of";
  }

  else if (numApples == 3) {
    return "a few";
  }

  else if (numApples > 3) {
    return "many";
  }

  else {
    return "sybau";
  }
}

// Write the function getApplesPluralized() here
std::string_view getApplesPluralized(int maryApples) {
  if (maryApples == 1) {
    return "apple";
  } 

  return "apples";
} 

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}
