//https://leetcode.com/problems/increasing-decreasing-string/
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    auto less_comparator = [] (auto& a ,auto &b){ return a < b; };
    auto greater_comparator = [] (auto& a ,auto &b){ return a > b; };
    map<char,int> increasingMap;
    map<char,int,decltype(greater_comparator)> decreasingMap(greater_comparator);

    std::string str = "abcdefg";
    std::string result;
    for(auto& val : str)
    {
        increasingMap[val]++;
        decreasingMap[val]++;
    }
    for(auto& pair : increasingMap)
    {
        cout << pair.first << " ";
    }
    cout << endl;

    for(auto& pair : decreasingMap)
    {
        cout << pair.first << " ";
    }
    cout << endl;
    return 0;
}
