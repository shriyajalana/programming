// We'll use built-in list for O(1) splice.
class LRUCache {
    int cap;
    list<pair<int,int>> dll; // key,val - front most recent
    unordered_map<int, list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int capacity): cap(capacity) {}
    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        auto nodeIt = it->second;
        int val = nodeIt->second;
        dll.erase(nodeIt);
        dll.push_front({key, val});
        mp[key] = dll.begin();
        return val;
    }
    void put(int key, int value) {
        if (mp.count(key)) {
            dll.erase(mp[key]);
        } else if (dll.size() == cap) {
            auto last = dll.back();
            mp.erase(last.first);
            dll.pop_back();
        }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};
