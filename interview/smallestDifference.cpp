#include <bits/stdc++.h>

using namespace std;

int smallestDifference(vector<int>& arr1, vector<int>& arr2) {
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
    int index1 = 0;
    int index2 = 0;
    int smallest = INT_MAX;

    while (index1 < arr1.size() && index2 < arr2.size()) {
        int actual = arr1[index1] - arr2[index2];
        if (actual < 0) actual *= -1;
        smallest = min(actual, smallest);

        if (arr1[index1] < arr2[index2]) {
            index1++;
        } else {
            index2++;
        }
    }

    return smallest;
}

int main() {
    vector<int> v1{1, 3, 15, 11, 2};
    vector<int> v2{23, 127, 235, 19, 8};
    cout << smallestDifference(v1, v2) << endl;
    return 0;
}
