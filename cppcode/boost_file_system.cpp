#include<iostream>
#include<boost/filesystem.hpp>

int main()
{
    std::string str("/Users/sudhendu.sharma/Code/interview/cppcode");
    boost::filesystem::path p(str.c_str());
    if(boost::filesystem::is_regular_file(p))
    {
        std::cerr<<"Hi"<<std::endl;
    }
    if(boost::filesystem::exists(p))
    {
        std::cerr<<"Hello"<<std::endl;
    }
    int x;
    std::cin >> x;
}
