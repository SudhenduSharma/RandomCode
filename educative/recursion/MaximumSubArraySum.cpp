//https://medium.com/solvingalgo/how-to-solve-algorithmic-problems-maximum-sum-of-a-contiguous-subarray-5568adbfc5b
#include <iostream>
#include<vector>
#include <functional>
#include <numeric>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int total = std::accumulate(nums.begin(),nums.end(),0);

        int sum  = maxSubArrayRecurse(nums,0,nums.size()-1,total);
        return sum;
    }

    int maxSubArrayRecurse(vector<int>& nums,int left , int right, int total) {
        if(left >= right)
        {
            return total; 
        }
        //include index
        int sum1 = maxSubArrayRecurse(nums,left, right-1, total-nums[right]);
        int sum2 = 0;
        sum2 = maxSubArrayRecurse(nums,left+1,right, total - nums[left]);
        return max(total,max(sum1,sum2));

       }       
    int maxSubArrayKadane(vector<int>& nums){
        return 0;
        }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(nums) << endl;
    nums = {4, -1, 6, -100, 5};
    cout << Solution().maxSubArray(nums) << endl;

    return 0;
}
