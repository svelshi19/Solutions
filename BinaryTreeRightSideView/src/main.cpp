#include "TreeUtils.hpp"
#include <iostream>
#include <vector>

void test(const std::vector<int> &treeVector, const std::vector<int> &expected,
          int number) {
  TreeUtils treeUtils;
  TreeNode *tree = treeUtils.buildTree(treeVector);
  std::vector<int> actual = treeUtils.rightSideView(tree);
  if (actual == expected) {
    std::cout << "Test " << number << " passed." << std::endl;
  } else {
    std::cout << "Test " << number << " failed." << std::endl;
    for (auto a : actual)
      std::cout << a;
  }
  std::cout << std::endl;
}

int main() {

  // 0 in vector means null node
  std::cout << "Running 4 test cases." << std::endl;

  // Test 1
  std::vector<int> treeVector1{1, 2, 3, 0, 5, 0, 4};
  // std::vector expected
  std::vector<int> expected1{1, 3, 4};
  test(treeVector1, expected1, 1);

  // Test 2
  std::vector<int> treeVector2{1, 0, 3};
  // std::vector expected
  std::vector<int> expected2{1, 3};
  test(treeVector2, expected2, 2);

  // Test 3
  std::vector<int> treeVector3{1, 2};
  // std::vector expected
  std::vector<int> expected3{1, 2};
  test(treeVector3, expected3, 3);

  // Test 4
  std::vector<int> treeVector4{};
  // std::vector expected
  std::vector<int> expected4{};
  test(treeVector4, expected4, 4);
}
