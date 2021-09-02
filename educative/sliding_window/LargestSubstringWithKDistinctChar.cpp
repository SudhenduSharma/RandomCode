
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
class LongestSubstringKDistinct {
 public:
  static int uninqueChar(const string& str,int windowStart,int windowEnd)
  {
      std::unordered_map<int, int> uniqueCharMap = {};
      for( ; windowStart <= windowEnd;++windowStart )
      {
         uniqueCharMap.insert(std::make_pair(str[windowStart],1));
      }
      return uniqueCharMap.size();
    }
  static int findLengthNSquareSolution(const string& str, int k) {
    int maxLength = 0;
    int windowStart = 0;
    string longestSubString;
    for(int windowEnd = windowStart; windowEnd < str.length() ; windowEnd++)
    {
   
        //process windowEnd to windowStart for k uniqueChar
        int uniqChar = uninqueChar(str,windowStart,windowEnd);
        if(uniqChar <= k)
        {
            maxLength = windowEnd - windowStart + 1;
        }
        else
        {
            ++windowStart;
        }

    }
    return maxLength;
  }

  static int findLengthOptimum(const string& str, int k) {
    int maxLength = 0;
    int windowStart = 0;
    string longestSubString;
    std::unordered_map<char, int> charFreqMap = {};
    for(int windowEnd = windowStart; windowEnd < str.length() ; windowEnd++)
    {
   
        //process windowEnd to windowStart for k uniqueChar
        char end = str[windowEnd];
        ++charFreqMap[end];

        while(charFreqMap.size() > k){
             char start = str[windowStart];
             charFreqMap[start]--;
             if(charFreqMap[start] == 0)
                 charFreqMap.erase(start);
             ++windowStart;
        }
        
        maxLength = max(maxLength,windowEnd - windowStart + 1);
    }
    return maxLength;
  }
  static int findLength(const string& str, int k) {
    return  findLengthOptimum(str,k);
    //return  findLengthNSquareSolution(str,k);
      
}
};


int main(int argc, char *argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1)
       << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3)
       << endl;
}

