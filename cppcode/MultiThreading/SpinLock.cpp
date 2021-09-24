#include<iostream>
#include<atomic>
#include<thread>
class SpinLock{
    public :
        SpinLock():flag(ATOMIC_FLAG_INIT){}
        void lock()
        {
            while(flag.test_and_set())
            {
                //spinning
            }
        }
        void unlock()
        {
            flag.clear();
        }
        std::atomic_flag flag;
        
};
SpinLock spin;
void workOnResource(){
    spin.lock();
    //critical section
    std::this_thread::sleep_for(std::chrono::milliseconds(200000));
    spin.unlock();
    std::cout << "Work done" << std::endl;
}
int main()
{
    std::thread t(workOnResource);
    std::thread t2(workOnResource);
    std::thread t3(workOnResource);
    std::thread t4(workOnResource);

    t.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}
