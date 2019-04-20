// Given an integer array, output all pairs that sum up to a specific value k.
#include <bits/stdc++.h>

using namespace std;

// O(n*log(n))
void pairSum1(vector<int>& arr, int k) {
    if (arr.size() < 2) // Array has not enough elements to make pairs
        return;

    sort(arr.begin(), arr.end()); // Average time: O(n*log(n))

    int left = 0;
    int right = arr.size() - 1;

    while (left < right) { // Time: O(n)
        int sum = arr[left] + arr[right];
        if (sum == k) {
            cout << arr[left] << ", " << arr[right] << endl;
            left++;
        } else if (sum < k) {
            left++;
        } else {
            right--;
        }
    }

    // Time complexity: O(n*log(n)) + O(n) = O(n + n*log(n)) = O(n*log(n))
}

// O(n)
void pairSum(vector<int>& arr, int k) {
    if (arr.size() < 2)
        return;

    unordered_set<int> seen; // Unordered_set has Search and Insertion with O(1) in average
    set<pair<int, int>> output; // Avoid duplicates
    for (auto num : arr) { // Time: O(n)
        int target = k - num;
        const bool is_in = seen.find(target) != seen.end(); // Average time: O(1)
        if (is_in) {
            output.insert(make_pair(min(num, target), max(num, target)));
        }
        seen.insert(num);
    }

    for (auto num : output) {
        cout << num.first << ", " << num.second << endl;
    }

    // Time complexity: O(n) * (O(1) + O(1)) = O(n)
}

int main() {
    vector<int> v{5,6,4,7,3,4,5,6,3,1,2,4};
    pairSum1(v, 6);
    cout << endl;
    pairSum(v, 6);
    return 0;
}
