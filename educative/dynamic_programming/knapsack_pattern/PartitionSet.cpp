#include <iostream>
#include <vector>
using namespace std;
class PartitionSet {
	public:
		bool canPartition(const vector<int> &num) {
			int sum = 0;
			for(auto c : num)
				sum += c;
			cout << " Solving for " << sum << endl;
			//check if sum is even else return
			if(sum%2)
				return false;
			return this->canPartitionRecursive(num,0,sum/2);
		}
    private :
        bool canPartitionRecursive(const vector<int> &num, int sum, int currentIndex) {
            //base case
            if( 0 == sum)
                return true;
            if( num.empty() || currentIndex >= num.size())
                return false;
            // recursive call after choosing the number at the currentIndex
            // if the number at currentIndex exceeds the sum, we shouldn't process this
            if (num[currentIndex] <= sum) {
                if (canPartitionRecursive(num, sum - num[currentIndex], currentIndex + 1)) {
                    return true;
                }
            }

            // recursive call after excluding the number at the currentIndex
            return canPartitionRecursive(num, sum, currentIndex + 1);
        }
		//bool canPartitionRecursive(const vector<int> &num, int index, int sum) {
		//	//base case
		//	if(num[index] == sum || index >= num.size())
		//		return true;
		//	bool result1 = false;
		//	if(num[index] <= sum )
		//	{
		//		//include index in solution
		//		result1 = canPartitionRecursive(num,sum-num[index], index+1);
		//	}
		//	//exclusde index in solution keep sum intact and solve for remaining
		//	bool result2 = canPartitionRecursive(num,sum,index+1);
		//	return (result1 || result2);
		//}
};

int main(int argc, char *argv[]) {
  PartitionSet ps;
  vector<int> num = {1, 2, 3, 4};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{1, 1, 3, 4, 7};
  cout << ps.canPartition(num) << endl;
  num = vector<int>{2, 3, 4, 6};
  cout << ps.canPartition(num) << endl;
}
