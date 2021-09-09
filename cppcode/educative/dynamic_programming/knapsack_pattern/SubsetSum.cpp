#include <iostream>
#include <vector>

using namespace std;
class SubsetSum {
public:
  bool canPartition(const vector<int> &num, int sum) {
    if(num.size() == 1 && num[0] == sum)
        return true;
    vector<vector<int>> dp(num.size(),vector<int>(sum+1, -1));
    bool res =  canPartitionRecurseTopDownDp( num, sum, dp,0);
     for(auto r : dp)
    {
        for(auto c:r)
            cout<< c << " ";
        cout << endl;
    }
    return res;
  }
  bool canPartitionRecurseTopDownDp(const vector<int> &num, int sum,vector<vector<int>> &dp,  int index) {

    if(index >= num.size() || sum < 0)
        return false;
    if(sum == 0 )
        return true;
    //check if already solved previously
    if(dp[index][sum] != -1)
    {
        cout << " already solved index" << index << " sum " << sum << endl;
        return dp[index][sum];
    }
    //solve for including num[index]
    bool  res1 =  canPartitionRecurseTopDownDp(num,sum - num[index],dp, index + 1);
    //solve for excluding num[index]
    bool res = canPartitionRecurseTopDownDp(num,sum, dp, index + 1);
    dp[index][sum] = (res1 || res);
    return dp[index][sum];
  }

  bool canPartitionRecurse(const vector<int> &num, int sum, int index) {
    if(index >= num.size())
        return false;
    if(num[index] == sum)
        return true;
    //solve for including num[index]
    bool res = false;
    if( num[index] <= sum)
    {
        res = canPartitionRecurse(num,sum - num[index], index + 1);
        if( res == true )
            return true;
    }
    //solve for excluding num[index]
    res = canPartitionRecurse(num,sum, index + 1);
    return res;
  }
};

int main(int argc, char *argv[]) {
  SubsetSum ss;
  vector<int> num = {3};
  cout << ss.canPartition(num, 3) << endl;
  num = {1, 2, 3, 7};
  cout << ss.canPartition(num, 6) << endl;
  num = vector<int>{1, 2, 7, 1, 5};
  cout << ss.canPartition(num, 10) << endl;
  num = vector<int>{1, 3, 4, 8};
  cout << ss.canPartition(num, 6) << endl;
}
