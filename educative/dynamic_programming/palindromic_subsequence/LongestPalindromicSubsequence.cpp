using namespace std;

#include <iostream>
#include <string>

class LPS {

public:
  int findLPSLength(const string &st) {
    return findLPSLengthRecursive(st, 0, st.length() - 1);
  }

private:
  int findLPSLengthRecursive(const string &st, int startIndex, int endIndex) {
      if(startIndex == endIndex)
          return 1;
      if(startIndex > endIndex)
          return 0;
      if(st[startIndex] == st[endIndex])
      {
          //reduce
          return 2 + findLPSLengthRecursive(st, startIndex + 1, endIndex-1) ;
      }
      int len1 = findLPSLengthRecursive(st, startIndex + 1, endIndex);
      int len2 = findLPSLengthRecursive(st, startIndex, endIndex -1);
      
      return max(len1,len2);
  }
};
int main(int argc, char *argv[]) {
  LPS *lps = new LPS();
  cout << lps->findLPSLength("abdbca") << endl;
  cout << lps->findLPSLength("cddpd") << endl;
  cout << lps->findLPSLength("pqr") << endl;

  delete lps;
}
