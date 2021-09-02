#include <iostream>
#include<vector>
using namespace std;
class Knapsack
{
    public :
        int solveKnapsack(vector<int> profits, vector<int> weights, int capacity)
        {
            return solveKnapsackRecurse(profits, weights, capacity,0,0);
        }
        int solveKnapsackRecurse(vector<int> profits, vector<int> weights, int capacity,int currentIndex,int profit)
        {
            if(capacity <= 0)
                return profit;
            if(currentIndex >= profits.size())
            {
                return profit;
            }
            int profit1 = 0;
            if(capacity >= weights[currentIndex] )
            {
                profit1 = solveKnapsackRecurse(profits,weights,capacity - weights[currentIndex], currentIndex,profit+profits[currentIndex]);
            }

            int profit2 = 0;
            profit2 = solveKnapsackRecurse(profits,weights,capacity, currentIndex+1,profit);

            return std::max(profit1,profit2);
        }

};
int main()
{

Knapsack *ks = new Knapsack();
  vector<int> profits = {15, 50, 60, 90};
  vector<int> weights = {1, 3, 4, 5};
  cout << ks->solveKnapsack(profits, weights, 8) << endl;
  cout << ks->solveKnapsack(profits, weights, 6) << endl;
}

