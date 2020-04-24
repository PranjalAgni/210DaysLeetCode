/*
Question: Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache(2)

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);     // returns 1
cache.put(3, 3);  // evicts key 2
cache.get(2);     // returns -1 (not found)
cache.put(4, 4);  // evicts key 1
cache.get(1);     // returns -1 (not found)
cache.get(3);     // returns 3
cache.get(4);     // returns 4
*/

class LRUCache {
   public:
    unordered_map<int, pair<int, list<int>::iterator>> hashMap;
    int mCapacity;
    list<int> keys;
    LRUCache(int capacity) {
        mCapacity = capacity;
    }

    int get(int key) {
        if (hashMap.find(key) != hashMap.end()) {
            keys.erase(hashMap[key].second);
            keys.push_front(key);
            hashMap[key].second = keys.begin();
            return hashMap[key].first;
        }

        return -1;
    }

    void put(int key, int value) {
        if (hashMap.find(key) != hashMap.end()) {
            keys.erase(hashMap[key].second);
            keys.push_front(key);
        } else {
            if (keys.size() == mCapacity) {
                hashMap.erase(keys.back());
                keys.pop_back();
            }

            keys.push_front(key);
        }

        hashMap[key] = make_pair(value, keys.begin());
    }
};
