using namespace std;

#include <iostream>
#include <vector>

class Knapsack {

public:
  int solveKnapsack(const vector<int> &profits, const vector<int> &weights, int capacity) {
      vector<vector<int>> dp(profits.size(),vector<int>(capacity+1, -1));
      int profit = this->knapsackTopDownDp(profits, weights, capacity, dp,  0);
      for(auto r : dp)
      {
          for(auto c : r)
          {
              cout << " " << c << " ";
          }
              cout << endl;
      }
      return profit;
    //return this->knapsackRecursive(profits, weights, capacity, 0);

  }
private :

  int knapsackTopDownDp(const vector<int> &profits, const vector<int> &weights, int capacity ,vector<vector<int>>& dp , int index)
  {
      if(capacity <= 0 || index >= weights.size())
      {
          return 0;
      }
      if(dp[index][capacity] != -1)
          return dp[index][capacity];

      //solve by including 
      int profit1 = 0;
      if(capacity >= weights[index])
      {
          profit1 = profits[index] + knapsackTopDownDp(profits,weights, capacity-weights[index], dp,index);
      }
      //solve by excluding 
      int   profit2  = knapsackTopDownDp(profits,weights, capacity, dp, index+1);

      dp[index][capacity] = max(profit1,profit2);

      return max(profit1,profit2);

  }
  int knapsackRecursive(const vector<int> &profits, const vector<int> &weights,     int capacity , int index)
  {
      if(capacity <= 0 || index >= weights.size())
      {
          return 0;
      }
      //solve by including 
      int profit1 = 0;
      if(capacity >= weights[index])
      {
          profit1 = profits[index] + knapsackRecursive(profits,weights, capacity-weights[index], index);
      }
      //solve by excluding 
      int   profit2  = knapsackRecursive(profits,weights, capacity, index+1);

      return max(profit1,profit2);

  }
};
int main(int argc, char *argv[]) {
  Knapsack *ks = new Knapsack();
  vector<int> profits = {15, 50, 60, 90};
  vector<int> weights = {1, 3, 4, 5};
  cout << ks->solveKnapsack(profits, weights, 8) << endl;
  cout << ks->solveKnapsack(profits, weights, 6) << endl;

  delete ks;
}
