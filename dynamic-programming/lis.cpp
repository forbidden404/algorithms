#include <bits/stdc++.h>

using namespace std;

vector<int> longestIncreasingSubsequence(vector<int>& arr) {
    vector<int> predecessor(arr.size());
    vector<int> memo(arr.size()+1);

    int longest = 0;
    for (int i = 0; i < arr.size(); i++) {
        int low = 1;
        int high = longest;
        while (low <= high) {
            int mid = ceil((low + high)/2.0);
            if (arr[memo[mid]] <= arr[i]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        int newLongest = low;

        predecessor[i] = memo[newLongest - 1];
        memo[newLongest] = i;

        if (newLongest > longest) {
            longest = newLongest;
        }
    }

    vector<int> answer(longest);
    int k = memo[longest];
    for (int i = longest - 1; i >= 0; i--) {
        answer[i] = arr[k];
        k = predecessor[k];
    }

    return answer;
}

int main() {
    vector<int> v{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    auto r = longestIncreasingSubsequence(v);
    for (auto n : r) { cout << n << ", "; }
    cout << endl;
    return 0;
}
