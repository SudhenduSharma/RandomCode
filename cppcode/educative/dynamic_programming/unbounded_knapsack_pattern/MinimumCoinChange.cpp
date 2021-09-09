using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class CoinChange {

    public:
        int countChange(const vector<int> &denominations, int total) {

            //return countChangeRecursive(denominations,total,0,0);
            
            vector<vector<int>> dp(total,vector<int>(total+1,-1));
            int res = countChangeTopDown(denominations, total,0,dp,0);

            for(auto r : dp){
                for(auto c:r)
                    cout << " " << c << " ";
                cout << endl;
            }
            return (INT_MAX == res) ? (-1):res;

        }

        int countChangeTopDown(const vector<int> &denominations, int total,int index,vector<vector<int>>& dp)  {
            if(index >= denominations.size())
                return INT_MAX;
            if(total == 0)
                return 0;

            if(dp[index][total] != -1)
                return dp[index][total];
            int count1 = INT_MAX;
            if(denominations[index] <= total)
            {
                int res = countChangeTopDown(denominations,total-denominations[index],index,dp);
                if (res != numeric_limits<int>::max()) {
                    count1 = res + 1;
                }
            }
            int count2 = INT_MAX;
            count2 = countChangeTopDown(denominations,total,index+1,dp);

            dp[index][total] = min(count1,count2);
            return dp[index][total];
        }

        int countChangeTopDown(const vector<int> &denominations, int total,int index,vector<vector<int>>& dp,int count)  {
            //cout << "WHY THIS DOES NOT WORK????????" << endl;
            if(index >= denominations.size())
                return INT_MAX;
            if(total == 0)
                return count;

            if(dp[index][total] != -1)
                return dp[index][total];

            int count1 = INT_MAX;
            if(denominations[index] <= total)
            {
                count1 = countChangeTopDown(denominations,total-denominations[index],index,dp,count+1);
            }
            int count2 = INT_MAX;
            count2 = countChangeTopDown(denominations,total,index+1,dp,count);

            dp[index][total] = min(count1,count2);
            return dp[index][total];
        }
        int countChangeRecursive(const vector<int> &denominations, int total,int index,int count)  {
            if(index >= denominations.size())
                return INT_MAX;
            if(total == 0)
                return count;
            int count1 = INT_MAX;
            if(denominations[index] <= total)
            {
                count1 = countChangeRecursive(denominations,total-denominations[index],index,count+1);
            }
            int count2 = INT_MAX;
            count2 = countChangeRecursive(denominations,total,index+1,count);

            return min(count1,count2);
        }
};
int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;
  return 0;
  cout << cc->countChange(denominations, 11) << endl;
  cout << cc->countChange(denominations, 7) << endl;
  denominations = vector<int>{3, 5};
  cout << cc->countChange(denominations, 7) << endl;

  delete cc;
}
