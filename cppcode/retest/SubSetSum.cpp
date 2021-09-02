#include<iostream>
#include<vector>
#include <functional>
#include <numeric>
using namespace std;

class SubSetSumProblem
{
    public :
        bool CanPartition(vector<int> &set)
        {
            int sum = std::accumulate(set.begin(),set.end(),0);
            if(1 == sum%2)
                return false;
            sum = sum/2;
            cout << sum << endl;
            int index = 0;
            return CanPartitionRecurse(set,index,sum);
        }

        bool CanPartitionRecurse(vector<int> &set , int index,int sum)
        {
            if(sum == 0)
                return true;

            if(index >= set.size())
                return false;

            //include
            if(set[index] <= sum)
            {
                if(CanPartitionRecurse(set,index+1,sum-set[index]))
                    return true;
            }
            //exclude
            return CanPartitionRecurse(set,index+1,sum);
        }
};
int main()
{
    vector<int> set = {1, 2, 3, 4};
    bool res = SubSetSumProblem().CanPartition(set);
    cout << res ;
    set = {1, 1, 3, 4, 7};


}
