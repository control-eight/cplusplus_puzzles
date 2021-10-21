#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <set>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

// binary search
pair<lli, int> FindLessOrEqual(const multiset<pair<lli, int>>& v, lli el) {
    auto iter = v.lower_bound(make_pair(el, 0));
    if (iter == v.end()) {
        iter--;
    }
    if (iter->first <= el) {
        return {iter->first, iter->second};
    }
    if (iter != v.begin()) {
        iter--;
        return {iter->first, iter->second};
    }
    return {-1, -1};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        multiset<pair<lli, int>> els;
        lli first = 0;
        int i = 0;
        while (i < N) {
            if (i == 0) {
                first = Read<lli>();
            } else {
                els.insert(make_pair(Read<lli>(), i));
            }
            i++;
        }
        vector<vector<lli>> ans;
        bool possible = 1;
        while (!els.empty()) {
            auto pair = FindLessOrEqual(els, first);
            if (pair.first == -1) {
                if (els.size() == 1) {
                    possible = 0;
                    break;
                }
                auto min = els.begin();
                auto next = min;
                next++;
                auto next_pair = *next;
                next_pair.first += min->first - first;
                els.insert(next_pair);
                ans.push_back({min->second + 1, next->second + 1, min->first - first});
                ans.push_back({min->second + 1, 1, first});
                els.erase(min);
                els.erase(next);
                first *= 2;
            } else {
                ans.push_back({pair.second + 1, 1, pair.first});
                els.erase(pair);
                first += pair.first;
            }
        }
        if (possible) {
            cout << ans.size() << endl;
            for (const auto& el : ans) {
                cout << el[0] << " " << el[1] << " " << el[2] << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}