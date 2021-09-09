
#include <iostream>
#include <queue>

using namespace std;
class TreeNode {
 public:

  int val = 0;
  TreeNode *left ;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if(root == 0)
        return result;
    queue<TreeNode*> nodesToBeVisited;
    nodesToBeVisited.push(root);
    int level = 1;
    while(!nodesToBeVisited.empty())
    {
        vector<int> treeNodeValues;
        int nodesInCurrentLevel = nodesToBeVisited.size();

        cout<< " Level " << level << " nodesInCurrentLevel " <<nodesInCurrentLevel  << endl;
        for(int i = 0; i < nodesInCurrentLevel; i++)
        {
            TreeNode* node = nodesToBeVisited.front();
            treeNodeValues.push_back(node->val);
            if(node->left != nullptr)
            {
                nodesToBeVisited.push(node->left);
            }
            if(node->right != nullptr)
            {
                nodesToBeVisited.push(node->right);
            }   
            //cout<< " Level " << level << " popping node# " << i  << endl;
            nodesToBeVisited.pop();
        }
        result.push_back(treeNodeValues);
        ++level;
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
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}
