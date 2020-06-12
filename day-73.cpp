/*
  Insert Delete GetRandom O(1)


Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
*/

// Average O(1) implementation with vector and map
class RandomizedSet {
   public:
    /** Initialize your data structure here. */
    unordered_map<int, int> hashMap;
    vector<int> customSet;
    RandomizedSet() {
        hashMap = unordered_map<int, int>();
        customSet = vector<int>();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashMap.count(val) > 0) return false;
        customSet.push_back(val);
        hashMap[val] = customSet.size() - 1;
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hashMap.count(val) == 0) return false;
        int idx = hashMap[val];
        hashMap[customSet.back()] = idx;
        hashMap.erase(val);
        swap(customSet[idx], customSet.back());
        customSet.pop_back();

        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return customSet[rand() % customSet.size()];
    }
};
