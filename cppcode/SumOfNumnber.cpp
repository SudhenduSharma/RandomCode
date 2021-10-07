#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

class Solution
{
    public :
        static long SumOfNumber(vector<int>& nums)
        {
            return std::accumulate(nums.begin(),nums.end(),0);
        }

};
int main()
{
      std:vector<int> nums = { 1 ,2 ,3 ,4 ,5 };
      std::cout << Solution::SumOfNumber(nums);
    return 0;
}
