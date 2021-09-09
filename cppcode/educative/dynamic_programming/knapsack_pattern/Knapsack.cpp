#include <iostream>
#include <vector>
using namespace std;

class Knapsack {
public:
int solveKnapsack(const vector<int> &profits, const vector<int> &weights,int capacity)
{
    return    this->KnapsackRecursive(profits,weights,capacity,0);
	
}
int KnapsackRecursive(const vector<int> &profits, const vector<int> &weights,int capacity, int index)
{
    if( capacity <=0 || index >= profits.size() )
        return 0;

    int profit1 = 0;
    if(weights[index]<= capacity)
        profit1 = profits[index] + KnapsackRecursive(profits,weights,capacity-weights[index], index + 1 );

    int profit2 = KnapsackRecursive(profits,weights,capacity,index + 1 );

    return max(profit1 , profit2);
}

int solveKnapsackTopDownDP(const vector<int> &profits, const vector<int> &weights,int capacity)
{

    vector<vector<int>> dp(profits.size() ,vector<int>(capacity+1,-1));
    return this->KnapsackTopDownDP(profits, weights, capacity,0,dp);
}
int KnapsackTopDownDP(const vector<int> &profits, const vector<int> &weights,int capacity, int index,vector<vector<int>> &dp)
{
    if( capacity <=0 || index >= profits.size() )
        return 0;
    if(dp[index][capacity] != -1)
        return dp[index][capacity];
    int profit1 = 0;
    if(weights[index]<= capacity)
        profit1 = profits[index] + KnapsackRecursive(profits,weights,capacity-weights[index], index + 1 );

    int profit2 = KnapsackRecursive(profits,weights,capacity,index + 1 );
    dp[index][capacity] = max(profit1 , profit2);

    return dp[index][capacity];
}
private:
};

int main(int argc, char *argv[]) {
     Knapsack ks;
  vector<int> profits = {1, 6, 10, 16};
  vector<int> weights = {1, 2, 3, 5};
  int maxProfit = ks.solveKnapsack(profits, weights, 7);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsackTopDownDP(profits, weights, 7);
  cout << "Total knapsack profit TopDownDP--> " << maxProfit << endl;
  maxProfit = ks.solveKnapsack(profits, weights, 6);
  cout << "Total knapsack profit ---> " << maxProfit << endl;
  maxProfit = ks.solveKnapsackTopDownDP(profits, weights, 6);
  cout << "Total knapsack profit TopDownDP--> " << maxProfit << endl;
}
