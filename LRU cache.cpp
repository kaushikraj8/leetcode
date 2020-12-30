struct Cache {
    int _key;
    int _value;
    Cache(int key = 0, int value = 0) {
        _key = key;
        _value = value;
    }
};

class LRUCache{
    list<Cache> cache;
    unordered_map<int, list<Cache>::iterator> posMap;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (posMap.find(key) == posMap.end()) return -1;
        auto it = posMap[key];
        cache.push_front(*it);
        cache.erase(it);
        posMap[key] = cache.begin();
        return posMap[key]->_value;
    }
    
    void set(int key, int value) {
        if (posMap.find(key) == posMap.end()) {
            cache.push_front(Cache(key, value));
            posMap[key] = cache.begin();
            if (cache.size() > _capacity) {
                Cache lastNode = cache.back();
                posMap.erase(lastNode._key);
                cache.pop_back();
            }
        } else {
            auto it = posMap[key];
            it->_value = value;
            cache.push_front(*it);
            cache.erase(it);
            posMap[key] = cache.begin();
        }
    }
};