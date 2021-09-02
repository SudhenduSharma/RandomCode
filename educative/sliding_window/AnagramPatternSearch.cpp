
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    unordered_map<char,int> charCountMapAnagram;
    int matchedCharCountInWindow = 0;
    for(int i = 0; i < pattern.length(); ++i)
    {
        ++charCountMapAnagram[pattern[i]];
    }
    int windowStart = 0 ,  windowEnd = 0;

    for( ;windowEnd < str.length(); ++windowEnd )
    {
        char charAtWindowEnd = str[windowEnd];
                if(windowEnd - windowStart + 1 > pattern.length()  )
        {
            //time to shrink window of interest
            char charAtWindowStart = str[windowStart];
            if(charCountMapAnagram.find(charAtWindowStart) != charCountMapAnagram.end())
            {
                //char at window start is in anagram therfore it need to be back in char count map while shrinking
                ++charCountMapAnagram[charAtWindowStart];
                if(charCountMapAnagram[charAtWindowStart] > 0)
                    --matchedCharCountInWindow;
            }
            ++windowStart;
        }
        if(charCountMapAnagram.find(charAtWindowEnd)  != charCountMapAnagram.end())
        {
            --charCountMapAnagram[charAtWindowEnd];
            if(charCountMapAnagram[charAtWindowEnd] == 0)
                ++matchedCharCountInWindow;
        }

        cout <<  windowStart << " - " << windowEnd << " " << matchedCharCountInWindow << " " <<endl; 
        if(matchedCharCountInWindow == charCountMapAnagram.size())
        {
            //handle the match found by adding windowStart 
            resultIndices.push_back(windowStart);
        }


    }
    return resultIndices;
  }
};


int main(int argc, char *argv[]) {
  cout << "ppqp" << "--pq " << endl;
  auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  cout << "abbcabc" << " -- >abc"<< endl;
  result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

