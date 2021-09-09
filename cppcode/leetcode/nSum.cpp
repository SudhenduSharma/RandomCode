#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
//https://www.sandordargo.com/blog/2019/11/06/stl-alogorithms-tutorial-part-7-transform

class Solution {
public:
    bool nSum(vector<int>& nums, int index ,int target) {

        if( target == 0 )
        {
            return true;
        }
        else
        {
            int i = 0;
            for( auto& n : nums ) {
                nSum(vector<int>& nums,index,)

            } 
            ++i;
        }
    }

};

int main(int argc, char** argv)
{
    if(!(argc > 1)) {
        std::cout<< "EXIT no input";
        return 0;
    }

    int sum = -1;
    std::istringstream ( argv[1] ) >> sum;

    std:cout << sum << "<--sum";

    std::vector<int> nums = { 4,7,2,8,100};
    auto res = Solution().TwoSum(nums,sum);
    std::cout << "------\n";
    for ( auto& n : res ) {
        std::cout << n << " ";
    }
    std::cout << "\n------\n";
    return 0;
}
