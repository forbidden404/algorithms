#include <bits/stdc++.h>

using namespace std;

class Trie {
    unordered_map<char, Trie *> children;
    bool isWord;
public:
    Trie() : isWord(false) { }

    void insert(string word) {
        auto cur = this;
        for (auto c : word) {
            if (cur->children.find(c) == cur->children.end())
                cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }

    bool search(string word) {
        auto cur = this;
        for (auto c : word) {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return cur->isWord;
    }

    vector<string> getAllPrefixesOfWord(string word) {
        string prefix = "";
        vector<string> prefixes;
        auto cur = this;
        for (auto c : word) {
            if (cur->children.find(c) == cur->children.end())
                return prefixes;
            cur = cur->children[c];
            prefix += c;
            if (cur->isWord)
                prefixes.push_back(prefix);
        }
        return prefixes;
    }
};

string longestWord(vector<string>& words) {
    // Add words to the trie, and pairs to the queue
    Trie trie;
    queue<pair<string, string>> q;
    for (auto word : words) {
        auto prefixes = trie.getAllPrefixesOfWord(word);
        for (auto prefix : prefixes)
            q.push(make_pair(word, word.substr(prefix.size())));
        trie.insert(word);
    }

    string longestWord;
    int maxLength = 0;

    while (!q.empty()) {
        string word, suffix;
        tie(word, suffix) = q.front(); q.pop();
        if (trie.search(suffix) && word.size() > maxLength) {
            longestWord = word;
            maxLength = word.size();
        } else {
            auto prefixes = trie.getAllPrefixesOfWord(suffix);
            for (auto prefix : prefixes)
                q.push(make_pair(word, suffix.substr(prefix.size())));
        }
    }

    return longestWord;
}

int main() {
    vector<string> s{"cat", "cats", "catsdogcats", "catxdogcatsrat", "dog", "dogcatsdog",
                     "hippopotamuses", "rat", "ratcat", "ratcatdog", "ratcatdogcat"};
    cout << longestWord(s) << endl;
    return 0;
}