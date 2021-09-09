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

class TreeDiameter {
 public:
  static int findDiameter(TreeNode *root) {
    int treeDiameter = 0;
    findDiameterRecursive(root,treeDiameter);
    return treeDiameter;
  }
  static int findDiameterRecursive(TreeNode *node, int& treeDiameter){
      if(node == nullptr)
      {
          return 0;
      }
      int leftDepth = 0;
      if(node->left!= nullptr)
          leftDepth = 1 + findDiameterRecursive(node->left,treeDiameter);
      int rightDepth = 0;
      if(node->right!= nullptr)
          rightDepth = 1 + findDiameterRecursive(node->right,treeDiameter);
      int nodeDiameter = leftDepth+rightDepth+1;
      treeDiameter = max(treeDiameter,nodeDiameter);
      return max(leftDepth,rightDepth);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree treeDiameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree treeDiameter: " << TreeDiameter::findDiameter(root) << endl;
}
