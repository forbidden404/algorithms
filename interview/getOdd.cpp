#include <bits/stdc++.h>

using namespace std;

int getOdd(vector<int>& arr) {
    int answer = 0;
    for (auto num : arr) answer ^= num;
    return answer;
}

int main() {
    vector<int> v{1, 2, 3, 1, 2, 3, 1};
    cout << getOdd(v) << endl;
    return 0;
}