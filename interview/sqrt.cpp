#include <bits/stdc++.h>

using namespace std;

int sqrt1(int num) {
    if (num < 0) return -1;
    if (num == 1) return 1;
    for (int k = 1; k <= (1 + (num/2)); k++) {
        if (k*k == num) return k;
        else if (k*k > num) return k-1;
    }
    return (1 + (num/2));
}

int sqrt2(int num) {
    if (num < 0) return -1;
    if (num == 1) return 1;
    int left = 0;
    int right = 1 + (num / 2);
    while (left + 1 < right) {
        int middle = left + (right - left) / 2;
        unsigned long square = middle * middle;
        if (square == num) return middle;
        else if (square < num) left = middle;
        else right = middle;
    }

    return left;
}

int main() {
    int s;
    cin >> s;
    cout << sqrt2(s) << endl;
    return 0;
}