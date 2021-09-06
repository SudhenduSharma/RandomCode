//https://leetcode.com/problems/increasing-decreasing-string/
#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    //auto less_comparator = [] (auto& a ,auto &b){ return a < b; };
    //auto greater_comparator = [] (auto& a ,auto &b){ return a > b; };
    //map<char,int,decltype(less_comparator)> decreasingMap(less_comparator);
    map<char,int> char_map;

    std::string str = "aaaabbbbcccc";
    str = "ab";
    std::string result;
    result.reserve(str.length());

    for(auto& val : str)
    {
        char_map[val]++;
    }
    size_t len = str.length();
    bool order = true;
    while(len)
    {
        //if(order)
        {
            for(auto it = char_map.begin();it!=char_map.end();++it)
            {
                if(it->second)
                {
                    result.push_back(it->first);
                    --it->second;
                    cout << " i " << it->first << " ";
                    //if(!it->second)
                    //    it = char_map.erase(it);
                    //else
                    --len;
                }
            }
                //cout << endl;
        }
        //else
        {
            for(auto it = char_map.rbegin();it!=char_map.rend();++it)
            {
                if(it->second)
                {
                    result.push_back(it->first);
                    --it->second;
                    //if(!it->second)
                        //it = char_map.erase(it);
                      //  it =  decltype(it){ char_map.erase(std::next(it).base())};
                    --len;
                    //cout << " d " << it->first << " ";
                }
            }
                //cout << endl;
        }
    }
    std::cout << endl << result << endl;
    return 0;
}
