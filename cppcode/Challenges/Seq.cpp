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
struct Consumer
{
    virtual void handle(atomic_set&& val)
    {
       cout << "handle Consumer" << endl;

    }

};
template <typename C>
struct Producer
{
    //TODO use smart pointer instead
    C * consumer_;
    Producer(Consumer* consumer = nullptr)
    {
        if(consumer)
            consumer_= consumer;
        else
            consumer_ = new Consumer();
    }
    typedef uint64_t cat_id_t ;
    std::map<cat_id_t, map<uint64_t , calc_data_1>> map_1;
    std::map<cat_id_t, map<uint64_t , calc_data_2>> map_2;
    std::map<cat_id_t, map<uint64_t , calc_data_3>> map_3;
    template<typename T>
    void PrintMap(T &map)
    {
        for(auto it = map.begin();it!= map.end(); ++it)
        {
            cout << "cat_id --> " << it->first << endl;
            for(auto it_seq = it->second.begin();it_seq!= it->second.end(); ++it_seq)
            {
                cout << "       seq-> " << it_seq->first << "  ";
            }
            cout << endl << " ----- " << endl;
        }
    }

    void Print()
    {
        cout << endl << " --- MAP-1 --- " << endl;
        PrintMap(map_1);
        cout << endl << " --- MAP-2 --- " << endl;
        PrintMap(map_2);
        cout << endl << " --- MAP-3 --- " << endl;
        PrintMap(map_3);

    }

    //TODO handle const and temporary using universal ref
    template<typename T1, typename M1,typename M2,typename M3>
    void match(T1&& calc_data ,M1& map1 , M2& map2,M3& map3)
    {
        auto it2 = map2.find(calc_data.cat_id);
        auto it3 = map3.find(calc_data.cat_id);
        bool matched = false;
        if(it2!=map2.end() && it3!=map3.end())
        {
            auto it_v2 = it2->second.find(calc_data.seq_num);
            auto it_v3 = it3->second.find(calc_data.seq_num);
            if(it_v2!= it2->second.end() && it_v3 != it3->second.end())
            {
                //match
                atomic_set set = generate(calc_data,it_v2->second, it_v3->second);
                //TODO handle in new theread to avoid blocking in case consumer handle is blocking
                consumer_->handle(std::move(set));
                //assuming that seq number will not repeated , removing all previous sequence, when next match happen current sequence will be automatically deleted.
                it2->second.erase(it2->second.begin(),++it_v2);
                it3->second.erase(it3->second.begin(),++it_v3);
                std::cout << "match found \n" << endl; 
                matched = true;
            }
        }
        if(!matched)
            map1[calc_data.cat_id][calc_data.seq_num]= calc_data;
    }

    atomic_set generate(calc_data_1& data1, calc_data_2& data2,calc_data_3& data3)
    {
        //TODO std::move
        return atomic_set{data1,data2,data3};
    }

    atomic_set generate(calc_data_2& data2, calc_data_1& data1,calc_data_3& data3)
    {
        return atomic_set{data1,data2,data3};
    }

    atomic_set generate(calc_data_3& data3, calc_data_1& data1,calc_data_2& data2)
    {
        return atomic_set{data1,data2,data3};
    }

    void handleMessage(calc_data_1&& data)
    {
        match(data,map_1,map_2,map_3);
    }
    void handleMessage(calc_data_2&& data)
    {
        match(data,map_2,map_1,map_3);
    }
    void handleMessage(calc_data_3&& data)
    {
        match(data,map_3,map_1,map_2);
    }

};

int main()
{
    Consumer* c = new Consumer();    
    Producer<Consumer> *producer = new Producer<Consumer>(c);
    producer->handleMessage(std::move(calc_data_1{10001,1}));
    producer->handleMessage(std::move(calc_data_2{10001,1}));
    producer->handleMessage(std::move(calc_data_1{1001,1}));
    producer->handleMessage(std::move(calc_data_2{1001,1}));
    producer->Print();
    producer->handleMessage(std::move(calc_data_3{10001,1}));
    producer->Print();
    producer->handleMessage(std::move(calc_data_3{1001,1}));
    producer->Print();
    return 0;
}
