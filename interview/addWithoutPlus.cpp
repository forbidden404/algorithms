#include <bits/stdc++.h>

using namespace std;

#define isOn(S, j) (S & (1<<j))

int add(int a, int b) {
    if (b == 0) return a;
    int carry = (a & b) << 1;
    int sum = a ^ b;
    return add(sum, carry);
}

int main() {
     
}
