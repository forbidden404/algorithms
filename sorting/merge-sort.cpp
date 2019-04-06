#include <bits/stdc++.h>

using namespace std;

typedef bool (*cmp) (int a, int b);

void merge(vector<int> &arr, int p, int q, int r, cmp f) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[p + i];
    }

    for (int i = 0; i < n2; i++) {
        right[i] = arr[q + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;
    while (i < n1 && j < n2) {
        if (f(left[i], right[j])) {
            arr[k] = left[i];
            i++;
            k++;
        } else {
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

bool increasing(int a, int b) {
    return a <= b;
}

bool decreasing(int a, int b) {
    return a >= b;
}

void mergeSort(vector<int> &arr, int p, int r, cmp f) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(arr, p, q, f);
        mergeSort(arr, q+1, r, f);
        merge(arr, p, q, r, f);
    }
}

void printVector(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    vector<int> v{2,4,5,7,1,2,3,6};
    printVector(v);

    mergeSort(v, 0, v.size()-1, increasing);
    printVector(v);
    return 0;
}
