// This file contains test cases to test the palindrome function.

#include "Palindrome.hpp"
#include "TestUtils.hpp"
#include <iostream>

int main() {
  Palindrome palindrome;

  // Test cases
  /* Test Case 1:
     Input: 121, output: True
  */
  EXPECT_TRUE(palindrome.isPalindrome(121), "Test_121");
  std::cout << std::endl;
  
  /* Test Case 2:
     Input: -121, output: False
  */
  EXPECT_FALSE(palindrome.isPalindrome(-121), "Test_Negative121");
  std::cout << std::endl;
  
  /* Test Case 3:
     Input: 1234567899, output: False
  */
  EXPECT_FALSE(palindrome.isPalindrome(1234567899), "Test_1234567899");
  std::cout << std::endl;
  
  /* Test Case 4:
     Input: 99999, output: True
  */
  EXPECT_TRUE(palindrome.isPalindrome(99999), "Test_99999");
  std::cout << std::endl;
  
  /* Test Case 5:
     Input: 0, output: True
  */
  EXPECT_TRUE(palindrome.isPalindrome(0), "Test_0");
  std::cout << std::endl;
  
  /* Test Case 6:
     Input: 1234, output: False
  */
  EXPECT_FALSE(palindrome.isPalindrome(1234), "Test_1234");
  std::cout << std::endl;
}
