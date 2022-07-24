#include "TreeUtils.hpp"
#include <iostream>
#include <queue>
#include <tgmath.h>

TreeNode *TreeUtils::createSubTree(const std::vector<int> &treeVector, int ind,
                                   int size, TreeNode *tree, int num) {
  // Check for size
  if (ind >= size) {
    return nullptr;
  }
  TreeNode *subtree;
  // Create root node, 0 means null node
  if (ind < size && treeVector[ind] != 0) {
    subtree = new TreeNode(treeVector[ind]);
  }

  // Create left tree
  auto add = pow(2, num);
  if ((ind + add) < size && treeVector[ind + add] != 0) {
    subtree->left = createSubTree(treeVector, ind + add, size, tree, ++num);
  }

  // Create right tree
  if ((ind + add + 1) < size && treeVector[ind + add + 1] != 0) {
    subtree->right =
        createSubTree(treeVector, ind + add + 1, size, tree, ++num);
  }

  return subtree;
}

TreeNode *TreeUtils::buildTree(const std::vector<int> &treeVector) {
  if (treeVector.empty()) {
    return nullptr;
  }

  // Use recursion to create
  TreeNode *tree = createSubTree(treeVector, 0, treeVector.size(), tree, 0);

  return tree;
}

std::vector<int> TreeUtils::rightSideView(TreeNode *root) {
  std::vector<int> rightSideView;

  if (root == nullptr) {
    return rightSideView;
  }

  // Maintain a std::queue to insert left and right of tree
  std::queue<TreeNode *> qTree;
  qTree.push(root);

  while (!qTree.empty()) {
    int size = qTree.size();
    while (size != 0) {
      TreeNode *tree = qTree.front();
      qTree.pop();
      size--;
      if (tree != nullptr) {
        if (size == 0) {
          // Print extreme right
          rightSideView.push_back(tree->val);
        }
        if (tree->left != nullptr) {
          qTree.push(tree->left);
        }
        if (tree->right != nullptr) {
          qTree.push(tree->right);
        }
      }
    }
  }

  return rightSideView;
}
