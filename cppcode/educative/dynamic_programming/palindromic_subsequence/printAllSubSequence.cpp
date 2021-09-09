#include<iostream>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

class Solution
{
    public :
    void printSubsequence(vector<char>& str)
    {

        vector<char> subarray;
        printSubsequenceiRecursive(str,subarray,0);
        
    }
    private :
    void printSubsequenceiRecursive( vector<char> str,vector<char> subarray,int index)
    {
       if( index == str.size())
        {
            //if(subarray.size())
            {
                for(auto c:subarray)
                    cout <<  c ;
                cout <<  endl ;
            }
            return ;
        }
        //exclude index
        printSubsequenceiRecursive(str,subarray,index+1);
        //exclude index
        subarray.push_back(str[index]);
        printSubsequenceiRecursive(str,subarray,index+1);
        return;
    }


};
int main()
{

    vector<char> str = {'a','p','p','l','e'};
    Solution().printSubsequence(str);
    return 0;

}
