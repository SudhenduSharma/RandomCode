#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        priority_queue<int> capacityAvailable;
        int currentLimit = limit;
        for(auto weight:people)
        {
            if(capacityAvailable.size())
            {

            }
            if(weight <= currentLimit)
                currentLimit -= weight;

        }
        
    }
};
int main()
{
    vector<int> people = {1,2};
    Solution().numRescueBoats(people,3);
    people = {3,2,2,1};
    Solution().numRescueBoats(people,3);
    people = {3,5,3,4};
    Solution().numRescueBoats(people,5);


    return 0;

}
