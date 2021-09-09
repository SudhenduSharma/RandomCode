#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
bool isPrime(int n, int i)
   {
     // write your function here
     if(n==1 || n== 0)
         return false;
      if(i == 1)
        return true;
     if(n%i == 0)
         return false;
     return isPrime(n,i-1);
   }


// function to test your code
// do not change this
int testPrime(int num)
{
  int prime=isPrime(num,num/2);
  return prime;
}
int main()
{
    int n = 0;
       cout << " " << n << "  is  prime? -->"  << testPrime(n) << endl;
       n =1 ;
       cout << " " << n << "  is  prime? -->"  << testPrime(n) << endl;
       n =89 ;
       cout << " " << n << "  is  prime? -->"  << testPrime(n) << endl;
       n = 51 ;
       cout << " " << n << "  is  prime? -->"  << testPrime(n) << endl;
    return 0;;
}
