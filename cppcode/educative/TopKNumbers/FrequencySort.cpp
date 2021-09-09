using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

class FrequencySort {
    class CompareWordFreq
    {
        public :
            bool operator() (const pair<char,int>& x, const pair<char,int>& y)
            {
                return x.second < y.second;
            }

    };
 public:
  static string sortCharacterByFrequency(const string &str) {
    string sortedString = "";
    unordered_map<char,int> charFreqMap;
    for(auto c : sortedString)
    {
        ++charFreqMap[c];
    }
    priority_queue<pair<char,int>,vector<pair<char,int>>,CompareWordFreq> maxHeap;
    for(auto charFreq : charFreqMap)
    {
        maxHeap.push(charFreq);
    }

    return sortedString;
  }
};

int main(int argc, char *argv[]) {
  string result = FrequencySort::sortCharacterByFrequency("Programming");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;

  result = FrequencySort::sortCharacterByFrequency("abcbab");
  cout << "Here is the given string after sorting characters by frequency: " << result << endl;
}
