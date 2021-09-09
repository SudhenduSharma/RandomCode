
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

class ReverseLevelOrderTraversal {
 public:
   static deque<vector<int>> traverse(TreeNode *root) {
       deque<vector<int>> result = deque<vector<int>>();
       if(root->left == nullptr && root->right == nullptr)
           return deque<vector<int>>{{root->val}};
       
       queue<TreeNode*> nodes;

       nodes.push(root);
       int level = 1;
       while(!nodes.empty())
       {
           vector<int> nodesValues;
           int nodesInQueue = nodes.size();
           for(int i = 0; i < nodesInQueue; ++i)
           {
               TreeNode* node = nodes.front();
               nodesValues.push_back(node->val);
               if(node->left != nullptr)
               {
                   nodes.push(node->left);
               }
               if(node->right != nullptr)
               {
                   nodes.push(node->right);
               }
               nodes.pop();
           }
           result.push_front(nodesValues);
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
  auto result = ReverseLevelOrderTraversal::traverse(root);

  cout << "Reverse level order traversal: ";
  for (auto que : result) {
    for (auto num : que) {
      cout << num << " ";
    }
    cout << endl;
  }
}

