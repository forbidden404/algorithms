#include <bits/stdc++.h>

using namespace std;

int cutRod(vector<int> &prices, int length) {
    if (length == 0) return 0;
    int revenue = -1;
    for (int i = 1; i <= length; i++) {
        revenue = max(revenue, prices[i-1] + cutRod(prices, length - i));
    }
    return revenue;
}

int memoTD[1000];
int memoizedCutRod(vector<int> &prices, int length) {
    int revenue = 0;
    if (memoTD[length] >= 0) return memoTD[length];
    if (length == 0) revenue = 0;
    else {
        revenue = -1;
        for (int i = 1; i <= length; i++) {
            revenue = max(revenue, prices[i-1] + memoizedCutRod(prices, length - i));
        }
    }
    return memoTD[length] = revenue;
}

int bottomUpCutRod(vector<int> &prices, int length) {
    int *memo = new int[length+5];
    memo[0] = 0;
    for (int j = 1; j <= length; j++) {
        int revenue = -1;
        for (int i = 1; i <= j; i++) {
            revenue = max(revenue, prices[i-1] + memo[j - i]);
        }
        memo[j] = revenue;
    }
    return memo[length];
}

int memo[1000];
int s[1000];
void extendedBottomUpCutRod(vector<int> &prices, int length) {
    memo[0] = 0;
    for (int j = 1; j <= length; j++) {
        int revenue = -1;
        for (int i = 1; i <= j; i++) {
            if (revenue < prices[i-1] + memo[j - i]) {
                revenue = prices[i-1] + memo[j - i];
                s[j] = i;
            }
        }
        memo[j] = revenue;
    }
}

int bottomUpCutRod(vector<int> &prices, int length, int cost) {
    int *memo = new int[length+5];
    memo[0] = 0;
    for (int j = 1; j <= length; j++) {
        int revenue = prices[j-1];
        for (int i = 1; i < j; i++) {
            revenue = max(revenue, prices[i-1] + memo[j - i] - cost);
        }
        memo[j] = revenue;
    }
    return memo[length];
}

void printCutRodSolution(vector<int> &prices, int length) {
    memset(s, 0, sizeof(s));
    extendedBottomUpCutRod(prices, length);
    while (length > 0) {
        cout << s[length] << ' ';
        length = length - s[length];
    }
    cout << endl;
}

int main() {
    vector<int> v{1,5,8,9,10,17,17,20,24,30};
    printCutRodSolution(v, 10);
    printCutRodSolution(v, 7);

    cout << bottomUpCutRod(v, 7, 2) << endl;
    return 0;
}
