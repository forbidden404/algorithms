#include <bits/stdc++.h>

using namespace std;

vector<string> getWords(string text) {
    istringstream iss(text);
    vector<string> results(istream_iterator<string>{iss},
                           istream_iterator<string>());
    return results;
}

unordered_map<string, vector<int>> createIndex1(string text) {
    unordered_map<string, vector<int>> index;
    auto words = getWords(text);
    for (int i = 0; i < words.size(); i++) {
        index[words[i]].push_back(i);
    }
    return index;
}

vector<int> queryIndex1(unordered_map<string, vector<int>>& index, string word) {
    if (index.find(word) != index.end()) return index[word];
    else return {};
}

class Trie {
    unordered_map<char, Trie*> children;
    vector<int> positions;
    bool isWord;
public:
    Trie() : isWord(false) { }

    vector<int>& addWord(string word) {
        auto cur = this;
        for (auto c : word) {
            if (cur->children.find(c) == cur->children.end()) 
                cur->children[c] = new Trie();
            cur = cur->children[c];
        }
        cur->isWord = true;
        return cur->positions;
    }

    vector<int> search(string word) {
        auto cur = this;
        for (auto c : word) {
            if (cur->children.find(c) == cur->children.end()) return {};
            cur = cur->children[c];
        }
        if (cur->isWord) {
            return cur->positions;
        }
        return {};
    }

    bool startsWith(string prefix) {
        auto cur = this;
        for (auto c : prefix) {
            if (cur->children.find(c) == cur->children.end()) return false;
            cur = cur->children[c];
        }
        return true;
    }
};

Trie createIndex2(string text) {
    Trie trie;
    auto words = getWords(text);
    for (int i = 0; i < words.size(); i++) {
        trie.addWord(words[i]).push_back(i);
    }
    return trie;
}

vector<int> queryIndex2(Trie& trie, string word) {
    return trie.search(word);
}

int main() {
    string text = "Lets keep testing this function with this code.";
    auto trie = createIndex2(text);
    auto indexes = queryIndex2(trie, "this");
    for (auto i : indexes) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}