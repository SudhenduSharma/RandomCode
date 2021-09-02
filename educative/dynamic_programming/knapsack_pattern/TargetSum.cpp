using namespace std;

#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#include <algorithm>

class TargetSum {
public:
    int findTargetSubsets(const vector<int> &num, int s) {

            int maxSum = std::accumulate(num.begin(),num.end(),0);

            vector<vector<int>> dp(num.size(),vector<int>(maxSum+1,-1));

            int way =  findTargetSubsetsTopDown(num,s,0,dp,0);

            for(auto r:dp)
            {
                for(auto c:r)
                    cout << " " << c << " ";
                cout <<endl;
            }
            return way;

    }

    int findTargetSubsetsTopDown(const vector<int> &num, int sum,int index, vector<vector<int>>& dp, int pathSum) {
        if(index >= num.size() && pathSum == sum )
        {
            return 1;
        }
        if(index >= num.size() && pathSum != sum)
            return 0;
        if(dp[index][pathSum] != -1)
        {
            cout<< "returning from memoization" << endl;
            return dp[index][pathSum];
        }
        // add + 
        int way1 = findTargetSubsetsTopDown(num,sum,index+1,dp ,pathSum+num[index]);
        // add -
        int way2 = findTargetSubsetsTopDown(num,sum,index+1,dp, pathSum-num[index]);
        
        dp[index][pathSum] = way1 + way2;
        return dp[index][pathSum];

    } 

    int findTargetSubsetsRecursive(const vector<int> &num, int sum,int index, int pathSum) {
        if(index >= num.size() && pathSum == sum )
        {
            return 1;
        }
        if(index >= num.size() && pathSum != sum)
            return 0;
        // add + 
        
        int way1 = findTargetSubsetsRecursive(num,sum,index+1,pathSum+num[index]);
        // add -
        int way2 = findTargetSubsetsRecursive(num,sum,index+1,pathSum-num[index]);

        return way1 + way2;

    } 

};




int main(int argc, char *argv[]) {
  TargetSum ts;
  vector<int> num = {1, 1, 2, 3};
  cout << ts.findTargetSubsets(num, 1) << endl;
  num = vector<int>{1, 2, 7, 1};
  cout << ts.findTargetSubsets(num, 9) << endl;
}
