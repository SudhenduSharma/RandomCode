#include <utility>
#include <iostream>
#include <vector>

using namespace std;
class KnapSack
{
    public :
        int solveKnapsack(const vector<int> profit , const vector<int> weights, int capacity)
        {
            if(capacity <= 0 || profit.size() <= 0 )
                return 0;
            int index = 0;
            int profitCalculated = 0;
            return solveKnapsackRecurse(profit , weights,index, capacity,profitCalculated);
        }

        int solveKnapsackRecurse(const vector<int> profit , const vector<int> weights,int index, int capacity,int profitCalculated)
        {
            if(index >= profit.size())
            {
                return profitCalculated;
            }
            //include
            int profitIncluded = 0;
            if( weights[index] <= capacity )
                profitIncluded = solveKnapsackRecurse(profit , weights,index+1,capacity-weights[index],profitCalculated+profit[index]);
            //exclude
            int profitExcluede = solveKnapsackRecurse(profit , weights,index+1,capacity,profitCalculated);
            return max(profitIncluded, profitExcluede);
        }

};
int main()
{
    KnapSack ks;
    vector<int> profits = {1, 6, 10, 16};
    vector<int> weights = {1, 2, 3, 5};
    int maxProfit = ks.solveKnapsack(profits, weights, 7);
    cout<< "maxProfit " << maxProfit << std::endl;
    maxProfit = ks.solveKnapsack(profits, weights, 6);
    cout<< "maxProfit " << maxProfit << std::endl;
    return 0;
}

