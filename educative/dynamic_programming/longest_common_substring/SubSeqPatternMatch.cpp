using namespace std;

#include <iostream>
#include <string>

class SPM {
public:
  int findSPMCount(const string &str, const string &pat) {
    return findSPMCountRecursive(str, pat, 0, 0);
  }

private:
  int findSPMCountRecursive(const string &str, const string &pat, int strIndex, int patIndex) {
      if( patIndex >= pat.length())
      {
          return 1;
      }
      if(strIndex>= str.length())
          return 0;
      int c1 = 0; 
      if(str[strIndex] == pat[patIndex])
      {
          c1 = findSPMCountRecursive(str,pat,strIndex+1,patIndex+1);
      }
      int c2 = findSPMCountRecursive(str,pat,strIndex+1,patIndex);

      return c1+c2;

  }
};

int main(int argc, char *argv[]) {
  SPM *spm = new SPM();
  cout << spm->findSPMCount("baxmx", "ax") << endl;
  cout << spm->findSPMCount("tomorrow", "tor") << endl;

  delete spm;
}
