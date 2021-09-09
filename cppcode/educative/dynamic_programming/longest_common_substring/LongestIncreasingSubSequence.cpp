//Lecture By https://jeffe.cs.illinois.edu/
//This video explains in details about though process 
////https://echo360.org/lesson/G_3782eb5d-ce5c-41f0-bdc9-11b1b28624f2_e91d9230-df55-45bf-916a-0443232ec040_2020-01-24T15:30:00.000_2020-01-24T16:57:00.000/classroom#sortDirection=desc
using namespace std;

#include <iostream>
#include <vector>

class LIS {

public:
  int findLISLength(const vector<int> &nums) { return findLISLengthRecursive(nums, 0, -1); }

private:
  int findLISLengthRecursive(const vector<int> &nums, int currentIndex, int previousIndex) 
  {
      if(currentIndex >= nums.size())
          return 0;

      int len1 = 0;

      if(previousIndex == -1 || nums[currentIndex] >= nums[previousIndex] )
      {
          //include element in current increasing subsequence and reduce
          len1 = 1 + findLISLengthRecursive(nums, currentIndex+1, currentIndex );
      }
      int len2 = findLISLengthRecursive(nums, currentIndex+1, currentIndex );

      return max (len1,len2);

  }
};

int main(int argc, char *argv[]) {
  LIS *lis = new LIS();
  vector<int> nums = {4, 2, 3, 6, 10, 1, 12};
  cout << lis->findLISLength(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << lis->findLISLength(nums) << endl;

  delete lis;
}
