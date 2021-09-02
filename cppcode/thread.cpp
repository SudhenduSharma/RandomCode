#include<iostream>
#include<thread>
//#include<>
using namespace std;
void callable(int val)
{
    std::cout << "callable func " << val << std::endl;
}
class CallableFunctionObject
{
    public :
        void operator()(int val) const
        {
            std::cout << "callable func object " << val << endl;
        }

};
int main()
{
    std::cout << " in main" << std::endl;
    std::thread t1(callable,5);
    CallableFunctionObject  callableFunctionObject;
    std::thread t2(callableFunctionObject,5);
    std::thread t3([]{std::cout<< "Callable Lambda" << std::endl;});
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
