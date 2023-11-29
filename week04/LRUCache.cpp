class LRUCache
{
private:
 int cap;
    list<int> lru;
    unordered_map<int, list<int>::iterator> k_loc;
    unordered_map<int, int> k_v;

    void updateLRU(int key)
    {
      if (k_v.count(key))
        {
            lru.erase(k_loc[key]);
        }
        lru.push_front(key);
        k_loc[key] = lru.begin();
    }
    void evict()
    {
        k_v.erase(lru.back());
        k_loc.erase(lru.back());
        lru.pop_back();
    }

public:
    LRUCache(int capacity)
    {
        cap = capacity;
    }
    // TC: O(1)
    // MC: O(capacity)
    int get(int key)
    {
        if (k_v.count(key) == 0) {
            return -1;
        }
        updateLRU(key);
        return k_v[key];
    }
    // TC: O(1)
    // MC: O(capacity)
    void put(int key, int value)
    {
        if (k_v.count(key) == 0 && lru.size() == cap)
        {
            evict();
        }
        updateLRU(key);
        k_v[key] = value;
    }
};
