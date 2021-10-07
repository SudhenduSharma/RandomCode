#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LRUCache
{
    public :
        LRUCache()
        {
        }
        auto access(int val)
        {
            printCache();
            cout << "accessing " << val << endl;
            auto it_cache = cache_.find(val);
            if(it_cache != cache_.end())
            {
                auto it = cache_[val];
                recent_items_.erase(it);
                recent_items_.push_back(val);
                cache_[val] = --recent_items_.end();
            }
            else
            {
                if(capacity_ == cache_.size())
                {
                    auto front = recent_items_.front();
                    recent_items_.pop_front();
                    auto it = cache_.find(front);
                    cache_.erase(it);
                }
                recent_items_.push_back(val);
                cache_[val] = --recent_items_.end();
            }
            cout << "accessed " << val << endl;
            printCache();
            return cache_[val];
        }
        void printCache()
        {
            cout << "printing cache list " << endl;
            for(auto val : recent_items_)
            {
                cout << val << " ";
            }

            cout << endl;
        }

        int capacity_;
    private :
        typedef std::list<int>::iterator list_it_type;
        std::list<int> recent_items_;
        std::unordered_map<int,list_it_type> cache_;
};

int main(){

    LRUCache cache;
    cache.capacity_ = 3;
	cout << "Size of the cache:  " << cache.capacity_ << endl;

	cache.access(1);
	cache.access(2);
	cache.access(3);
	cache.access(1);
	cache.access(4);
	cache.access(5);
	cache.access(5);
	cache.access(1);
	cache.access(6);
	cache.access(4);

	return 0;
}
