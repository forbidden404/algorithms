#include <bits/stdc++.h>

using namespace std;

struct Person {
    int birth;
    int death;
    Person(int birthYear, int deathYear) {
        birth = birthYear;
        death = deathYear;
    }
};

// O(P log P)
pair<vector<int>, vector<int>> getSortedYears(vector<Person *>& people) {
    vector<int> births(people.size());
    vector<int> deaths(people.size());
    for (int i = 0; i < people.size(); i++) {
        births[i] = people[i]->birth;
        deaths[i] = people[i]->death;
    }
    sort(births.begin(), births.end());
    sort(deaths.begin(), deaths.end());
    return make_pair(births, deaths);
}

int maxAliveYears(vector<Person *>& people, int min, int max) {
    vector<int> births, deaths;
    tie(births, deaths) = getSortedYears(people);

    int birthIndex = 0, deathIndex = 0;
    int currentlyAlive = 0;
    int maxAlive = 0, maxAliveYear = min;

    while (birthIndex < births.size()) {
        if (births[birthIndex] <= deaths[deathIndex]) {
            currentlyAlive++;
            if (currentlyAlive > maxAlive) {
                maxAlive = currentlyAlive;
                maxAliveYear = births[birthIndex];
            }
        } else if (births[birthIndex] > deaths[deathIndex]) {
            currentlyAlive--;
            deathIndex++;
        }
    }

    return maxAliveYear;
}

// O(R + P)
vector<int> getPopulationDeltas(vector<Person *>& people, int min, int max) {
    vector<int> deltas(max - min + 2);
    for (auto person : people) {
        int birth = person->birth - min;
        deltas[birth]++;

        int death = person->death - min;
        deltas[death + 1]--;
    }
    return deltas;
}

int getMaxAliveYear(vector<int> deltas) {
    int maxAliveYear = 0;
    int maxAlive = 0;
    int currentlyAlive = 0;
    for (int year = 0; year < deltas.size(); year++) {
        currentlyAlive += deltas[year];
        if (currentlyAlive > maxAlive) {
            maxAlive = currentlyAlive;
            maxAliveYear = year;
        }
    }
    return maxAliveYear;
}

int maxAliveYears2(vector<Person *>& people, int min, int max) {
    auto populationDeltas = getPopulationDeltas(people, min, max);
    int maxAliveYear = getMaxAliveYear(populationDeltas);
    return maxAliveYear + min;
}
