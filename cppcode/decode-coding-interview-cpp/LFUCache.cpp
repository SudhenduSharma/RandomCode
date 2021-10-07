#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

struct Node
{
    int key;
    std::string val;
    int freq;
};

class LFUCache
{
    public :
        LFUCache()
        {
            min_freq_= 0;
            max_freq_= 0;
        }
        auto get(int key)
        {
            auto it = cache_.find(key);
            if(it == cache_.end())
                return "";
            //found in cache
            int node_freq = cache_[key].freq;
            //move node in freq map
            if(freq_map_[node_freq].size() == 1)
            {
                freq_map_.erase(node_freq);
                if(min_freq_ == node_freq)
                {
                    min_freq_++;
                }
            }
            else
            {
                freq_map_[node_freq].erase(key);
            }
            cache_[key].freq++;
            freq_map_[node_freq+1].erase(key);

        }

        auto set(int key,std::string& val)
        {
        }

        void printCache()
        {

        }

        int capacity_;
        int min_freq_;
        int max_freq_;
    private :
        std::unordered_map<int,list<Node>> freq_map_;
        std::unordered_map<int,Node> cache_;
};

int main(){

    LFUCache cache;
    cache.capacity_ = 3;
	cout << "Size of the cache:  " << cache.capacity_ << endl;


	return 0;
}
