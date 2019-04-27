#include <bits/stdc++.h>

using namespace std;

char firstUnique(string text) {
    unordered_map<char, int> frequency;
    for (auto letter : text)
        frequency[letter]++;
    for (auto letter : text)
        if (frequency[letter] == 1)
            return letter;
    return 0;
}

int main() {
    string s = "ABCDABD";
    cout << "The first unique letter of \'" << s << "\' is \'" << firstUnique(s) << "\'." << endl;
    return 0;
}
