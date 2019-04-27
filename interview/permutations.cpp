#include <bits/stdc++.h>

using namespace std;

vector<string> permutations(string word) {
    if (word.size() == 1) return {word};

    auto perms = permutations(word.substr(1));
    auto c = word[0];
    vector<string> result;

    for (auto perm : perms) {
        for (int i = 0; i <= perm.size(); i++) {
            result.push_back(perm.substr(0, i) + c + perm.substr(i));
        }
    }

    return result;
}

int main() {
    string s = "LSE";
    auto v = permutations(s);
    for (auto w : v) { cout << w << " "; }
    cout << endl;
    return 0;
}
