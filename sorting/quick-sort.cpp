#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i + 1;
}

void quicksort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int q = partition(arr, left, right);
        quicksort(arr, left, q-1);
        quicksort(arr, q+1, right);
    }
}

void printArr(vector<int> &arr) {
    for (auto n : arr) {
        cout << n << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> v{1,2,4,8,3,5,10,6,12};
    printArr(v);

    quicksort(v, 0, v.size()-1);

    printArr(v);
}
