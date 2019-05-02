#include <bits/stdc++.h>

using namespace std;

int rand(int lower, int higher) {
    return lower + (rand() % (higher - lower +1));
}

vector<int> shuffleArrayRecursively(vector<int>& cards, int i) {
    if (i == 0) return cards;

    shuffleArrayRecursively(cards, i-1);
    int k = rand(0, i);

    swap(cards[k], cards[i]);

    return cards;
}

void shuffleArray(vector<int> &cards) {
    for (int i = 0; i < cards.size(); i++) {
        int k = rand(0, i);
        swap(cards[k], cards[i]);
    }
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Given array: ";
    for (auto num : v) cout << num << " ";
    cout << endl;

    srand(time(NULL));
    shuffleArray(v);

    cout << "Shuffled array: ";
    for (auto num : v) cout << num << " ";
    cout << endl;

    return 0;
}