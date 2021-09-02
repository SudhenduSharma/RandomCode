using namespace std;

#include <iostream>
#include <vector>

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class CountAllPathSum {
 public:
  static int countPaths(TreeNode *root, int S) {
    // TODO: Write your code here
    return countPathsRecursive(root,S);
  }
  static int countPathsRecursive(TreeNode *root, int S) {
      if(root == nullptr )
          return 0;
      if(root->val == S && root->left == nullptr && root->right == nullptr)
          return 1;

      int sumCurrent1 = countPathsRecursive(root->left,S-root->val);
      int sumCurrent2 = countPathsRecursive(root->right,S-root->val);

      int sumLeft = countPathsRecursive(root->left,S);
      int sumRight = countPathsRecursive(root->right,S);

      return sumCurrent1+sumCurrent2+sumLeft+sumRight;

  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}
