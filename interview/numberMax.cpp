#include <bits/stdc++.h>

using namespace std;

int flip(int a) {
    return 1^a;
}

int sign(int a) {
    return flip((a >> 31) & 0x1);
}

int max(int a, int b) {
    int c = a - b;
    
    int sa = sign(a);
    int sb = sign(b);
    int sc = sign(c);

    int use_sign_of_a = sa ^ sb;
    int use_sign_of_c = flip(sa ^ sb);

    int k = use_sign_of_a * sa + use_sign_of_c * sc;
    int q = flip(k);

    return a * k + b * q;
}

int main() {
    int a = INT_MAX - 2, b = -15;
    cout << max(a, b) << endl;
    return 0;
}