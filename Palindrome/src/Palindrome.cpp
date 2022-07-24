#include "Palindrome.hpp"
#include <limits.h>

bool Palindrome::isPalindrome(int x) {
  int converted = 0;
  const auto NUMBER_TEN = 10;

  // Negative number cannot be a palindrome
  if (x < 0) {
    return false;
  }

  // Form the number in reverse order
  auto original_number = x;
  while (original_number != 0) {
    auto remainder = original_number % NUMBER_TEN;

    // Make sure value is not greater than max value of
    if (converted < (INT_MAX / NUMBER_TEN)) {
      converted = converted * NUMBER_TEN + remainder;
      original_number = original_number / NUMBER_TEN;
    } else {
      return false;
    }
  }

  if (x == converted) {
    return true;
  }

  return false;
}
