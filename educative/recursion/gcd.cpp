#include <iostream>
using namespace std;
int gcd(int num1, int num2)
{
  
  
  if(num1 == 0 || num2 == 0)
      return -1;
  
  if(num1 == 1 || num2 == 1)
    return 1;
  if(num1 > num2)
    return gcd(num1-num2,num2);
  else if(num2 > num1)
    return gcd(num2-num1,num1);
  else
    return num1;
}
int main()
{
    int res = 0;
    res = gcd(18,24);
    if(res == 6)
    {
        cout<<"Test Passed gcd(18,24) " << res << endl;
    }
    
    res = gcd(18,0);
    if(res == -1)
    {
        cout<<"Test Passed gcd(18,0) " << res << endl;
    }


    res = gcd(4,5);
    if(res == 1)
    {
        cout<<"Test Passed gcd(4,5) " << res << endl;
    }
    return 0;
}
