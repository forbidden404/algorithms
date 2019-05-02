#include <bits/stdc++.h>

using namespace std;

class GraphNode {
    vector<GraphNode *> neighbors;
    unordered_map<string, GraphNode *> map;
    string name;
    int frequency;
    bool visited;

public:
    GraphNode(string nm, int freq) : name(nm), frequency(freq), visited(false) {}

    string getName() { return name; }
    int getFrequency() { return frequency; }
    vector<GraphNode *> getNeighbors() { return neighbors; }
    bool isVisited() { return visited; }

    bool addNeighbor(GraphNode *node) {
        if (map.find(node->getName()) != map.end())
            return false;
        neighbors.push_back(node);
        map[node->getName()] = node;
        return true;
    }

    void setIsVisited(bool v) {
        visited = v;
    }
};

class Graph {
    vector<GraphNode *> nodes;
    unordered_map<string, GraphNode *> map;

public:
    bool hasNode(string name) {
        return map.find(name) != map.end();
    }

    GraphNode* getNode(string name) {
        return map[name];
    }

    GraphNode* createNode(string name, int freq) {
        if (hasNode(name))
            return getNode(name);

        auto node = new GraphNode(name, freq);
        nodes.push_back(node);
        map[name] = node;
        return node;
    }

    vector<GraphNode *> getNodes() { return nodes; }

    void addEdges(string startName, string endName) {
        auto start = getNode(startName);
        auto end = getNode(endName);
        if (start != nullptr && end != nullptr) {
            start->addNeighbor(end);
            end->addNeighbor(start);
        }
    }
};

Graph constructGraph(unordered_map<string, int>& names) {
    Graph graph;
    for (auto p : names) {
        string name = p.first;
        int freq = p.second;
        graph.createNode(name, freq);
    }
    return graph;
}

void connectEdges(Graph& graph, vector<vector<string>> synonyms) {
    for (auto entry : synonyms) {
        string name1 = entry[0];
        string name2 = entry[1];
        graph.addEdges(name1, name2);
    }
}

int getComponentFrequency(GraphNode *node) {
    if (node->isVisited()) return 0;
    node->setIsVisited(true);
    int sum = node->getFrequency();
    for (auto child : node->getNeighbors())
        sum += getComponentFrequency(child);
    return sum;
}

unordered_map<string, int> getTrueFrequencies(Graph& graph) {
    unordered_map<string, int> rootNames;
    for (auto node : graph.getNodes()) {
        if (!node->isVisited()) {
            int frequency = getComponentFrequency(node);
            string name = node->getName();
            rootNames[name] = frequency;
        }
    }
    return rootNames;
}

unordered_map<string, int> trulyMostPopular(unordered_map<string, int> names, vector<vector<string>> synonyms) {
    auto graph = constructGraph(names);
    connectEdges(graph, synonyms);
    auto rootNames = getTrueFrequencies(graph);
    return rootNames; 
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