using namespace std;

#include <iostream>
#include <string>

class MPP {

public:
  int findMPPCuts(const string &st) { return this->findMPPCutsRecursive(st, 0, st.length() - 1); }

private:
  int findMPPCutsRecursive(const string &st, int startIndex, int endIndex) 
  {
      if (startIndex >= endIndex || isPalindrome(st, startIndex, endIndex)) {
         return 0;
       }
      int cutmin = endIndex - startIndex;
      if(st[startIndex] == st[endIndex])
      {
          cutmin = findMPPCutsRecursive(st,startIndex +1 ,endIndex-1);
          if(cutmin!=0)
          {
              cutmin += 2;
          }
      }
      int cutmin1 = 1 + findMPPCutsRecursive(st,startIndex+1,endIndex);
      int cutmin2 = 1 + findMPPCutsRecursive(st,startIndex,endIndex-1);
      return min(cutmin,min(cutmin1,cutmin2));
  }/*{
    // we don't need to cut the string if it is a palindrome
    if (startIndex >= endIndex || isPalindrome(st, startIndex, endIndex)) {
      return 0;
    }

    // at max, we need to cut the string into its 'length-1' pieces
    int minimumCuts = endIndex - startIndex;
    for (int i = startIndex; i <= endIndex; i++) {
      if (isPalindrome(st, startIndex, i)) {
        // we can cut here as we have a palindrome from 'startIndex' to 'i'
        minimumCuts = min(minimumCuts, 1 + findMPPCutsRecursive(st, i + 1, endIndex));
      }
    }
    return minimumCuts;
  }*/

  bool isPalindrome(const string &st, int x, int y) {
    while (x < y) {
      if (st[x++] != st[y--]) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  MPP *mpp = new MPP();
  cout << mpp->findMPPCuts("abdbca") << endl;
  cout << mpp->findMPPCuts("cdpdd") << endl;
  cout << mpp->findMPPCuts("pqr") << endl;
  cout << mpp->findMPPCuts("pp") << endl;

  delete mpp;
}
