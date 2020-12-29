#include <iostream>
#include <vector>
#include <unordered_map>
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

bool SortByFirst(const tuple<int, int> &l,
                 const tuple<int, int> &r) {
    return (get<0>(l) < get<0>(r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int Q = Read<int>();
        vector<tuple<int, int>> intervals;
        while (Q--) {
            int L = Read<int>();
            int R = Read<int>();
            intervals.push_back(make_tuple(L, R));
        }
        sort(intervals.begin(), intervals.end());
        vector<int> cities(N, 0);
        unordered_map<int, vector<int>> map;
        lli running_sum = 0;
        int elements = 0;
        int intervals_index = 0;
        for (int i = 1; i <= N; i++) {
            while(intervals_index < intervals.size() && get<0>(intervals[intervals_index]) == i) {
                running_sum++;
                elements++;
                auto& v = map[get<1>(intervals[intervals_index])];
                v.push_back(get<1>(intervals[intervals_index]) - get<0>(intervals[intervals_index]) + 1);
                intervals_index++;

            }
            cout << running_sum;
            if (i != N) {
                cout << " ";
            }
            vector<int> to_subtract = map[i];
            for (const int el : to_subtract) {
                running_sum -= el;
                elements--;
            }
            //cout << "[DEBUG " << running_sum << ", " << elements << "]";
            running_sum += elements;
        }
        cout << endl;
    }
    return 0;
}