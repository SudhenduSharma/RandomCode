using namespace std;

#include <iostream>
#include <string>

class MDI {
public:
    void findMDI(const string &s1, const string &s2) {
        int c1 = findLCSLengthRecursive(s1, s2, 0, 0);
        cout << "Minimum deletions needed: " << (s1.length() - c1) << endl;
        cout << "Minimum insertions needed: " << (s2.length() - c1) << endl;
    }

private:
  int findLCSLengthRecursive(const string &s1, const string &s2, int i1, int i2) 
  {
      if(i1 >= s1.length() || i2 >= s2.length())
      {
          return 0;
      }
      int len1 = 0;
      if(s1[i1] == s2[i2])
      {
          len1 = 1 + findLCSLengthRecursive(s1,s2,i1+1,i2+1);
      }
      int len2 = findLCSLengthRecursive(s1,s2,i1,i2+1);
      int len3 = findLCSLengthRecursive(s1,s2,i1+1,i2);
      return max(len1,max(len2,len3));

  }
};
int main(int argc, char *argv[]) {
  MDI *mdi = new MDI();
  mdi->findMDI("abc", "fbc");
  mdi->findMDI("abdca", "cbda");
  mdi->findMDI("passport", "ppsspt");

  delete mdi;
}
