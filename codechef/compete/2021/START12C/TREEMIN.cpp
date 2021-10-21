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

lli minmax(int vertex, bool move, const vector<vector<int>>& assoc, const vector<int>& cost) {
    lli r = move? -1e18: 1e18;
    for(int v : assoc[vertex]) {
        lli res = minmax(v, !move, assoc, cost) + cost[v];
        r = !move? std::min(r, res): std::max(r, res);
    }
    return r == 1e18 || r == -1e18? 0: r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int K = Read<int>();
        vector<int> cost;
        cost.push_back(0);
        for (int i = 0; i < N; i++) {
            cost.push_back(Read<int>());
        }
        vector<vector<int>> assoc(N + 2, vector<int>());
        for (int i = 0; i < N - 1; i++) {
            int x = Read<int>();
            int y = Read<int>();
            assoc[std::min(x, y)].push_back(std::max(x, y));
        }
        cout << minmax(1, false, assoc, cost) << endl;
    }
    return 0;
}