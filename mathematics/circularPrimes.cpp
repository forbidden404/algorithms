#include <bits/stdc++.h>

using namespace std;

// Sieve of Sundaram
void sieve(bool marked[], int n) {
    // Mark all numbers of the form i + j + 2ij as true where 1 <= i <= j
    for (int i = 1; i <= n; i++) 
        for (int j = i; (i + j + 2 * i *j) <= n; j++)
            marked[i + j + 2 * i * j] = true;
}

// Find total number of digits
int countDigits(int n) {
    int digits = 0;
    while (n /= 10)
        digits++;
    return digits;
}

// Rotate function to right rotate the number
int rotate(int n) {
    int rem = n % 10;
    rem *= pow(10, countDigits(n));
    n /= 10;
    n += rem;
    return n;
}

// Print all circular primes
void circularPrime(int n) {
    if (n < 2) { return; }
    int half = (n - 2) / 2;

    // Take into consideration the rotation when finding the primes.
    // The maximum number possibly found when rotating a number with n digits is 
    // 10^|n| - 1
    int digits = countDigits(n);
    int length = pow(10, digits);
    bool marked[length];
    memset(marked, false, sizeof(marked));

    sieve(marked, length);

    cout << "2 ";

    // If marked[i] is false, then 2*i + 1 is a prime number from Sieve of Sundaram
    for (int i = 1; i <= half; i++) {
        if (marked[i]) continue;

        int num = 2 * i + 1;
        num = rotate(num);

        while (num != 2 * i + 1) {
            if (num % 2 == 0) break;

            if (marked[(num - 1) / 2] == false) num = rotate(num);
            else break;
        }

        if (num == (2 * i + 1)) cout << num << " ";
    }
}

int main() {
    circularPrime(333);
    cout << endl;
    return 0;
}
