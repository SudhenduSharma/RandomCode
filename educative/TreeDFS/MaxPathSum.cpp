#include <iostream>
#include <limits>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MaximumPathSum {
 public:
  static int findMaximumPathSum(TreeNode *root) {
    int maxPathSum = 0;
    findMaximumPathSumRecursive(root,maxPathSum);
    return maxPathSum;
  }
  static int findMaximumPathSumRecursive(TreeNode *root, int& maxPathSum) {
    if(root == nullptr)
        return 0;
    int leftPathSum = findMaximumPathSumRecursive(root->left,maxPathSum);
    int rightPathSum = findMaximumPathSumRecursive(root->right,maxPathSum);
    int nodePathSum = leftPathSum + rightPathSum + root->val;
    //cout << " nodePathSum " << nodePathSum << " maxPathSum " << maxPathSum << endl;
    maxPathSum = max(nodePathSum,maxPathSum);
    return max(leftPathSum,rightPathSum)+root->val;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}
