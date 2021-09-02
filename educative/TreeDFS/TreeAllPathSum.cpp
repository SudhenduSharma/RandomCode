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

class SumOfPathNumbers {
 public:
  static int findSumOfPathNumbers(TreeNode *root) {
      if(root==nullptr)
          return 0;
    return findSumOfPathNumbersRecursive(root,root->val);
  }
  static int findSumOfPathNumbersRecursive(TreeNode *root, int value) {
      if(root==nullptr)
          return 0;

      int sum1 = 0;
      if(root->left!= nullptr)
      {
          sum1 = 10 * value +  findSumOfPathNumbersRecursive(root->left,root->left->val);
      }
      int sum2 = 0;
      if(root->right!= nullptr)
      {
          sum2 = 10* root->val + findSumOfPathNumbersRecursive(root->right,root->right->val);
      }
      return sum1 + sum2;

  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}
