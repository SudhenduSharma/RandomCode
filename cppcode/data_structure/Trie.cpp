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
        isLeaf_ = false;
    }

    void insert(std::string val)
    {
        Trie *node = this;
        for(int i = 0; i< val.size();++i)
        {
            if(!childs_[val[i]-'a'])
            {
                node = node->childs_[val[i]-'a'];
            }
            else
            {
                node->childs_[val[i]-'a'] = new Trie();
                node->childs_[val[i]-'a']->val_ = val[i];
            }
        }
        node->isLeaf_ = true;
    }
    private: 
    bool isLeaf_;

        vector<Trie*> childs_;


};
