#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;
//https://www.sandordargo.com/blog/2019/11/06/stl-alogorithms-tutorial-part-7-transform

class Solution {
public:

};

// C++ program to print all possible
// substrings of a given string

using namespace std;

// Function to print all sub strings
void subString(char str[], int n)
{
    // Pick starting point
    for (int len = 1; len <= n; len++)
    {
        // Pick ending point
        for (int i = 0; i <= n - len; i++)
        {
            //  Print characters from current
            // starting point to current ending
            // point.
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
            {
                //cout << "len = " << len << " i= " <<  i << " j= " <<j << " k= " << k << " " << str[k];
                cout << str[k];
            }
            cout << endl;
        }
    }
}

// Driver program to test above function
int main()
{
    char str[] = "abcde";
    subString(str, strlen(str));
    return 0;
}

//int main(int argc, char** argv)
//{
//    if(!(argc > 1)) {
//        std::cout<< "EXIT no input";
//        return 0;
//    }
//
//    int sum = -1;
//    std::istringstream ( argv[1] ) >> sum;
//
//    std:cout << sum << "<--sum";

//    std::vector<int> nums = { 1,2,3,4};
//    auto res = Solution().printSubArray(nums);
//    return 0;
//}
