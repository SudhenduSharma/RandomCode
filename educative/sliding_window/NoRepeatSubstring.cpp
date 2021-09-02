
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    int windowStart = 0, windowEnd = 0;
    unordered_map<char,int> charFreqMap;
    for(;windowEnd < str.length(); ++windowEnd)
    {
        char charAtwindowEnd = str[windowEnd];
        int prevSize = charFreqMap.size();
        ++charFreqMap[charAtwindowEnd];
        if(prevSize == charFreqMap.size())
        {
            //shirnk window such that windowStart = windowEnd
            //new Char added is already existing in Map
            while(windowStart < windowEnd)
            {
                char charAtwindowStart = str[windowStart];
                --charFreqMap[charAtwindowStart];
                if(charFreqMap[charAtwindowStart] == 0)
                    charFreqMap.erase(charAtwindowStart);
                ++windowStart;
            }
        }
        maxLength = max(maxLength,windowEnd-windowStart+1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
}
