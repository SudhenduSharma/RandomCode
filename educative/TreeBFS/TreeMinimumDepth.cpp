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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int minimumTreeDepth = 0;
    if(!root)
        return minimumTreeDepth;
    queue<TreeNode*> nodes;
    nodes.push(root);

    minimumTreeDepth++;
    
    while(!nodes.empty())
    {
        int nodesInLevel = nodes.size();
        for(int i = 0; i < nodesInLevel; ++i)
        {
            TreeNode *node = nodes.front();
            if(node->left == nullptr)
                return minimumTreeDepth;
            else
                nodes.push(node->left);
            if(node->left == nullptr)
                return minimumTreeDepth;
            else
                nodes.push(node->right);
            
            nodes.pop();
        }
        minimumTreeDepth++;
    }
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}
