using namespace std;

#include <iostream>
#include <string>
#include <vector>

class FindCorruptNums {
 public:
     static void swap(vector<int>& nums, int i, int j)
     {
         int tmp = nums[j];
         nums[j] = nums[i];
         nums[i] = tmp;
     }
  static vector<int> findNumbers(vector<int> &nums) {
      if(nums.size() == 1)
          return vector<int>{1,nums[1]};
      int i = 0;
      while(i < nums.size())
      {
          int j  = nums[i];
          if(i == j-1 || (nums[i] == nums[j-1]))
              ++i;
          else
              swap(nums, i , j-1);
      }

      i = 0;
      for(auto c : nums)
      {
          if(c-1 != i)
              return vector<int>{i+1,c};
     ++i;
      }
    return vector<int>{-1, -1};
  }
};


int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 1, 2, 5, 2};
  //vector<int> v1 = {4, 1, 2, 5, 3};
  vector<int> nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;

  v1 = {3, 1, 2, 3, 6, 4};
  //v1 = {5, 1, 2, 3, 6, 4};
  nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;
}
