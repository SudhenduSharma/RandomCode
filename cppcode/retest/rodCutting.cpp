#include<iostream>
#include <vector>

using namespace std;
struct Solution{
    int cutRod(vector<int>& length, vector<int> &price, int rodLen)
    {
        //asserts TODO
        //memoize TODO
        return solveRodCuttingRecurse(length,price,rodLen,0);
        //return cutRodRecurse(length,price,rodLen,0);
    }
    int cutRodRecurse(vector<int>& length, vector<int> &price, int rodLen, int index)
    {
        if(rodLen <=0)
            return 0;
        if(index>=length.size())
        {
            return 0;
        }
        int profit_by_including = 0;
        if(length[index] <= rodLen)
        {
            //include
            profit_by_including = price[index] + cutRodRecurse(length,price,rodLen-length[index],index);
        }
            //exclude
        int profit_by_exluding =  cutRodRecurse(length,price,rodLen,index+1);

        return std::max(profit_by_including,profit_by_exluding);

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

int main()
{
    vector<int> length = {1,2,3,4,5};
    vector<int> prices = {2,6,7,10,13};
    int maxProfit = Solution().cutRod(length, prices, 5);
  cout << maxProfit << endl;
}
