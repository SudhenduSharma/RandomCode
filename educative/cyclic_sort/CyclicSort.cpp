using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
    public:
        static void sort(vector<int> &nums) {
            int count = 0;
            int i = 0;
            while(i < nums.size())
            {

                if(nums[i] == i+1)
                    ++i;
                else
                {
                    int tmp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = tmp;
                }
            }   
        }
};
