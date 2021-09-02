using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class MinimumWindowSubstring {
 public:
  static string findSubstring(const string &str, const string &pattern) {
      int windowStart = 0 , windowEnd = 0;
      int matched = 0;
      int minLen = str.length();
      unordered_map<char,int> charFreqMapForPattern; 
      for(auto c : pattern)
      {
        charFreqMapForPattern[c]++;
      }
      vector<int> indices= {0,0};
      
      for (;windowEnd < str.length(); ++windowEnd)
      {
            char right = str[windowEnd];
            if(charFreqMapForPattern.find(right) != charFreqMapForPattern.end())
            {
                //char found in map
                --charFreqMapForPattern[right];
                if(charFreqMapForPattern[right] == 0)
                {
                    //char matched in pattern with count 
                    ++matched;
                }
            }
            //shrint windowto minimum for matched char
            while(matched == charFreqMapForPattern.size())
            {
                
                char left = str[windowStart]; 
                windowStart++;
                if(charFreqMapForPattern.find(left) != charFreqMapForPattern.end())
                {
                    charFreqMapForPattern[left]++;
                    if(charFreqMapForPattern[left] > 0)
                    {
                        --matched;
                        if(windowEnd - windowStart + 1 < minLen)
                        {
                            indices[0] = windowStart-1;
                            indices[1] = windowEnd;
                        }

                    }
                }
                // all character matched in current window
            }
      }     
      cout << indices[0] << "-" << indices[1] << endl;
    return str.substr(indices[0],indices[1]);
  }
};

int main(int argc, char *argv[]) {
  cout << "aabdec" <<  MinimumWindowSubstring::findSubstring("aabdec", "abc") << endl;
  cout << "abdbca" << MinimumWindowSubstring::findSubstring("abdbca", "abc") << endl;
  cout << "abdabca" <<  MinimumWindowSubstring::findSubstring("abdabca", "abc") << endl;
  cout << "adcad" << MinimumWindowSubstring::findSubstring("adcad", "abc") << endl;
}
