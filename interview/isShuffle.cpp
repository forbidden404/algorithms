// We are given 3 strings: str1, str2, and str3. Str3 is said to be a shuffle of str1 and str2
// if it can be formed by interleaving the characters of str1 and str2 in a way that maintains the
// left to right ordering of the characters from each string.
#include <bits/stdc++.h>

using namespace std;

bool isShuffle(string str1, string str2, string str3) {
    if (str1.size() + str2.size() != str3.size()) return false;

    if ((str1.empty() || str2.empty()) || str3.empty()) {
        if (str1 + str2 == str3) return true;
        else return false;
    }

    if (str1[0] != str3[0] && str2[0] != str3[0])
        return false;

    if (str1[0] == str3[0] && isShuffle(str1.substr(1), str2, str3.substr(1))) 
        return true;
    if (str2[0] == str3[0] && isShuffle(str1, str2.substr(1), str3.substr(1)))
        return true;

    return false;
}

bool isShuffle2(string str1, string str2, string str3, unordered_set<string> cache) {
    if (cache.find(str1+str2) != cache.end()) return false;

    if (str1.size() + str2.size() != str3.size()) return false;

    if ((str1.empty() || str2.empty()) || str3.empty()) {
        if (str1 + str2 == str3) return true;
        else return false;
    }

    if (str1[0] != str3[0] && str2[0] != str3[0])
        return false;

    if (str1[0] == str3[0] && isShuffle2(str1.substr(1), str2, str3.substr(1), cache)) 
        return true;
    if (str2[0] == str3[0] && isShuffle2(str1, str2.substr(1), str3.substr(1), cache))
        return true;

    cache.insert(str1+str2);

    return false;

}

int main() {
    string str1 = "abc";
    string str2 = "def";
    string str3 = "dabecf";
    unordered_set<string> cache;

    if (isShuffle2(str1, str2, str3, cache)) {
        cout << str3 << " is a shuffle of " << str1 << " and " << str2 << endl;
    } else {
        cout << str3 << " is not a shuffle of " << str1 << " and " << str2 << endl;
    }
}
