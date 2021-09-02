using namespace std;

#include <iostream>
#include <vector>

class RodCutting {

public:
    int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int rodLen) {

        vector<vector<int>> dp(lengths.size(),vector<int>(rodLen+1,-1));

        int profit = solveRodCuttingTopDown(lengths,prices,rodLen,dp, 0);

        for(auto r: dp)
        {
            for(auto c : r)
                cout << " " << c << " ";
            cout << endl;
        }

        return profit;

    }
    int solveRodCuttingTopDown(const vector<int> &lengths, vector<int> &prices, int rodLen, vector<vector<int>>& dp, int index) {
      if(rodLen <= 0)
          return 0;

      if(index >= lengths.size())
          return 0;

      if(dp[index][rodLen] != -1 )
          return dp[index][rodLen];

      //include index 
      int profit1 = 0;

      if(rodLen >= lengths[index])
        profit1 = prices[index] + solveRodCuttingTopDown(lengths, prices, rodLen - lengths[index],dp, index);

      //exclude index
      int profit2 = solveRodCuttingTopDown(lengths, prices, rodLen , dp, index + 1 );

      //cout << " profit1"
      //
      dp[index][rodLen] = max(profit1, profit2);

      return max(profit1, profit2);

  }
int solveRodCuttingRecurse(const vector<int> &lengths, vector<int> &prices, int rodLen,int index) {
      if(rodLen <= 0)
          return 0;

      if(index >= lengths.size())
          return 0;

      //include index 
      int profit1 = 0;

      if(rodLen >= lengths[index])
        profit1 = prices[index] + solveRodCuttingRecurse(lengths, prices, rodLen - lengths[index], index);

      //exclude index
      int profit2 = solveRodCuttingRecurse(lengths, prices, rodLen , index + 1 );

      //cout << " profit1"

      return max(profit1, profit2);

  }


};
int main(int argc, char *argv[]) {
  RodCutting *rc = new RodCutting();
  vector<int> lengths = {1, 2, 3, 4, 5};
  vector<int> prices = {2, 6, 7, 10, 13};
  int maxProfit = rc->solveRodCutting(lengths, prices, 5);
  cout << maxProfit << endl;

  delete rc;
}
