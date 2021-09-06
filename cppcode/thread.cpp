#include<iostream>
#include<chrono>
#include<thread>
//#include<>
using namespace std;
using namespace std::chrono_literals;
volatile int check = 1;
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

struct A
{
    void foo(){cout << "foo" << endl;}
    void bar(){
        std::thread t1(&A::foo,this);
        t1.join();
        cout << "foo" << endl;
    }

};

struct A1
{
    std::thread t1;
    std::thread t2;
    std::thread t3;
    int memberInt;
    template<typename T>
    void boo(T& obj)
    {
        cout << "Inside T " << obj << " " << __LINE__ << endl;
    }
    void foo(int x)
    {
        cout << endl << "foo " << x << endl;
        while(check)
        {
            std::this_thread::sleep_for(200ms);    
            //std::cout << "in foo " << check << __LINE__ << endl;
        }
    }
    void bar2()
    {
        auto callable = [&](){
            this->foo(40);
        };
        t3 =std::thread(callable);
    }
    void bar1()
    {
        memberInt = 11;
        t2 = std::thread(&A1::boo<int>,this,std::ref(memberInt));
    }
    void bar()
    {
        t1 = std::thread(&A1::foo,this,6);
        //std::cout << " after bar " << __LINE__ << endl;
    }
    ~A1()
    {
        t1.join();
        t2.join();
        t3.join();
    }
};
int main()
{
    std::cout << " in main" << std::endl;
    std::thread t1(callable,5);
    CallableFunctionObject  callableFunctionObject;
    std::thread t2(callableFunctionObject,5);
    std::thread t3([]{std::cout<< "Callable Lambda" << std::endl;});
    A obj;
    obj.bar();

    A1 obj1;
    obj1.bar();
    obj1.bar1();
    obj1.bar2();
    std::this_thread::sleep_for(2000ms);    

    check = 0;
    //obj.t1.join();
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
