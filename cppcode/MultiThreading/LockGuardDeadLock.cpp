#include<iostream>
#include<thread>
#include<map>
#include<mutex>
using namespace std;

struct Resource
{
    mutex lock_;
    map<string,string> r;
};

template<typename T>
void writeURLMap(T& res1,T& res2,string key,string val)
{
    std::lock_guard<std::mutex> lock1(res1.lock_);
    std::lock_guard<std::mutex> lock2(res2.lock_);
    res1.r[key] = val;
    res2.r[key] = val;
}

void R12(Resource& r1,Resource& r2)
{
    string key = "key";
    string val = "val";
    writeURLMap<Resource>(std::ref(r1),std::ref(r2) , key,val);
}
void R21(Resource& r1,Resource& r2)
{
    string key = "key1";
    string val = "val2";
    writeURLMap<Resource>(std::ref(r2),std::ref(r1) , key,val);
}
using namespace std::chrono_literals;
int main()
{
    Resource r1;
    Resource r2;
    while(1)
    {
        std::thread t1(R12,std::ref(r1),std::ref(r2));
        std::thread t2(R21,std::ref(r1),std::ref(r2));
        t1.join();
        t2.join();
        std::cout << "if it's not printing then deadlock" << endl;
        std::cout << endl;
    }

    return 0;
}


