
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0;
 	int windowStart = 0;
 	int windowEnd = 0;
    unordered_map<char,int> fruitsTypeInWindow;	
    for(;windowEnd < arr.size();++windowEnd)
    {
		char nextFruitType = arr[windowEnd];
        ++fruitsTypeInWindow[nextFruitType];
        while(fruitsTypeInWindow.size() > 2 )
        {
        //shrink window	
            char currFruitType = arr[windowStart];
            --fruitsTypeInWindow[currFruitType];

            if(fruitsTypeInWindow[currFruitType] == 0)
            {
                fruitsTypeInWindow.erase(currFruitType);
            }
            ++windowStart;
        }
        maxLength = max(maxLength,windowEnd-windowStart+1);

        }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}
