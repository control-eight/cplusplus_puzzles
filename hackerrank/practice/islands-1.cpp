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

int find(int id, std::vector<int>& union_find) {
    if (union_find[id] == id) {
        return id;
    }
    int parent = find(union_find[id], union_find);
    // optimize
    union_find[id] = parent;
    return parent;
}

int join(int id1, int joinTo, std::vector<int>& union_find) {
    int joinToParent = find(joinTo, union_find);
    union_find[find(id1, union_find)] = joinToParent;
    // optimize
    union_find[id1] = joinToParent;
    return joinToParent;
}

int coord(int i, int c, int j) {
    return i * c + j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r = Read<int>();
    int c = Read<int>();

    std::vector<std::vector<int>> m(r, std::vector<int>(c));
    std::vector<int> union_find;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            m[i][j] = Read<int>();
            if (!m[i][j]) {
                union_find.push_back(-1);
            } else {
                union_find.push_back(coord(i, c, j));
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!m[i][j]) {
                continue;
            }
            if (j > 0 && m[i][j - 1]) {
                join(coord(i, c, j), coord(i, c, j - 1), union_find);
            }
            if (i > 0) {
                if (j > 0 && m[i - 1][j - 1]) {
                    join(coord(i, c, j), coord(i - 1, c, j - 1), union_find);
                }
                if (m[i - 1][j]) {
                    join(coord(i, c, j), coord(i - 1, c, j), union_find);
                }
                if (j < c - 1 && m[i - 1][j + 1]) {
                    join(coord(i, c, j), coord(i - 1, c, j + 1), union_find);
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < union_find.size(); i++) {
        if (union_find[i] == i) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}