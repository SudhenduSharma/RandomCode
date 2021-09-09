using namespace std;

#include <iostream>
#include <string>

class SI {

public:
  bool findSI(const string &m, const string &n, const string &p) {

    /*for(int pi =0; pi< p.length();++pi)
    {

    }*/
    return findSIRecursive(m, n, p, 0, 0, 0);
  }

private:
  bool findSIRecursive(const string &m, const string &n, const string &p, int mIndex, int nIndex,
          int pIndex) {
      if(mIndex == m.length() && nIndex == n.length() && pIndex == p.length())
      {
          return true;
      }
      if(pIndex == p.length())
          return false;
      bool res1 = false;
      if(mIndex <  m.length() && m[mIndex] == p[pIndex])
      {
          res1 = findSIRecursive(m,n,p,mIndex+1,nIndex,pIndex+1);
      }
      bool res2 = false;
      if(nIndex <  n.length() && n[nIndex] == p[pIndex])
      {
          res2 = findSIRecursive(m,n,p,mIndex,nIndex + 1 , pIndex+1);
      }
      return res1||res2;
  }
};

int main(int argc, char *argv[]) {
  SI *si = new SI();
  cout << si->findSI("abd", "cef", "abcdef") << endl;
  cout << si->findSI("abd", "cef", "adcbef") << endl;
  cout << si->findSI("abc", "def", "abdccf") << endl;
  cout << si->findSI("abcdef", "mnop", "mnaobcdepf") << endl;

  delete si;
}
