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
            int totalPathsSum = findSumOfPathNumbersRecursive(root,0);
            return totalPathsSum;
        }

        static int findSumOfPathNumbersRecursive(TreeNode *root,int totalPathsSum) {
            if(root == nullptr)
              return 0;
            int nodeSum = totalPathsSum*10 + root->val;
            if(root->left == nullptr && root->right == nullptr)
                return nodeSum;
            int sum1 = 0,sum2 = 0;
            if(root->left != nullptr)
                sum1 = findSumOfPathNumbersRecursive(root->left,nodeSum);
            if(root->right != nullptr)
                sum2 = findSumOfPathNumbersRecursive(root->right,nodeSum);
            return sum1+sum2;
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
