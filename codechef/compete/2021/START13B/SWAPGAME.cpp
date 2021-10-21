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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();

    while (T--) {
        lli N = Read<lli>();
        vector<lli> A;
        vector<lli> prefix_sum_A;
        for (int i = 0; i < N; i++) {
            lli el = Read<lli>();
            A.push_back(el);
            if (!prefix_sum_A.empty()) {
                prefix_sum_A.push_back(prefix_sum_A.back() + el);
            } else {
                prefix_sum_A.push_back(el);
            }
        }
        unordered_map<lli, vector<int>> index;
        for (int i = 0; i < N; i++) {
            index[Read<lli>()].push_back(i);
        }
        lli res = 0;
        for (int i = 0; i < N; i++) {
            int z = index[A[i]].back();
            index[A[i]].pop_back();
            if (z >= i) {
                res += (z - i) * A[i] - (prefix_sum_A[z] - prefix_sum_A[i]);
            } else {
                res += (prefix_sum_A[i] - prefix_sum_A[z]) - (i - z) * A[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}