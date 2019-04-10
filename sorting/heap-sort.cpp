#include <bits/stdc++.h>

using namespace std;


struct Heap {
    int heap_size;
    int length;
    vector<int> array;

    Heap(int length) : heap_size(0), length(length) {
        vector<int> v(length);
        array = v;
    }

    Heap(int length, vector<int> array) : heap_size(0), length(length), array(array) { }

    int parent(int i) { return i/2; }
    int left(int i) { return 2 * i; }
    int right(int i ) { return 2 * i + 1; }

    void maxHeapify(int index) {
        int largest = 0;
        int l = left(index);
        int r = right(index);
        
        if (l <= heap_size && array[l] > array[index]) {
            largest = l; 
        } else {
            largest = index;
        }

        if (r <= heap_size && array[r] > array[largest]) {
            largest = r;
        }   

        if (largest != index) {
            swap(array[index], array[largest]);
            maxHeapify(largest);
        }
    }

    void buildMaxHeap() {
        heap_size = length;
        for (int i = length/2; i >= 0; i--) {
            maxHeapify(i);
        }
    }
};

void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        if (i != 0) cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

void heapSort(vector<int> array) {
    Heap maxHeap(array.size(), array);
    maxHeap.buildMaxHeap();
    for (int i = maxHeap.length; i >= 1; i--) {
        swap(array[1], array[i]);
        maxHeap.heap_size--;
        maxHeap.maxHeapify(1);
    }

    for (int i = 0; i < array.size(); i++) {
        cout << maxHeap.array[i] << ' ';
    }
    cout << endl;
}



int main() {
    vector<int> v{3,2,5,6,7,1,2};
    printVector(v);

    heapSort(v);

    printVector(v);

}

