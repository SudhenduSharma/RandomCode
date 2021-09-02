#include<iostream>
#include <iomanip>
using namespace std;
int main(){
    double a = 159543.000;
    double b = 1.29017;
    double x = 159543.000/1.29017;
    std::cout << "round(+2.3) = " << setprecision(10) << x << "  "<<(double)((double)159543.000)/(double)(1.29017);
    return 0;
}
