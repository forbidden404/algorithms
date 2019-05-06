#include <bits/stdc++.h>

using namespace std;

// O(2^k)
void getAllLengths(int k, int total, int shorter, int longer, unordered_set<int>& lengths) {
    if (k == 0) {
        lengths.insert(total);
        return;
    }
    getAllLengths(k - 1, total + shorter, shorter, longer, lengths);
    getAllLengths(k - 1, total + longer, shorter, longer, lengths);
}

unordered_set<int> allLengths(int k, int shorter, int longer) {
    unordered_set<int> lengths;
    getAllLengths(k, 0, shorter, longer, lengths);
    return lengths;
}

// O(K^2)
void getAllLengths(int k, int total, int shorter, int longer, unordered_set<int>& lengths, unordered_set<string>& visited) {
    if (k == 0) {
        lengths.insert(total);
        return;
    }

    string key = to_string(k) + " " + to_string(total);
    if (visited.find(key) != visited.end()) return;

    getAllLengths(k - 1, total + shorter, shorter, longer, lengths, visited);
    getAllLengths(k - 1, total + longer, shorter, longer, lengths, visited);
    visited.insert(key);
}

unordered_set<int> allLengthsMemo(int k, int shorter, int longer) {
    unordered_set<int> lengths;
    unordered_set<string> visited;
    getAllLengths(k, 0, shorter, longer, lengths, visited);
    return lengths;
}

// O(n)
unordered_set<int> allLengthsLinear(int k, int shorter, int longer) {
    unordered_set<int> lengths;
    for (int nShorter = 0; nShorter <= k; nShorter++) {
        int nLonger = k - nShorter;
        int length = nShorter * shorter + nLonger * longer;
        lengths.insert(length);
    }
    return lengths;
}
