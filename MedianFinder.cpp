
class MedianFinder {
    priority_queue<int> lo; // max-heap
    priority_queue<int, vector<int>, greater<int>> hi; // min-heap
public:
    MedianFinder() {}
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top()); lo.pop();
        if (lo.size() < hi.size()) { lo.push(hi.top()); hi.pop(); }
    }
    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};
