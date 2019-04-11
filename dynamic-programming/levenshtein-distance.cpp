#include <bits/stdc++.h>

using namespace std;

int memo[5001][5001];
int levenshteinDistance(string s1, string s2) {
    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            memo[i][j] = 0;
        }
    }

    for (int i = 1; i <= s1.size(); i++) {
        memo[i][0] = i;
    }

    for (int j = 1; j <= s2.size(); j++) {
        memo[0][j] = j;
    }

    for (int j = 1; j <= s2.size(); j++) {
        for (int i = 1; i <= s1.size(); i++) {
            int cost = 0;
            if (s1[i-1] != s2[j-1])
                cost = 1;
            memo[i][j] = min(min(memo[i-1][j] + 1, memo[i][j-1] + 1), memo[i-1][j-1] + cost);
        }
    }

    return memo[s1.size()][s2.size()];
}

int main() {
    string s1 = "kitten";
    string s2 = "sitting";
    cout << "Distance: " << levenshteinDistance(s1, s2) << endl;
    return 0;
}
