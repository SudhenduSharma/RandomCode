#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class PartitionSet
{
    public :
        int canPartition(vector<int> &num)
        {
            if(num.size() == 0)
                return 0;
            int minDiff = 0;
            int sum = std::accumulate(num.begin(),num.end(),0);
            vector<vector<int>> dp(num.size(), vector<int>(sum + 1, -1));
            minDiff = canPartitionRecurseBottomUp(num,dp,0,0,0);

            //minDiff = canPartitionRecurse(num,0,0,0);

            return minDiff;

        }

        int canPartitionRecurse(vector<int> &num, int index ,int set1,int set2)
        {
            if(index == num.size())
            {
                return  abs(set1-set2);
            }
            //include in set1
            int min1 = canPartitionRecurse(num,index+1,set1 + num[index],set2);
            //include in set2
            int min2 = canPartitionRecurse(num, index+1,set1,set2 + num[index]);
            return min(min1,min2);

        }
        int canPartitionRecurseBottomUp(vector<int> &num, vector<vector<int>>& dp, int index ,int set1,int set2)
        {
            if(index == num.size())
            {
                return  abs(set1-set2);
            }
            if(!(dp[index][set1] == -1))
                return dp[index][set1];
            //include in set1
            int min1 = canPartitionRecurseBottomUp(num,dp ,index+1,set1 + num[index],set2);
            //include in set2
            int min2 = canPartitionRecurseBottomUp(num, dp ,index+1,set1,set2 + num[index]);
            dp[index][set1] = min(min1,min2);
            return dp[index][set1];

        }
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 9};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 3, 100, 4};
  cout << ps.canPartition(num) << endl;
}
