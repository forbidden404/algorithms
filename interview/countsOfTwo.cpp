#include <bits/stdc++.h>

using namespace std;

int numberOf2s(int num) {
    int count = 0;
    while (num > 0) {
        if (num % 10 == 2) {
            count++;
        }
        num /= 10;
    }
    return count;
}

int numbersOf2sInRange(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        count += numberOf2s(i);
    }
    return count;
}

int count2sInRangeAtDigit(int number, int d) {
    int powerOf10 = pow(10, d);
    int nextPowerOf10 = powerOf10 * 10;
    int right = number % powerOf10;

    int roundDown = number - number % nextPowerOf10;
    int roundUp = roundDown + nextPowerOf10;

    int digit = (number / powerOf10) % 10;
    if (digit < 2) {
        return roundDown / 10;
    } else if (digit == 2) {
        return roundDown / 10 + right + 1;
    } else {
        return roundUp / 10;
    }
}

int count2sInRange(int number) {
    int count = 0;
    int len = to_string(number).size();
    for (int digit = 0; digit < len; digit++) {
        count += count2sInRangeAtDigit(number, digit);
    }
    return count;
}

int main() {
    int n = 61523;
    cout << "Count of 2s from 0 to 61523: "<< count2sInRange(n) << endl;

    n = 63525;
    cout << "Count of 2s from 0 to 63525: "<< count2sInRange(n) << endl;

    n = 62523;
    cout << "Count of 2s from 0 to 62523: "<< count2sInRange(n) << endl;

    return 0;
}