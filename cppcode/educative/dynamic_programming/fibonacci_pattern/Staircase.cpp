using namespace std;

#include <iostream>
#include <vector>

class Staircase {

public:
    int CountWays(int n) {
        vector<int> dp(n + 1, -1);
        int res = CountWaysRecursive(n,dp);
        for(auto c : dp)
            cout << " " << c << " ";
        cout <<endl;
        return res;
    }
    int CountWaysRecursive(int n,vector<int> &dp) {
        if(n == 0)
            return 1;
        if(n == 1)
            return 1;
        if(n == 2 )
            return 2;
        if(dp[n] != -1)
            return dp[n];
        dp[n] = CountWaysRecursive(n-1,dp) + CountWaysRecursive(n-2,dp) + CountWaysRecursive(n-3,dp);
        return dp[n];

    }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  cout << sc->CountWays(3) << endl;
  cout << sc->CountWays(4) << endl;
  cout << sc->CountWays(5) << endl;

  delete sc;
}
