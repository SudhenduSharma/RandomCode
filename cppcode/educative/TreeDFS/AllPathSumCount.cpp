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

class FindAllTreePaths {
 public:
  static vector<vector<int>> findPaths(TreeNode *root, int sum) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;
    findPathsRecurse(root,sum,allPaths,currentPath);
    
    return allPaths;
  }
  static void findPathsRecurse(TreeNode *node, int sum,vector<vector<int>>& allPaths, vector<int>& currentPath) {

      if(node == nullptr)
          return;
      currentPath.push_back(node->val);
      if(node->left == nullptr and node->right == nullptr and node->val == sum)
      {
          //path found
          allPaths.push_back(currentPath);
      }
      findPathsRecurse( node->left,sum - node->val , allPaths,currentPath);
      findPathsRecurse( node->right,sum - node->val , allPaths,currentPath);
      currentPath.pop_back();
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
