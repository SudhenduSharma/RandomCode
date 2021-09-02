using namespace std;

#include <iostream>
#include <queue>
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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if(root->left == nullptr && root->right == nullptr)
        return vector<vector<int>>{{root->val}};

    queue<TreeNode*>  nodes;
    nodes.push(root);

    bool flipOrder = true;

    while(!nodes.empty())
    {

        vector<int> nodeValues;

        int nodesInCurrentLevel = nodes.size();
        
        for(int i = 0 ; i < nodesInCurrentLevel ; ++i)
        {
            TreeNode *node = nodes.front();
            if(flipOrder)
            {
                nodeValues.push_back(node->val);
            }
            else
            {
                nodeValues.insert(nodeValues.begin(),node->val);

            }
            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);

            nodes.pop();
        }
        result.push_back(nodeValues);
        flipOrder = !flipOrder;
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}
