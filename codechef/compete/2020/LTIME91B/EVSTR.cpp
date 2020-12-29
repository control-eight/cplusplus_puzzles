#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <stdlib.h>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

int FindPair(tuple<int, int> prev_t, int k, const vector<tuple<int, int>>& tuples) {
    unordered_set<int> duplicates;
    for (int i = k; i < tuples.size(); i++) {
        int el = get<0>(tuples[i]);
        int f = get<1>(tuples[i]);
        if (get<0>(prev_t) == el && (get<1>(prev_t) + f) % 2 == 0) {
            return i;
        }
        if (f % 2 == 0 || !duplicates.insert(el).second) {
            return -1;
        }
    }
    return -1;
}

int Calc(const vector<int>& v) {
    vector<tuple<int, int>> tuples;
    int prev = v[0];
    int count = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == prev) {
            count++;
        } else {
            tuples.push_back(make_tuple(prev, count));
            count = 1;
        }
        prev = v[i];
    }
    tuples.push_back(make_tuple(prev, count));

    int ans = 0;
    for (int i = 0; i < tuples.size(); i++) {
        if (get<1>(tuples[i]) % 2 != 0) {
            int j = FindPair(tuples[i], i + 1, tuples);
            if (j != -1) {
                ans += j - i - 1;
                i += j - i;
            } else {
                ans++;
            }
        }
    }
    return ans;
}

int Calc2(const vector<int>& v) {
    vector<int> max_length(v.size() + 1, -v.size());
    max_length[0] = 0;
    for (const int x : v) {
        int max0 = max_length[0];
        int maxX = max_length[x];
        max_length[x] = std::max(maxX, max0 + 1);
        max_length[0] = std::max(max0, maxX + 1);
    }
    return v.size() - max_length[0];
}

vector<int> Generate(int n) {
    vector<int> res;
    int l = n;
    while (l--) {
        res.push_back(rand() % n + 1);
    }
    return res;
}

void Puzzle() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        vector<int> v;
        while(N--) {
            v.push_back(Read<int>());
        }
        int ans = Calc(v);
        int ans2 = Calc2(v);
        cout << "1 = " << ans << ", 2 = " << ans2 << endl;
    }
}

void Check() {
    srand(555);
    int n = 6;
    for (int i = 0; i < 6000; i++) {
        vector<int> w = Generate(n);
        //for (int q : w) {
        //    cout << q << endl;
        //}
        int ans11 = Calc(w);
        int ans22 = Calc2(w);
        //cout << ans11 << " != " << ans22 << ", when ";
        if (ans11 != ans22) {
            cout << ans11 << " != " << ans22 << ", when ";
            for (int el : w) {
                cout << el << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    Puzzle();
    //Check();
    return 0;
}