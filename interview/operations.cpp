#include <bits/stdc++.h>

using namespace std;

int negate(int a) {
    int neg = 0;
    int newSign = a < 0 ? 1 : -1;
    while (a != 0) {
        neg += newSign;
        a += newSign;
    }
    return neg;
}

int minus(int a, int b) {
    return a + ::negate(b);
}

int multiply(int a, int b) {
    if (a < b) 
        return multiply(b, a);

    int sum = 0;
    for (int i = abs(b); i > 0; i = ::minus(i, 1)) 
        sum += a;
    if (b < 0)
        sum = ::negate(sum);
    return sum;
}

int divide(int a, int b) {
    if (b == 0) return 0;

    int absa = abs(a);
    int absb = abs(b);

    int product = 0;
    int x = 0;
    while (product + absb <= absa) {
        product += absb;
        x++;
    }

    if ((a < 0 && b < 0) || (a > 0 && b > 0))
        return x;
    else
        return ::negate(x);
}

int main() {
    int a = 10, b = 7;
    cout << ::minus(a, b) << endl;
    cout << multiply(a, b) << endl;
    cout << divide(a, b) << endl;
    return 0;
}
