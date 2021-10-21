#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

struct Group {
    int x1;
    int y1;
    int x2;
    int y2;
};

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<Group*>> groups(land.size(), std::vector<Group*>(land[0].size()));
    vector<Group*> result;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[0].size(); j++) {
            if (land[i][j] == 0) {
                continue;
            }
            if (j > 0 && land[i][j - 1] == 1) {
                groups[i][j] = groups[i][j - 1];
                groups[i][j]->x2 = i;
                groups[i][j]->y2 = j;
            } else if (i > 0 && land[i - 1][j] == 1) {
                groups[i][j] = groups[i - 1][j];
                groups[i][j]->x2 = i;
                groups[i][j]->y2 = j;
            } else {
                groups[i][j] = new Group{.x1 = i, .y1 = j, .x2 = i, .y2 = j};
                result.push_back(groups[i][j]);
            }
        }
    }
    vector<vector<int>> converted;
    for (Group* group: result) {
        converted.push_back({group->x1, group->y1, group->x2, group->y2});
    }
    return converted;
}

void Print(const vector<vector<int>>& res) {
    cout << "Ans: ";
    for (auto r : res) {
        cout << "[";
        for (auto c : r) {
            cout << c << ",";
        }
        cout << "]" << endl;
    }
}

int main() {
    vector<vector<int>> land = {{1,0,0},{0,1,1},{0,1,1}};
    Print(findFarmland(land));
    vector<vector<int>> land1 = {{1,1},{1,1}};
    Print(findFarmland(land1));
    vector<vector<int>> land2 = {{0}};
    Print(findFarmland(land2));
    return 0;
}