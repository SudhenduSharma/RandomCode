using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LPS {

public:
  int findLPSLength(const string &st) {
    vector<vector<int>> dp(st.length(), vector<int>(st.length(), -1));
    return findLPSLengthRecursive(dp, st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(vector<vector<int>> &dp, const string &st, int startIndex,
                             int endIndex) {
      if(startIndex > endIndex)
          return 0;
      if(startIndex == endIndex)
          return 1;
      if(dp[startIndex][endIndex] == -1)
      {
          int length1 = 0;
          if(st[startIndex] == st[endIndex]){
              //recursively find the if startIndex+1 and endIndex-1 is palindrom
              int remainingLen =  endIndex - startIndex -1 ;
              int res = findLPSLengthRecursive(dp,st,startIndex+1, endIndex-1);
              if(res == remainingLen )
              {
                  length1 = remainingLen + 2;
              }
          }
          int length2 = findLPSLengthRecursive(dp,st,startIndex+1, endIndex);
          int length3 = findLPSLengthRecursive(dp,st,startIndex, endIndex-1);
          dp[startIndex][endIndex] = max(length1,max(length2,length3));
      }

      return  dp[startIndex][endIndex];
    }

};

int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}
