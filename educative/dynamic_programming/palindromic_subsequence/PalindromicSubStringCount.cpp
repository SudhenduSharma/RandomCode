using namespace std;

#include <iostream>
#include <string>
#include <vector>

class CPS {
public:


public:
  int findCPS(const string &st) {
    int count = 0;
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
    int res = CountPalindromicSubStringTopDown(dp, st, 0, st.length() - 1);
    cout << " string is -> "  << st  << endl;
    for(auto r : dp)
    {
        for(auto c : r)
        {
            if(c != -1)
                ++count;
            cout << " " << c << " ";
        }
        cout <<endl;
    }
    return count;
  }

  int isPalindrom( const string &st, int startIndex, int endIndex)
  {
      while(startIndex <= endIndex && st[startIndex] == st[endIndex])
      {
          startIndex++;
          endIndex--;
      }
      if(startIndex > endIndex)
          return 1;
      return -1;
  }
private:
  int CountPalindromicSubStringTopDown(vector<vector<int>> &dp, const string &st, int startIndex, int endIndex) {
      if(startIndex > endIndex)
          return -1;
      if(dp[startIndex][endIndex] == -1)
      {
          //recursively find the if startIndex+1 and endIndex-1 is palindrom
          if(isPalindrom(st,startIndex, endIndex) == 1 )
              dp[startIndex][endIndex]  = 1;
          if(CountPalindromicSubStringTopDown(dp,st,startIndex+1, endIndex) == 1 )
              dp[startIndex+1][endIndex]  = 1;
          if(CountPalindromicSubStringTopDown(dp,st,startIndex, endIndex-1) == 1)
              dp[startIndex][endIndex-1]  = 1;
      }
      return  dp[startIndex][endIndex];
    }
};

int main(int argc, char *argv[]) {
  CPS *cps = new CPS();
  cout << cps->findCPS("abdbca") << endl;
  cout << cps->findCPS("cdpdd") << endl;
  cout << cps->findCPS("pqr") << endl;

  delete cps;
}

