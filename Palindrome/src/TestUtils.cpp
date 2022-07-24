#include <iostream>

void EXPECT_TRUE(bool flag, const char *test) {
  if (!flag) {
    std::cout << test << " FAILED.";
  } else {
    std::cout << test << " PASSED.";
  }
}

void EXPECT_FALSE(bool flag, const char *test) {
  if (flag) {
    std::cout << test << " FAILED.";
  } else {
    std::cout << test << " PASSED.";
  }
}
