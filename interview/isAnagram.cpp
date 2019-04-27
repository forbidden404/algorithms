#include <bits/stdc++.h>

using namespace std;

string getLetters(string text) {
    string s;
    for (auto c : text) {
        if (c >= 'A' && c <= 'Z') {
            s += char(tolower(c));
        } else if (c >= 'a' && c <= 'z') {
            s += c;
        }
    }
    return s;
}

bool isAnagram(string str1, string str2) {
    if (str1.size() != str2.size()) return false;
    str1 = getLetters(str1);
    str2 = getLetters(str2);

    unordered_map<char, int> frequency;

    for (auto letter : str1) {
        frequency[letter]++; 
    }

    for (auto letter : str2) {
        frequency[letter]--;
        if (frequency[letter] < 0) return false;
    }

    return true;
}

int main() {
    string str1 = "Eleven plus two";
    string str2 = "Twelve plus one";

    if (isAnagram(str1, str2)) {
        cout << str1 << " and " << str2 << " are anagrams." << endl;
    } else {
        cout << str1 << " and " << str2 << " are not anagrams." << endl;
    }

    return 0;
}
