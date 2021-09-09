using namespace std;

#include <iostream>
#include <queue>

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

class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
      if(root->left == nullptr && root->right == nullptr)
          return nullptr;
      queue<TreeNode*> nodes;
      nodes.push(root);
      bool nodeFound = false;
      while(!nodes.empty())
      {
          int nodesInCurrentLevel = nodes.size();
          for(int i =0; i< nodesInCurrentLevel ; ++i)
          {
            TreeNode* node = nodes.front();
            if(nodeFound )
                return node;
            if(node->val == key)
                nodeFound = true;
            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);
            nodes.pop();
          }
      }
   return nullptr;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  TreeNode *result = LevelOrderSuccessor::findSuccessor(root, 12);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
  result = LevelOrderSuccessor::findSuccessor(root, 9);
  if (result != nullptr) {
    cout << result->val << " " << endl;
  }
}
