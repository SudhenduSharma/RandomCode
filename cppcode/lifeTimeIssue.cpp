// lifetimeIssues.cpp

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono_literals; 
int main(){
    
  std::cout << "Begin:" << std::endl;               

  std::string mess{"Child thread"};

  std::thread t([&mess]{ std::cout << mess << std::endl;});
  t.detach();                                   
  
  std::cout << "End:" << std::endl;             
  std::this_thread::sleep_for(2000ms);
}
