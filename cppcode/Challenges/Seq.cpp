#include <cstdint>
#include<iostream>
#include <vector>
#include <map>
using namespace std;
struct calc_data_1 //CD1
{
    uint64_t cat_id;
    uint64_t seq_num;
    std::vector<uint64_t> payload;
};

struct calc_data_2 // CD2
{
    uint64_t cat_id;
    uint64_t seq_num;
    std::vector<uint64_t> payload;
};

struct calc_data_3 // CD3
{
    uint64_t cat_id;
    uint64_t seq_num;
    std::vector<uint64_t> payload;
};

// example same cat_id and same seq_num
struct atomic_set {
    calc_data_1 d1;
    calc_data_2 d2;
    calc_data_3 d3;  
};
using namespace std;
struct Consumer
{
    virtual void consume(atomic_set && matched)
    {
        //black hole
    }
};
template<typename C>
struct Producer
{
    C* consumer_;
    Producer(C* consumer = nullptr)
    {
        if(consumer)
            consumer_ = consumer;
        else
            consumer_ = new Consumer();
    }

    template<typename T>
    void PrintMap(T& map)
    {
        for(auto it = map.begin();it!=map.end();++it)
        {
            cout<< "cat-id => " << it->first << endl;
            cout<< " Seq - Num " << it->first << endl;
            for(auto it_seq = map.begin();it_seq!=map.end();++it_seq)
            {
                cout<< "   " << it->first;
            }
            cout<< endl;
        }
    }
    void Print()
    {
        PrintMap(map_1);
        PrintMap(map_2);
        PrintMap(map_3);
    }
    std::map<uint64_t, std::map<uint64_t,calc_data_1>> map_1;
    std::map<uint64_t, std::map<uint64_t,calc_data_2>> map_2;
    std::map<uint64_t, std::map<uint64_t,calc_data_3>> map_3;

    template <typename T , typename M1 ,typename M2 ,typename M3>
    void match(T&& data1,M1& map1, M2& map2, M3& map3)
    {
        bool matched = false;
        auto it2 = map2.find(data1.cat_id);
        auto it3 = map3.find(data1.cat_id);
        if(it2!= map2.end() && it3!= map3.end())
        {
            auto it2_seq = it2->second.find(data1.seq_num);
            auto it3_seq = it3->second.find(data1.seq_num);
            if(it2_seq!= it2->second.end() && it3_seq != it3->second.end())
            {
                //matched
                atomic_set&& matched_set = generateAtomicSet(std::move(data1),std::move(it2_seq->second),std::move(it3_seq->second));
                consumer_->consume(std::move(matched_set));
                it2->second.erase(it2->second.begin(),++it2_seq);
                it3->second.erase(it3->second.begin(),++it3_seq);
                if(it2->second.empty())
                    map2.erase(it2);
                if(it3->second.empty())
                    map3.erase(it3);
                matched = true;
            }
        }
        if(!matched)
            map1[data1.cat_id][data1.seq_num] = data1;
    }

    atomic_set&& generateAtomicSet(calc_data_1&& data1,calc_data_2&& data2,calc_data_3&& data3)
    {
                return std::move(atomic_set{data1,data2,data3});
    }

    atomic_set&& generateAtomicSet(calc_data_2&& data2,calc_data_1&& data1,calc_data_3&& data3)
    {
                return std::move(atomic_set{data1,data2,data3});
    }
    atomic_set&& generateAtomicSet(calc_data_3&& data3,calc_data_1&& data1,calc_data_2&& data2)
    {
                return std::move(atomic_set{data1,data2,data3});
    }
    void handle(calc_data_1&& data1)
    {
        match(data1,map_1,map_2,map_3);
    }
    void handle(calc_data_2&& data2)
    {
        match(data2,map_2,map_1,map_3);
    }
    void handle(calc_data_3&& data3)
    {
        match(data3,map_3,map_1,map_2);
    }
};

int main()
{
    Consumer* c = new Consumer();
    Producer<Consumer> *producer = new Producer<Consumer>(c);
    producer->handle(std::move(calc_data_1{10001,1}));
    producer->handle(std::move(calc_data_2{10001,1}));
    producer->handle(std::move(calc_data_3{10001,1}));
    producer->Print();
    return 0;
}
