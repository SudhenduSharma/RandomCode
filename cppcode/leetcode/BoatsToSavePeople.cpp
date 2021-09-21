//https://leetcode.com/problems/boats-to-save-people/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(),people.end());
        auto it = std::max_element(people.begin(),people.end());
        if(*it>limit)
        {
            return -1;
        }
        int allocated = 0;
        int start = 0;
        int end = people.size() - 1;
        while(start <= end)
        {
            if(people[end] + people[start] <= limit  )
            {
                ++allocated;
                ++start; --end;
            }
            else if(people[end] <= limit)
            {
                ++allocated;
                --end;
            }
            else
            {
                cout << "not possible" << endl;
            }
        }
        return allocated;
    }
};
int main()
{
    vector<int> people = {1,2};
    cout << Solution().numRescueBoats(people,3) << endl;
    people = {3,2,2,1};
    cout << Solution().numRescueBoats(people,3) << endl;
    people = {3,5,3,4,4};
    cout << Solution().numRescueBoats(people,5) << endl;
    people = {3,5,3,6};
    cout << Solution().numRescueBoats(people,5) << endl;

    return 0;
}
