#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

pair<int, lli> FindLessOrEqual(const vector<lli>& v, lli el) {
    auto iter = lower_bound(v.begin(), v.end(), el);
    if (iter == v.end()) {
        iter--;
    }
    if (*iter <= el) {
        return {iter - v.begin(), *iter};
    }
    if (iter != v.begin()) {
        iter--;
        return {iter - v.begin(), *iter};
    }
    return {-1, *iter};
}

pair<int, lli> FindGreaterOrEqual(const vector<lli>& v, lli el) {
    auto iter = lower_bound(v.begin(), v.end(), el);
    if (*iter >= el) {
        return {iter - v.begin(), *iter};
    }
    return {-1, *iter};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        vector<vector<lli>> lines;
        while (N--) {
            int M = Read<int>();
            vector<lli> line;
            while (M--) {
                line.push_back(Read<int>());
            }
            lines.push_back(line);
        }

        unordered_map<lli, lli> all_pos_count;
        unordered_map<lli, lli> all_pos;
        for (auto& line : lines) {
            for (int i = 0; i < line.size(); i++) {
                lli ant = line[i];
                all_pos_count[abs(ant)]++;
                if (ant > 0) {
                    all_pos[abs(ant)] += line.size() - i - 1;
                } else {
                    all_pos[abs(ant)] += i;
                }
            }
        }

        unordered_map<lli, vector<lli>> excluded;
        for (int k = 0; k < lines.size(); k++) {
            auto& line = lines[k];
            for (auto it = line.begin(); it != line.end(); it++) {
                lli ant = *it;
                if (all_pos_count[abs(ant)] > 1) {
                    it = line.erase(it);
                    excluded[k].push_back(ant);
                    it--;
                }
            }
        }

        lli ans = 0;
        for (int k = 0; k < lines.size(); k++) {
            auto& line = lines[k];
            if (line.empty()) {
                continue;
            }

            lli positive_count = 0;
            lli negative_count = 0;
            for (lli ant : line) {
                if (ant > 0) {
                    positive_count++;
                }
                if (ant < 0) {
                    negative_count++;
                }
            }
            for (lli ant : line) {
                if (ant < 0) {
                    ans += positive_count;
                }
            }
            for (lli ant : excluded[k]) {
                if (ant < 0) {
                    auto pair = FindLessOrEqual(line, -ant - 1);
                    if (pair.first != -1 && pair.second > 0) {
                        ans += (pair.first - negative_count + 1);
                    }
                } else {
                    auto pair = FindGreaterOrEqual(line, -ant + 1);
                    if (pair.first != -1 && pair.second < 0) {
                        ans += (negative_count - pair.first);
                    }
                }
            }
        }
        for (auto [ant, count] : all_pos_count) {
            if (count > 1) {
                ans += all_pos[ant];
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}