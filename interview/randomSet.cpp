#include <bits/stdc++.h>

using namespace std;

int rand(int lower, int higher) {
    return lower + (rand() % (higher - lower + 1));
}

vector<int> randomSetRecursively(vector<int>& arr, int m, int i) {
    if (i + 1 == m) {
        vector<int> v(arr.begin(), arr.begin() + m);
        return v;
    } else {
        auto subset = randomSetRecursively(arr, m, i - 1);
        int k = rand(0, i);
        if (k < m)
            subset[k] = arr[i];
        return subset;
    }
    return {};
}

vector<int> randomSet(vector<int> &arr, int m) {
    vector<int> subset(arr.begin(), arr.begin()+m);
    for (int i = m; i < arr.size(); i++) {
        int k = rand(0, i);
        if (k < m) {
            subset[k] = arr[i];
        }
    }
    return subset;
}

int main() {
    srand(time(NULL));

    cout << "Given array: ";
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto num : v) cout << num << " ";
    cout << endl;

    auto a = randomSet(v, 7);
    cout << "Random set with 7 elements: ";
    for (auto num : a) cout << num << " ";
    cout << endl;

    return 0; 
}