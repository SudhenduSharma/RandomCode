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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;
    if(root->left == nullptr && root->right == nullptr)
        return vector<double>{double(root->val)};
    queue<TreeNode*> nodes;
    nodes.push(root);
    int level = 1 ;
    while(!nodes.empty())
    {
        double levelAverage = 0.0;
        int nodesInLevel = nodes.size();
        for(int i = 0;  i < nodesInLevel ; ++i)
        {   
            TreeNode* node = nodes.front();
            levelAverage += node->val;
            if(node->left != nullptr)
                nodes.push(node->left);
            if(node->right != nullptr)
                nodes.push(node->right);
            nodes.pop();
        }
        result.push_back(levelAverage/nodesInLevel);
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
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
