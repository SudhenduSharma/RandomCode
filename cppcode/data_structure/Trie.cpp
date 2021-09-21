#include<iostream>
#include<vector>
using namespace std;

class Trie
{
    public :
        const int char_size = 26;
        char val_;
        Trie()
        {
            childs_.reserve(char_size);
            childs_ = {nullptr};
            isLeaf_ = false;
        }

        void insert(std::string val)
        {
            Trie *node = this;
            for(int i = 0; i< val.size();++i)
            {
                if(childs_[val[i]-'a'] == nullptr)
                {
                    node->childs_[val[i]-'a'] = new Trie();
                    node->childs_[val[i]-'a']->val_ = val[i];
                }
                node = node->childs_[val[i]-'a'];
            }
            node->isLeaf_ = true;
        }

        void Print(Trie* root,std::string &val)
        {
            if(root == nullptr)
            {
                return;
            }
            val.push_back(root->val_);

            if(root->isLeaf_)
               cout << val << endl;

            for(int i = 0; i < char_size;++i)
            {
               Print(root->childs_[i],val);
            }
            val.pop_back();
        }
    private: 
        bool isLeaf_;
        vector<Trie*> childs_;
};
int main ()
{
    auto trPtr = new Trie();
    trPtr->insert("hello");
    string val;
    trPtr->Print(trPtr , val);
    trPtr->insert("help");
    val = {};
    trPtr->Print(trPtr , val);
    trPtr->insert("hell");
    val = {};
    trPtr->Print(trPtr , val);
}
