class LRUCache {
private:
    int capacity;
    list<pair<int,int>> cache;
    unordered_map <int, list<pair<int,int>>::iterator> map;
public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        auto it = map.find(key);
        if(it == map.end()) return -1;
        cache.splice(cache.begin(),cache, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = map.find(key);
        if(it != map.end()){
        it->second->second = value;
        cache.splice(cache.begin(),cache, it->second);
        return;
        }

        if(cache.size() == capacity){
            map.erase(cache.back().first);
            cache.pop_back();
        }
        cache.push_front({key,value});
        map[key] = cache.begin();
        return;
    }
};
