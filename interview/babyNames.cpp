#include <bits/stdc++.h>

using namespace std;

class NameSet {
    unordered_set<string> names;
    int frequency;
    string rootName;

public:
    NameSet(string name, int freq) : frequency(freq), rootName(name) {
        names.insert(name);
    }

    void copyNamesWithFrequency(unordered_set<string>& more, int freq) {
        names.insert(more.begin(), more.end());
        frequency += freq;
    }

    unordered_set<string> getNames() { return names; }
    string getRootName() { return rootName; }
    int getFrequency() { return frequency; }
    int size() { return names.size(); }
};

unordered_map<string, NameSet*> constructGroups(unordered_map<string, int>& names) {
    unordered_map<string, NameSet*> groups;
    for (auto p : names) {
        string name = p.first;
        int frequency = p.second;
        auto group = new NameSet(name, frequency);
        groups[name] = group;
    }
    return groups;
}

unordered_map<string, int> convertToMap(unordered_map<string, NameSet*>& groups) {
    unordered_map<string, int> list;
    for (auto p : groups) {
        auto group = p.second;
        list[group->getRootName()] = group->getFrequency();
    }
    return list;
}

void mergeClasses(unordered_map<string, NameSet*>& groups, vector<vector<string>>& synonyms) {
    for (auto entry : synonyms) {
        string name1 = entry[0];
        string name2 = entry[1];
        
        auto set1 = groups[name1];
        auto set2 = groups[name2];

        if (set1 != set2) {
            auto smaller = set2->size() < set1->size() ? set2 : set1;
            auto bigger = set2->size() < set1->size() ? set1 : set2;

            auto otherNames = smaller->getNames();
            int frequency = smaller->getFrequency();
            bigger->copyNamesWithFrequency(otherNames, frequency);

            for (auto name : otherNames) {
                groups[name] = bigger;
            }
        }
    }
}

unordered_map<string, int> trulyMostPopular(unordered_map<string, int>& names, vector<vector<string>>& synonyms) {
    auto groups = constructGroups(names);
    mergeClasses(groups, synonyms);
    return convertToMap(groups);
}

int main() {
    unordered_map<string, int> names;
    names["John"] = 10;
    names["Jon"] = 3;
    names["Davis"] = 2;
    names["Kari"] = 3;
    names["Johnny"] = 11;
    names["Carlton"] = 8;
    names["Carleton"] = 2;
    names["Jonathan"] = 9;
    names["Carrie"] = 5;

    vector<vector<string>> synonyms;
    synonyms.push_back({"Jonathan", "John"});
    synonyms.push_back({"Jon", "Johnny"});
    synonyms.push_back({"Johnny", "John"});
    synonyms.push_back({"Kari", "Carrie"});
    synonyms.push_back({"Carleton", "Carlton"});

    auto map = trulyMostPopular(names, synonyms);
    for (auto p : map) {
        cout << "Name: " << p.first << " => Frequency: " << p.second << endl;
    }

    return 0;
}