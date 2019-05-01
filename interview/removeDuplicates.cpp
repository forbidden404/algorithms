#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string word) {
    string result = "";
    unordered_set<char> seen;
    for (auto c : word) {
        if (seen.find(c) == seen.end()) {
            seen.insert(c);
            result += c;
        }
    }
    return result;
}

int main() {
    string s = "tree traversal";
    cout << removeDuplicates(s) << endl;
    return 0;
}