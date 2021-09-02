
#include <iostream>
#include <vector>

using namespace std;
class Fibonacci {

public:
  virtual int CalculateFibonacci(int n) {
    if (n < 2) {
      return n;
    }
    return CalculateFibonacci(n - 1) + CalculateFibonacci(n - 2);
  }
};

class FibonacciMemoized:public Fibonacci {

public:
    FibonacciMemoized():Fibonacci(){}
    int CalculateFibonacciImp(int n)
    {
        if (n < 2) {
            return n;
        }

        if(mMemoized[n])
        {
            cout << " returning from memory " << mMemoized[n] << endl;
            return mMemoized[n];
        }
        mMemoized[n] = CalculateFibonacciImp(n-1) + CalculateFibonacciImp(n-2);
        return mMemoized[n];
    }

  virtual int CalculateFibonacci(int n) {
    //TODO fix memory leak
    mMemoized = new int[n+2]();
    mMemoized[0] = 0;
    mMemoized[1] = 1;
    if (n < 2) {
      return n;
    }
    return  CalculateFibonacciImp(n);
//    return CalculateFibonacci(n - 1) + CalculateFibonacci(n - 2);
  }
  void printMemoized()
  {
  }
  int *mMemoized;
};

class FibonacciTabulation:public Fibonacci {

public:
    FibonacciTabulation():Fibonacci(){}
  virtual int CalculateFibonacci(int n) {
    //TODO fix memory leak
    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    if(n<2)
        return dp[n];
    for(int i =2 ; i <= n ; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return  dp[n];
  }
};
int main(int argc, char *argv[]) {
  //Fibonacci *fib = new FibonacciMemoized();
  Fibonacci *fib = new FibonacciTabulation();
  cout << "5th Fibonacci is ---> " << fib->CalculateFibonacci(5) << endl;
  cout << "6th Fibonacci is ---> " << fib->CalculateFibonacci(6) << endl;
  cout << "7th Fibonacci is ---> " << fib->CalculateFibonacci(7) << endl;

  //static_cast<FibonacciMemoized*>(fib)->printMemoized();

}
