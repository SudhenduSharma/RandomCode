#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
 public:
  static bool findPath(TreeNode *root, const vector<int> &sequence) {
      bool res = findPathRecursive(root,sequence, 0);
    return res;
  }
  static bool findPathRecursive(TreeNode *root, const vector<int> &sequence,int currentIndex) {


      if(root == nullptr)
          return false;

      if(root->val == sequence[currentIndex] && root->left == nullptr && root->right == nullptr && currentIndex == sequence.size()-1)
          return true;

      if(root->val != sequence[currentIndex])
          return false;

      bool left = false;
      if(root->left != nullptr)
          left = findPathRecursive(root->left,sequence,currentIndex+1);
      
      bool right = false;
      if(root->right != nullptr)
          right = findPathRecursive(root->right,sequence,currentIndex+1);

      return left||right ;

  }

};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
       << endl;
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
       << endl;
}
