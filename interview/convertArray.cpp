#include <bits/stdc++.h>

using namespace std;

int getIndex(int currentIndex, int N) {
    return (currentIndex % 3) * N + (currentIndex/3);
}

void convertArray(vector<int>& arr) {
    int n = arr.size() / 3;
    for (int i = 0; i < arr.size(); i++) {
        int swapIndex = getIndex(i, n);
        while (swapIndex < i)
            swapIndex = getIndex(swapIndex, n);
        swap(arr[i], arr[swapIndex]);
    }
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    convertArray(v);
    for (auto num : v) { cout << num << " "; }
    cout << endl;
    return 0;
}
