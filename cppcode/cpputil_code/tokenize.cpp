#include <sstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;



int toeknizeByLine(string& jobs)
{
    std::stringstream ss(jobs);
    std::string job;

    if (jobs.length())
    {
        while(std::getline(ss,job,'\r')){
            std::cout << "jobs " << job <<endl;
            std::istringstream ss(job);
            std::string token;
            vector<int> jobInfo;
            while(std::getline(ss, token, ',')) {
                int num = std::stoi(token);
                jobInfo.push_back(num);
            }
            for(auto id :jobInfo)
            {
                std::cout<< id << " "; 
            }

        }
    }
    return 0;
}

int main()
{
    std::string jobs= "1,2,3\r\n3,4,5";
    toeknizeByLine(jobs);
    return 0;
}
