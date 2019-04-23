// Given an input string and a dictionary of words, find out if the input string can be
// segmented into a space-separated sequence of dictionary words.
#include <bits/stdc++.h>

using namespace std;

bool dictContains(string str, vector<string>& dict) {
    for (auto s : dict) { 
        if (str == s) return true;
    }
    return false;
}

bool wordBreak(string str, vector<string>& dict) {
    if (str.empty()) return true;

    for (int i = 1; i <= str.size(); i++) {
        if (dictContains(str.substr(0, i), dict) && wordBreak(str.substr(i, str.size() - i), dict))
            return true;
    }

    return false;
}

bool wordBreakDP(string str, vector<string>& dict) {
    if (str.empty()) return true;

    bool cache[str.size() + 1];
    memset(cache, false, sizeof(cache));

    for (int i = 1; i <= str.size(); i++) {
        if (cache[i] == false && dictContains(str.substr(0, i), dict))
            cache[i] = true;

        if (cache[i]) {
            if (i == str.size())
                return true;

            for (int j = i + 1; j <= str.size(); j++) {
                if (cache[j] == false && dictContains(str.substr(i, j - i), dict))
                    cache[j] = true;

                if (j == str.size() && cache[j])
                    return true;
            }
        }
    }

    return false;
}

void wordBreakUtil(string str, vector<string>& dict, int n, string result) {
    for (int i = 1; i <= n; i++) {
        string prefix = str.substr(0, i);

        if (dictContains(prefix, dict)) {
            if (i == n) {
                result += prefix;
                cout << result << endl;
                return;
            }

            wordBreakUtil(str.substr(i, n-i), dict, n-i, result + prefix + " ");
        }
    }
}

void wordBreakPrint(string str, vector<string>& dict) {
    wordBreakUtil(str, dict, str.size(), "");
}

int main() {
    vector<string> dict{"mobile","samsung","sam","sung","man","mango","icecream","and", 
                    "go","i","like","ice","cream"};
    wordBreakPrint("ilikesamsung", dict);
    wordBreakPrint("iiiiiiii", dict); 
    wordBreakPrint("", dict); 
    wordBreakPrint("ilikelikeimangoiii", dict); 
    wordBreakPrint("samsungandmango", dict); 
    wordBreakPrint("samsungandmangok", dict);
    return 0;
}
