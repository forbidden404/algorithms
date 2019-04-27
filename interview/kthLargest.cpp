#include <bits/stdc++.h>

using namespace std;

int kthLargest(vector<int>& arr, int left, int right, int k) {
    int pivot = arr[right - 1];
    int i = left - 1;
    for (int j = left; j < right - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right - 1]);

    if (i + 1 == k) {
        return arr[i + 1];
    } else if (k < i + 1) {
        return kthLargest(arr, left, i + 1, k);
    } else {
        return kthLargest(arr, i + 1, right, k - (i + 1));
    }
}

int main() {
    vector<int> v{2,6,11,15};
    for (int i = 0; i < v.size(); i++) {
        cout << i+1 << "-th largest: ";
        cout << kthLargest(v, 0, v.size(), v.size() - 1 - i) << endl;
    }

    return 0;
}

