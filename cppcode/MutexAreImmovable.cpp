#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>


std::map<std::string, std::string> g_pages;
std::mutex g_pages_mutex;

void save_page(const std::string &url)
{
    // simulate a long page fetch
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::string result = "fake content";

    std::lock_guard<std::mutex> guard(g_pages_mutex);
    g_pages[url] = result;
}
class A
{
    public :
        std::mutex aMutex;

};
#include<map>
#include <memory>

using namespace std;
class B
{
    public :
        map<string,mutex> mapOfMutex; 
};

std::map<string,unique_ptr<string>> map_

int main()
{
    B obj;
    obj.mapOfMutex.emplace(std::string("a"), std::mutex());
    //auto& pair = obj.mapOfMutex[0];

    //B ob1 = obj; //mutex are immovable and non copyable

    std::thread t1(save_page, "http://foo");
    std::thread t2(save_page, "http://bar");
    t1.join();
    t2.join();

    // safe to access g_pages without lock now, as the threads are joined
    for (const auto &pair : g_pages) {
        std::cout << pair.first << " => " << pair.second << '\n';
    }
}

