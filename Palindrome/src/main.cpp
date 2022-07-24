#include "Palindrome.hpp"
#include "TestUtils.hpp"
#include <iostream>

int main() {
  Palindrome palindrome;

  // Test cases
  EXPECT_TRUE(palindrome.isPalindrome(121), "Test_121");
  std::cout << std::endl;
  EXPECT_FALSE(palindrome.isPalindrome(-121), "Test_Negative121");
  std::cout << std::endl;
  EXPECT_FALSE(palindrome.isPalindrome(1234567899), "Test_1234567899");
  std::cout << std::endl;
  EXPECT_TRUE(palindrome.isPalindrome(99999), "Test_99999");
  std::cout << std::endl;
  EXPECT_TRUE(palindrome.isPalindrome(0), "Test_0");
  std::cout << std::endl;
  EXPECT_FALSE(palindrome.isPalindrome(1234), "Test_1234");
  std::cout << std::endl;
}
