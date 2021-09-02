//https://leetcode.com/problems/boats-to-save-people/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
    }
};
int main()
{
    vector<int> people = {1,2};
    cout << Solution().numRescueBoats(people,3) << endl;
    people = {3,2,2,1};
    cout << Solution().numRescueBoats(people,3) << endl;
    people = {3,5,3,4};
    cout << Solution().numRescueBoats(people,5) << endl;

    return 0;
}
