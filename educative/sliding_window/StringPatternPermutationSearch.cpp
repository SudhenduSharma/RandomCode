
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    int windowStart = 0 , windowEnd = 0;
    unordered_map<int,int> numberFreqMap;
    for( ; windowEnd < arr.size(); ++windowEnd )
    {
         numberFreqMap[arr[windowEnd]]++;
         int zeroCountInWindow = numberFreqMap[0];
         if(zeroCountInWindow > k)
         {
             --numberFreqMap[arr[windowStart]];
             ++windowStart;
         }
         maxLength = max(maxLength,windowEnd - windowStart + 1);
    }
    return maxLength;
  }
};


using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

class StringPermutation {
 public:
     static bool findPermutation(const string &str, const string &pattern) {
         unordered_map<char,int> charFreqMap;
         for(auto c : pattern)
         {
             ++charFreqMap[c];
         }
         int windowStart = 0 , windowEnd = 0;
         unordered_map<char,int> charFreqMapInWindow;
         for( ; windowEnd < str.length(); ++windowEnd )
         {
           //do nothing if windowEnd - windowStart + 1 < pattern.length() 
           char right = str[windowEnd];
           charFreqMapInWindow[right]++;

           if(windowEnd - windowStart + 1 > pattern.length())
           {
               char leftChar = str[windowStart];
               --charFreqMapInWindow[leftChar];
               if(charFreqMapInWindow[leftChar] == 0)
                   charFreqMapInWindow.erase(leftChar);
                ++windowStart;
           }
           if(charFreqMapInWindow.size() == charFreqMap.size())
           {
               if(charFreqMapInWindow == charFreqMap)
                   return true;
           }
         }

         return false;
     }
  static bool findPermutationSolution(const string &str, const string &pattern) {
    int windowStart = 0, matched = 0;
    unordered_map<char, int> charFrequencyMap;
    for (auto chr : pattern) {
      charFrequencyMap[chr]++;
    }

    // our goal is to match all the characters from the 'charFrequencyMap' with the current window
    // try to extend the range [windowStart, windowEnd]
    for (int windowEnd = 0; windowEnd < str.length(); windowEnd++) {
      char rightChar = str[windowEnd];
      if (charFrequencyMap.find(rightChar) != charFrequencyMap.end()) {
        // decrement the frequency of the matched character
        charFrequencyMap[rightChar]--;
        if (charFrequencyMap[rightChar] == 0) {  // character is completely matched
          matched++;
        }
      }

      if (matched == (int)charFrequencyMap.size()) {
        return true;
      }

      if (windowEnd >= pattern.length() - 1) {  // shrink the window
        char leftChar = str[windowStart++];
        if (charFrequencyMap.find(leftChar) != charFrequencyMap.end()) {
          if (charFrequencyMap[leftChar] == 0) {
            matched--;  // before putting the character back, decrement the matched count
          }
          // put the character back for matching
          charFrequencyMap[leftChar]++;
        }
      }
    }

    return false;
  }
};

int main(int argc, char *argv[]) {
  cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;
}
