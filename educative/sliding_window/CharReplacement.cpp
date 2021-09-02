
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
	int windowStart=0,windowEnd=0;
	unordered_map<char,int> reapeatedCharFreqMap;
	for( ; windowEnd < str.length(); ++windowEnd)
	{
		char charRight = str[windowEnd];
		reapeatedCharFreqMap[charRight]++;
        int mostRepeatedCharCount = 0;
        if(reapeatedCharFreqMap.size()){
            std::pair<char, int> min = *max_element( reapeatedCharFreqMap.begin(), reapeatedCharFreqMap.end(), [](const auto &a, const auto &b) { return a.second < b.second; });
            mostRepeatedCharCount = min.second;
        }
        if(windowEnd - windowStart +1 - mostRepeatedCharCount > k)
        {
            char leftChar = str[windowStart];
            reapeatedCharFreqMap[leftChar]--;
            //if(reapeatedCharFreqMap[leftChar] == 0)
            //    reapeatedCharFreqMap.erase(leftChar);
            windowStart++;
        }
        maxLength = max(maxLength, windowEnd - windowStart + 1);
	}
    return maxLength;
  }
};
int main(int argc, char *argv[]) {
  cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
  cout << CharacterReplacement::findLength("abbcb", 1) << endl;
  cout << CharacterReplacement::findLength("abccde", 1) << endl;
  cout << CharacterReplacement::findLength("abccdce", 1) << endl;
  cout << CharacterReplacement::findLength("aeaabcdr", 1) << endl;
}
