#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
//https://www.sandordargo.com/blog/2019/11/06/stl-alogorithms-tutorial-part-7-transform

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double median = 0;
        return median;
    }
    vector<int> TwoSum(vector<int>& nums, int target) {
        typedef int index;
        typedef int value;
        std::unordered_map<value,index> indexToValueLookUpTable;

        int i = 0;
        for( auto& n : nums ) {
//            std::cout << n << " ";
            indexToValueLookUpTable.insert(std::make_pair(n,i)); 
            ++i;
        }

 //       for(auto& p : indexToValueLookUpTable ) {
 //           std::cout << " " << p.first << " " << p.second << " \n";
 //       }
        
        i = 0;
        for( auto& n : nums ) {
            auto search = indexToValueLookUpTable.find(target-n);
            if (search != indexToValueLookUpTable.end() && search->second != i) {
                //std::cout << "Found " << search->first << " " << search->second << '\n';
                std::vector<int> result;
                result.push_back(i);
                result.push_back(search->second);
                return result;
            } 
            ++i;
        }

        return vector<int>();

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
