using namespace std;

#include <iostream>
#include <string>

class SCS {

public:
  int findSCSLength(const string &s1, const string &s2) {
    return findSCSLengthRecursive(s1, s2, 0, 0);
  }

private:
  int findSCSLengthRecursive(const string &s1, const string &s2, int i1, int i2) 
  {
      //base condition TBD
      if(i1 >= s1.length())
      {
          return s2.length() - i2;
      }

      if(i2 >= s2.length())
      {
          return s1.length() - i1;
      }
      if(s1[i1] == s2[i2])
      {
        return 1 + findSCSLengthRecursive(s1,s2,i1+1, i2+1);
      }
      int len2 = 1 + findSCSLengthRecursive(s1,s2,i1,i2+1);
      int len3 = 1 + findSCSLengthRecursive(s1,s2,i1+1,i2);
      return min(len2,len3);
  }
};

int main(int argc, char *argv[]) {
  SCS *scs = new SCS();
  cout << scs->findSCSLength("abcf", "bdcf") << endl;
  cout << scs->findSCSLength("dynamic", "programming") << endl;

  delete scs;
}
