using namespace std;

#include <iostream>
#include <vector>

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    int i = 0;
    int maxInNums = -1;
    while(i<nums.size())
    {
        for(auto c:nums)
  cout << " " << c << " ";
cout << endl;
        int j = nums[i];
        if(j == nums.size())
        {
            maxInNums = nums.size();
            j = maxInNums-1;
            //nums[i] = j;
            ++i;
            
        }
        else if(j == i)
        {
            ++i;
        }
        else
        {
            swap(nums,i,j);
        }
    }
    int j = 0;
    for(auto c : nums)
    {
        if(c!=j)
            return j;
        ++j;
    }
    cout << endl;
    return -1;
  }
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};


int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
}

