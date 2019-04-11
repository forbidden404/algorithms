#include <bits/stdc++.h>

using namespace std;

bool prime[1000005];
void findPrime() {
    memset(prime, true, sizeof(prime));
    prime[1] = false;

    for (int p = 2; p * p <= 1000000; p++) {
        if (prime[p]) {
            for (int i = p * 2; i <= 1000000; i += p)
                prime[i] = false;
        }
    }
}

int lenOfLongSubarr(int arr[], int n) {
    unordered_map<int, int> hashMap;
    int sum = 0, maxLength = 0;

    for (int i = 0; i < n; i++) {
        sum += prime[arr[i]] == 0 ? -1 : 1;

        if (sum == 1)
            maxLength = i + 1;

        else if (hashMap.find(sum) == hashMap.end())
            hashMap[sum] = i;

        if (hashMap.find(sum - 1) != hashMap.end()) {
            if (maxLength < (i - hashMap[sum - 1]))
                maxLength = i - hashMap[sum - 1];
        }
    }

    return maxLength;
}

int main() {
    findPrime();

    int arr[] = { 1, 9, 3, 4, 5, 6, 7, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << lenOfLongSubarr(arr, n) << endl;
    return 0;
}
