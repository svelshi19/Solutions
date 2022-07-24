#include "TreeNode.hpp"

class TreeUtils {

public:
  TreeNode *buildTree(const std::vector<int> &);
  std::vector<int> rightSideView(TreeNode *root);

private:
  TreeNode *createSubTree(const std::vector<int> &treeVector, int ind, int size,
                          TreeNode *tree, int);
};
