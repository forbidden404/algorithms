#include <bits/stdc++.h>

using namespace std;

int getEven(vector<int>& arr) {
    unordered_map<int, int> count;
    for (auto num : arr) {
        count[num]++;
    }
    for (auto p : count) {
        if (p.second % 2 == 0) return p.first;
    }
    return 0;
}

int getEven2(vector<int>& arr) {
    unordered_set<int> unique;
    int answer = 0;

    for (auto num : arr) {
        unique.insert(num);
        answer ^= num;
    }

    for (auto num : unique) {
        answer ^= num;
    }

    return answer;
}

int main() {
    vector<int> v1{1,2,3,1};
    vector<int> v2{2,3,4,2};
    cout << getEven(v1) << endl;
    cout << getEven2(v2) << endl;
    return 0;
}