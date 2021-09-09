using namespace std;

#include <iostream>
#include <vector>

class MSIS {

public:
  int findMSIS(const vector<int> &nums) { return findMSISRecursive(nums, 0, -1, 0); }

private:
  int findMSISRecursive(const vector<int> &nums, int currentIndex, int previousIndex, int sum) 
  {
      
        if(currentIndex >= nums.size())
            return sum;
        int sum1 = 0;
        if(previousIndex  == -1 || nums[currentIndex] >= nums[previousIndex])
        {
            //include  currentIndex
            sum1 = findMSISRecursive(nums,currentIndex+1, currentIndex,sum+nums[currentIndex]);
        }
        int sum2 =   findMSISRecursive(nums,currentIndex+1,previousIndex,sum);
        
        return max(sum1,sum2);

  }
};

int main(int argc, char *argv[]) {
  MSIS *msis = new MSIS();
  vector<int> nums = {4, 1, 2, 6, 10, 1, 12};
  cout << msis->findMSIS(nums) << endl;
  nums = vector<int>{-4, 10, 3, 7, 15};
  cout << msis->findMSIS(nums) << endl;

  delete msis;
}
