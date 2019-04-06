#include <bits/stdc++.h>

using namespace std;

typedef bool (*cmp) (int a, int b);

bool decreasing(int a, int b) {
    return a < b;
}

bool increasing(int a, int b) {
    return a > b;
}

void insertSort(vector<int>& arr, cmp f) {
    for (int j = 1; j < arr.size(); j++) {
        int key = arr[j];
        int i = j - 1;
        for (; i >= 0 && f(arr[i], key); i--) {
            arr[i + 1] = arr[i];
        }
        arr[i + 1] = key;
    }
}

void printVector(vector<int> v) {
    for (auto num : v) {
        cout << num << ' ';
    } 
    cout << endl;
}


int main() {
    vector<int> v{5,2,4,6,1,3};

    printVector(v);

    insertSort(v, increasing);

    printVector(v);

    insertSort(v, decreasing);

    printVector(v);

    return 0;
}
