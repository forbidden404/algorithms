#include <bits/stdc++.h>

using namespace std;

struct Attribute {
    string value;
    string getTagCode() { return tag; }
    Attribute(string val, string tag) : value(val), tag(tag) { } 

private:
    string tag;
};

struct Element {
    string value;
    vector<Attribute &> attributes;
    vector<Element &> children;
    
    string getNameCode() { return name; }
    Element(string val, string name) : value(val), name(name) { }

private:
    string name;
};

void encode(string v, string& s) {
    s += v + " ";
}

void encode(Attribute attr, string& s) {
    encode(attr.getTagCode(), s);
    encode(attr.value, s);
}

void encode(Element root, string& s) {
    encode(root.getNameCode(), s);
    for (auto a : root.attributes) {
        encode(a, s);
    }
    encode("0", s);
    if (root.value.compare("") != 0) {
        encode(root.value, s);
    } else {
        for (auto e : root.children)
            encode(e, s);
    }
    encode("0", s);
}

string encodeToString(Element root) {
    string s;
    encode(root, s);
    return s;
}
