#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;
class Solution {
public:
    //index,value pair
    deque<pair<int,int>> chronological_queue_;
    void removeElementSmallerThanCurrent(int val)
    {
        while(!chronological_queue_.empty() && val > chronological_queue_.back().second )
        {
            chronological_queue_.pop_back();
        }
    }

    void removeElementOutOfWindow(int ws)
    {
        if(!chronological_queue_.empty() && chronological_queue_.front().first < ws)
        {
            chronological_queue_.pop_front();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        vector<int> result;
        for(int i = 0 ; i < k; ++i)
        {
            removeElementSmallerThanCurrent(nums[i]);
            chronological_queue_.push_back({i,nums[i]});
        }
        result.push_back(chronological_queue_.front().second);
        for( int  we = k; we < nums.size()  ;++we)
        {
            removeElementOutOfWindow(we-k+1);
            removeElementSmallerThanCurrent(nums[we]);
            chronological_queue_.push_back({we,nums[we]});
            Print();
            result.push_back(chronological_queue_.front().second);
        }
        return result;
    }
    void Print()
    {
    for(auto val :chronological_queue_)
        {
            cout <<  val.second << "(" << val.first <<") ";
        }
        cout << endl <<  " --" << endl;
    }

};
int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto result = Solution().maxSlidingWindow(nums,2);
    cout << endl;
    for(auto val :nums)
    {
        cout << val << " ";
    }
    cout << endl;
    for(auto val :result)
    {
        cout << val << " ";
    }
    return 0;
}


