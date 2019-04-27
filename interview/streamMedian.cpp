#include <bits/stdc++.h>

using namespace std;

class StreamMedian {
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int N = 0;

public:
    void insert(int num) {
        if (N % 2 == 0) {
            maxHeap.push(num);
            N++;
            if (minHeap.empty()) return;
            if (maxHeap.top() > minHeap.top()) {
                auto toMin = maxHeap.top(); maxHeap.pop();
                auto toMax = minHeap.top(); minHeap.pop();
                maxHeap.push(toMax);
                minHeap.push(toMin);
            }
        } else {
            maxHeap.push(num);
            auto toMin = maxHeap.top(); maxHeap.pop();
            minHeap.push(toMin);
            N++;
        }
    }

    double getMedian() {
        if (N % 2 == 0)
            return (maxHeap.top() + minHeap.top())/2.0;
        else
            return maxHeap.top();
    }
};

int main() {
    StreamMedian s;
    s.insert(1);
    s.insert(2);
    cout << s.getMedian() << endl;
    s.insert(3);
    cout << s.getMedian() << endl;
    return 0;
}
