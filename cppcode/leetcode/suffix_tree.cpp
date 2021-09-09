#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
//https://www.sandordargo.com/blog/2019/11/06/stl-alogorithms-tutorial-part-7-transform

class Edge{
    public :
        const int INVALID = -1;
        Edge(int start,int end):mStart(start),mEnd(end){
        }
        Edge(){}
        int mStart = INVALID;
        int mEnd = INVALID; 
};

class SuffixTreeNodeT 
{
    public :
        char mNodeVal;
        std::vector<SuffixTreeNodeT*> mChildrenNodes;
        //mEdge holds the start to end index of the source node to self
        //such as Node1 --> Node2 then Node2 will hold the Edge
        Edge mEdge;
};

class SuffixTree
{
    public : 
        bool   DoesPathExists(std::string Edge);
    private :
        SuffixTreeNodeT *mRoot = 0;
};

bool  SuffixTree::DoesPathExists(std::string Edge)
{
    //TODO
    return false;
}
class Solution {

public:
    const SuffixTree& BuildSuffixTree(std::string inputStr) {

        //https://www.youtube.com/watch?v=aPRqocoBsFQ
        for( int phase = 0; phase < inputStr.size(); ++phase )
        {
            for( int extension = 0; extension <= phase; ++extension )
            {
                std::string Edge = inputStr.substr(extension, phase);

                if(mSuffixTree.DoesPathExists(Edge))
                {
                    
                }
                else
                {

                }
                std::cout << inputStr[extension];
            }
            std::cout << "\n";
        }
        return mSuffixTree;
    }
private :
    SuffixTree mSuffixTree;
};

int main(int argc, char** argv)
{
    if(!(argc > 1)) {
        std::cout<< "EXIT no input";
        return 0;
    }

    std::string input;
    std::istringstream ( argv[1] ) >> input;

    auto res = Solution().BuildSuffixTree(input);
    std::cout << "\n------\n";
    
    std::cout << "Print Suffix Tree\n";
    std::cout << "\n------\n";
    return 0;
}
