#include <bits/stdc++.h>

using namespace std;

void swap(int& i, int& j) {
    j = i + j;
    i = j - i;
    j = j - i;
}

void xorSwap(int& i, int & j) {
    if (i != j) {
        i ^= j;
        j ^= i;
        i ^= j;
    }
}

int main() {
    int a, b;
    a = 3;
    b = 2;
    swap(a, b);
    cout << a << ' ' << b << endl;
    xorSwap(a, b);
    cout << a << ' ' << b << endl;
    return 0;
}
