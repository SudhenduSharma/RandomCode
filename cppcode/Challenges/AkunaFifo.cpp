// the queue shall only contain a fixed capacity of elements
// the queue shall only contain homogeneous objects
// the queue shall support any kind of class as the elements
// the queue shall support push and pop one object
// the queue shall also provide interface to query it's current size
// FIFO Container

#include<iostream>
#include<vector>
#include <cassert>

using namespace std;
struct EmptyException : public exception
{
    
};
struct FullException : public exception
{
    
};
template<typename T,size_t size>
class MyQueue
{
    MyQueue()
    {
        front_ = 0;
        back_ = 0;
        capacity_ = size;
        current_size = 0;
    }

    void push(T obj)
    {
        if(current_size < capacity_)
        {
            if(front_ != capacity_-1 && front_ != 0)
             {
                 ++front_;
                 ++current_size;
             }   
            else
            {
                front_ = 0;
                ++current_size;
            }
            container[front_] = obj;
        }
        else 
        {
            throw FullException();
    
        }
    }

    T pop()
    {
        if(current_size == 0)
        {
            
            throw EmptyException();
        }
        
        if(current_size != 0 && back_ != 0)
        {
            --current_size;
            return container[back_--];
            
        }
        else {
            back_ = capacity_-1;
            --current_size;
            return container[back_];
        }
    }
  
    size_t front_;
    size_t back_;
    size_t current_size;
    size_t capacity_;
    
    private :
        T container[size];
};



struct Foo {
    int data;
};

int main()
{
    /*
    
    MyQueue<Foo, 2> q;
    assert(q.size_ == 0);
    
    q.push(Foo{1});
    assert(q.size_ == 1);
    
    q.push(Foo{2});
    assert(q.size() == 2);
    
    assert(q.pop().data == 1);
    assert(q.size() == 1);
    
    q.push(Foo{3});
    assert(q.size() == 2);
    
    assert(q.pop().data == 2);
    assert(q.size() == 1);
    
    assert(q.pop().data == 3);
    assert(q.size() == 0);
    */
    
    return 0;
}
