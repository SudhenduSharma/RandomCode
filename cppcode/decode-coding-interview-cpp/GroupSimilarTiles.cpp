#include<iostream>
#include<unordered_map>
#include<vector>
#include<numeric>
#include<functional>
#include<algorithm>
using namespace std;

void groupTitles(std::vector<std::string>& strs, std::vector<std::vector<std::string>> &output)
{
    //assuming all lower case  string
    unordered_map<std::string,vector<string> > result;
    for(auto str : strs)
    {
        vector<int> char_count(26,0);
        for(auto c : str)
        {
            ++char_count[c-'a'];
        }

        auto dash_fold = [](std::string a, int b) {
            return std::move(a) + '-' + std::to_string(b);
        };
        auto vector_string = std::accumulate(std::next(char_count.begin()),char_count.end(),std::to_string(char_count[0]),dash_fold);
        result[vector_string].push_back(str);
        //std::cout << " string -> " << str << " vector --> " << vector_string << endl;
    }
    for(auto it = result.begin();it!= result.end();++it)
    {
        output.push_back(std::move(it->second));
    }
}

int main() {
    // Driver code
    std::vector<std::string> titles = {"duel","dule","speed","spede","deul","cars"};

    std::vector<std::vector<std::string>> output;
    groupTitles(titles, output);
    std::string query = "spede"; 

    // Searching for all titles
    for (auto o : output){
        auto it = std::find (o.begin(), o.end(), query); 
        if (it != o.end()) 
        { 
            //print(o);
        }
    }
}
