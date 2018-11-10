class LRUCache {
private:
    list<pair<int,int>> LRUList; // for LRU order
    unordered_map<int, list<pair<int, int>>::iterator> cache; // for O(1) access
    
public:
    LRUCache(int capacity) : 
        LRUList(capacity),
        cache() { }
    
    /**
     * Get the value (will always be positive) of the key if the key exists 
     * in the cache, otherwise return -1.
     */
    int get(int key) {
        // if key is present, move element to the front of the cache and 
        // return its value
        if (cache.count(key) > 0) {  
            LRUList.push_front(*cache[key]);
            LRUList.erase(cache[key]);
            cache[key] = LRUList.begin();
            return (*cache[key]).second; // return value of list element
        } else { // not present -> return -1
            return -1;   
        }
    }
    
    /**
     * Set or insert the value if the key is not already present. When the cache
     * reached its capacity, it should invalidate the least recently used item 
     * before inserting a new item.
     */
    void put(int key, int value) {
        if (cache.count(key) == 0) {
            // remove least recently used key from cache
            cache.erase(LRUList.back().first);
            // remove least recently element from list
            LRUList.pop_back();
        } else {
            LRUList.erase(cache[key]);
        }
        LRUList.push_front(pair<int,int>(key, value));
        cache[key] = LRUList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
