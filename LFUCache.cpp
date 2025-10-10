class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int, pair<int,int>> valFreq; // key -> (value, freq)
    unordered_map<int, list<int>> freqList; // freq -> keys (recent front)
    unordered_map<int, list<int>::iterator> keyIter; // key -> iterator in freqList[f]
public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {}
    int get(int key) {
        if (!valFreq.count(key)) return -1;
        int val = valFreq[key].first;
        int f = valFreq[key].second;
        // remove from current freq list
        freqList[f].erase(keyIter[key]);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) ++minFreq;
        }
        // add to freq+1
        ++f;
        freqList[f].push_front(key);
        keyIter[key] = freqList[f].begin();
        valFreq[key].second = f;
        return val;
    }
    void put(int key, int value) {
        if (capacity <= 0) return;
        if (valFreq.count(key)) {
            valFreq[key].first = value;
            get(key); // update freq via get
            return;
        }
        if (valFreq.size() == capacity) {
            // evict least frequently used -> minFreq list's back (least recent)
            int evictKey = freqList[minFreq].back();
            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
            valFreq.erase(evictKey);
            keyIter.erase(evictKey);
        }
        // insert new key with freq 1
        valFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};
