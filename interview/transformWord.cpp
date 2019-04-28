#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> constructGraph(unordered_set<string> &dictionary) {
    unordered_map<string, vector<string>> graph; 
    string letters = "abcdefghijklmnopqrstuvwxyz";

    for (auto word : dictionary) {
        vector<string> words;

        for (int i = 0; i < word.size(); i++) {
            string rem = word.substr(0, i) + word.substr(i+1);
            if (dictionary.find(rem) != dictionary.end()) {
                words.push_back(rem);
            }

            for (auto c : letters) {
                string change = word.substr(0, i) + c + word.substr(i+1);
                if (dictionary.find(change) != dictionary.end() && change != word) {
                    words.push_back(change);
                }
            }
        }

        for (int i = 0; i <= word.size(); i++) {
            for (auto c : letters) {
                string add = word.substr(0, i) + c + word.substr(i);
                if (dictionary.find(add) != dictionary.end()) {
                    words.push_back(add);
                }
            }
        }

        graph[word] = words;
    }

    return graph;
}

vector<string> transformWord(unordered_map<string, vector<string>> &graph, string start, string goal) {
    deque<vector<string>> paths;
    paths.push_back({start});
    unordered_set<string> extended;

    while (!paths.empty()) {
        auto currentPath = paths.front();
        paths.pop_front();
        string currentWord = currentPath[currentPath.size() - 1];
        if (currentWord == goal)
            return currentPath;
        else if (extended.find(currentWord) != extended.end())
            continue;

        extended.insert(currentWord);
        auto transforms = graph[currentWord];
        for (auto word : transforms) {
            bool isNot = true;
            for (auto w : currentPath) {
                if (word == w) {
                    isNot = false;
                    break;
                }
            }
            if (isNot) {
                vector<string> p;
                p.insert(p.end(), currentPath.begin(), currentPath.end());
                p.push_back(word);
                paths.push_back(p);
            }
        }
    }

    return {};
}

int main() {
    unordered_set<string> dict;
    dict.insert("cat");
    dict.insert("bat");
    dict.insert("bet");
    dict.insert("bed");
    dict.insert("at");
    dict.insert("ad");
    dict.insert("ed");

    auto graph = constructGraph(dict);
    auto transform = transformWord(graph, "cat", "bed");
    for (auto word : transform) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
