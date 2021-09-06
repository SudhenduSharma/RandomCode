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
    //map<char,int,decltype(less_comparator)> decreasingMap(less_comparator);
    map<char,int> decreasingMap;

    std::string str = "aaaabbbbcccc";
    std::string result;
    for(auto& val : str)
    {
        increasingMap[val]++;
        decreasingMap[val]++;
    }
    size_t len = str.length();
    bool order = true;
    while(len)
    {
        if(order)
        {
            for(auto it = increasingMap.begin();it!=increasingMap.end();++it)
            {
                if(it->second)
                {
                    result.push_back(it->first);
                    --it->second;
                    --decreasingMap[it->first];
                    --len;
                    cout << " i " << it->first << " ";
                }
            }
                cout << endl;
        }
        else
        {
            for(auto it = decreasingMap.rbegin();it!=decreasingMap.rend();++it)
            {
                if(it->second)
                {
                    result.push_back(it->first);
                    --it->second;
                    --increasingMap[it->first];
                    --len;
                    cout << " d " << it->first << " ";
                }
            }
                cout << endl;
        }
        order = !order;
    }
    std::cout << result << endl;
    return 0;
}
