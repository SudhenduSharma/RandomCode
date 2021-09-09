#include <cstdint>
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

auto generator()
{
    calc_data_1 obj;
    return obj;
}

class Consumer
{
    public :
        virtual void Consume(atomic_set&& ) 
        {
            //NYI
        }
};

template<typename T>
class Producer
{
    T* consumer;
    public :
    Producer(T* con = nullptr)
    {
        if(con==nullptr)
        {
            consumer = new Consumer();
        }
        else
            consumer = con;
    }
    public :
        typedef std::pair<uint64_t,uint64_t> key_t;
        std::map<key_t, calc_data_1> map_data_1;
        std::map<key_t, calc_data_2> map_data_2;
        std::map<key_t, calc_data_3> map_data_3;

        void Process(calc_data_1& data_1)
        {
            auto it2 = map_data_2.find({data_1.seq_num,data_1.cat_id});
            if(it2 != map_data_2.end())
            {
                //found in map_2
                //search in map_3
                auto it3 = map_data_3.find({data_1.seq_num,data_1.cat_id});
                if(it3 != map_data_3.end())
                {
                    //match found generate atomic Seq [):
                    atomic_set obj;
                    obj.d1 = data_1;
                    obj.d2 = it2->second;
                    obj.d3 = it3->second;
                    consumer->Consume(std::move(obj));
                }
            }
        }

};

int main()
{
    while(1)
    {
        calc_data_1 obj ;

        Producer<Consumer> producer ;
        producer.Process(obj);

    }


    return 0;
}
