#include <bits/stdc++.h>

using namespace std;

int countFactZeros(int num) {
    int count = 0;
    if (num < 0) return -1;
    for (int i = 5; num / i > 0; i *= 5)
        count += num / i;
    return count;
}

int main() {
    int x;
    cin >> x;
    cout << countFactZeros(x) << endl;
    return 0;
}
