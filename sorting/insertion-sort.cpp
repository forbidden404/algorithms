#include <bits/stdc++.h>

using namespace std;

void insertSort(vector<int>& arr) {
    for (int j = 1; j < arr.size(); j++) {
        int key = arr[j];
        int i = j - 1;
        for (; i >= 0 && arr[i] > key; i--) {
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

    insertSort(v);

    printVector(v);

    return 0;
}
