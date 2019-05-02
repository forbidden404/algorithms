#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int> &v) {
    if (v.empty()) return 0;
    
    vector<int> oneBit;
    vector<int> zeroBit;

    for (auto num : v) {
        if (num % 2 == 0) {
            zeroBit.push_back(num >> 1);
        } else {
            oneBit.push_back(num >> 1);
        }
    }

    if (zeroBit.size() <= oneBit.size()) {
        int v = missingNumber(zeroBit);
        return v << 1;
    } else {
        int v = missingNumber(oneBit);
        return (v << 1) | 1;
    }
}

int main() {
    vector<int> v{0,8,1,2,4,5,6,7};
    cout << missingNumber(v) << endl;
    return 0;
}