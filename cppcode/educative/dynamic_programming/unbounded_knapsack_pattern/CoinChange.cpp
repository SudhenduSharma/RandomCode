using namespace std;

#include <iostream>
#include <vector>

class CoinChange {
    public:
        int countChange(const vector<int> &denominations, int total) {
            return countChangeRecursive(denominations,total,0);
            vector<vector<int>> dp(denominations.size(), vector<int>(total+1,-1));
            int ways = this->countChangeTopDown(denominations, total, dp, 0);
            for(auto r : dp)
            {
                for (auto c : r )
                    cout << " " << c << " ";
                cout << endl;
            }
            return ways;
        }

    private:
        int countChangeTopDown(const vector<int> &denominations, int total, vector<vector<int>> &dp , int currentIndex) {
            if(total == 0)
                return 1;
            if(total < 0)
                return 0;
            if(currentIndex >= denominations.size())
                return 0;

            if(dp[currentIndex][total] != -1)
                return dp[currentIndex][total];
            //include currentIndex
            int way1 = 0;
            if(denominations[currentIndex] <= total)
                way1 = countChangeTopDown(denominations,total - denominations[currentIndex], dp, currentIndex);
            //exclude currentIndex
            int way2 = countChangeTopDown(denominations,total,dp, currentIndex + 1 );
            dp[currentIndex][total] = way1 + way2;
            return dp[currentIndex][total];
        }

        int countChangeRecursive(const vector<int> &denominations, int total,  int currentIndex) {
            if(total == 0)
                return 1;
            if(total < 0)
                return 0;
            if(currentIndex >= denominations.size())
                return 0;
            //include currentIndex
            int way1 = 0;
            if(denominations[currentIndex] <= total)
                way1 = countChangeRecursive(denominations,total - denominations[currentIndex], currentIndex);
            //exclude currentIndex
            int way2 = countChangeRecursive(denominations,total, currentIndex + 1 );
            return way1 + way2;
        }
};


int main(int argc, char *argv[]) {
  CoinChange *cc = new CoinChange();
  vector<int> denominations = {1, 2, 3};
  cout << cc->countChange(denominations, 5) << endl;

  delete cc;
}
