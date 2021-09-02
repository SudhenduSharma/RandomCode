#include <vector>
#include <iostream>

class Solution {
public:
   bool canWinNimTest(int n) {
       if(n%4 == 0)
               return false;
       return true;

   }
    
    bool canWinNim(int n) {
        
        std::vector<int> resultMemorized(n+1,-1);

        return canWinNimDP(n,resultMemorized);

    }
    bool canWinNimDP(int n , std::vector<int> &resultMemorized ) {
        if(n==0 || n == 1 || n == 2 || n==3)
        {
            resultMemorized[n-1] = true;
            return true;
        }
        if(-1  != resultMemorized[n-1])
        {
            static int count = 0;
            ++count;
            std::cout << "count " << count << "\n";
            return resultMemorized[n-1];
        }
        
        if(canWinNim(n-1) && canWinNim(n-2) && canWinNim(n-3))
        {
            resultMemorized[n-1] = false;          
            return resultMemorized[n-1];
        }
        
        resultMemorized[n-1] = true;
        return resultMemorized[n-1];
       
    }
};

int main()
{
    for(int val = 0 ; val < 100; ++val)
    {
        if ( Solution().canWinNim(val) == Solution().canWinNimTest(val))
        {
            std::cout << "TRUE\n";
        }
        else
        {
            std::cout << val << " FALSE \n";

        }
    }
    return 0;
}
