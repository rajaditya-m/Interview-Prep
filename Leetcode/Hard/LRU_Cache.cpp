typedef std::list<int>::iterator ListIt;
typedef std::pair<int,ListIt> Node;
typedef std::unordered_map<int,Node> HashMap;

class LRUCache{
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        load = 0;
    }
    
    int get(int key) {
        auto it = store.find(key);
        if(it==store.end())
            return -1;
        else
        {
            auto &kv = it->second;
            access.erase(kv.second);
            access.push_front(key);
            kv.second = access.begin();
            return kv.first;
        }
    }
    
    void set(int key, int value)
    {
        auto it = store.find(key);
        if(it==store.end())
        {
            if(load==capacity_)
            {
                //Need to delete
                store.erase(access.back());
                access.pop_back();
                access.push_front(key);
                store[key] = std::pair<int,ListIt>(value,access.begin());
                
            }
            else
            {
                access.push_front(key);
                store[key] = std::pair<int,ListIt>(value,access.begin());
                load++;
            }
            
        }
        else
        {
            auto &kv = it->second;
            access.erase(kv.second);
            access.push_front(key);
            kv.second = access.begin();
            kv.first = value;
        }
    }
    
    HashMap store;
    std::list<int> access;
    int capacity_;
    int load;
};