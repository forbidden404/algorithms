#include <bits/stdc++.h>

using namespace std;

int longestSubarray(int arr[], int n) {
    int sum = 0, maxLen = 0;

    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        sum += arr[i] == 0 ? -1 : 1;

        if (sum == 1) maxLen = i + 1;

        else if (um.find(sum) == um.end()) {
            um[sum] = i;
        }

        if (um.find(sum-1) != um.end()) {
            if (maxLen < i - um[sum - 1])
                maxLen = i = um[sum - 1];
        }
    }

    return maxLen;
}

int main() {
    int arr[] = { 0, 1, 1, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length = " << longestSubarray(arr, n) << endl;
    return 0;
}
