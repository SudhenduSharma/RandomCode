// http://jakascorner.com/blog/2016/02/lock_guard-and-unique_lock.html
// https://www.modernescpp.com/index.php/c-core-guidelines-be-aware-of-the-traps-of-condition-variables

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>

std::mutex mutex_;
std::condition_variable condVar;

bool dataReady{false};


void waitingForWork(){

    std::cout << "Worker: Waiting for work." << std::endl;

    std::unique_lock<std::mutex> lck(mutex_);
    condVar.wait(lck);                          
    // do the work
    std::cout << "Work done." << std::endl;

}

void setDataReady(){

    std::cout << "Sender: Data is ready."  << std::endl;
    condVar.notify_one();                        

}

int main(){

  std::cout << std::endl;

  std::thread t1(setDataReady);
  std::thread t2(waitingForWork);               

  t1.join();
  t2.join();

  std::cout << std::endl;
  
}
