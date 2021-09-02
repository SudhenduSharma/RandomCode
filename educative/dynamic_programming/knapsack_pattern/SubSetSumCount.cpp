using namespace std;

#include <iostream>
#include <vector>

// divide and conquer

class SubsetSum {
public:
  int countSubsets(const vector<int> &num, int sum) {
      if(num.empty())
          return 0;
    return this->countSubsetsRecursive(num, sum, 0);
  }

public :
  int countSubsetsRecursive(const vector<int> &num,int sum, int index){

      if(sum == 0)
          return 1;
      if(index >= num.size())
          return 0;

      int count1 = countSubsetsRecursive(num,sum-num[index],index+1);
      int count2 = countSubsetsRecursive(num,sum,index+1);
      return count1+count2;

  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {1, 1, 2, 2, 3};
  cout << ss.countSubsets(num, 4) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.countSubsets(num, 9) << endl;
}

