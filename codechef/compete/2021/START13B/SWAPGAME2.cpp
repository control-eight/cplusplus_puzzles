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
        for (int i = 0; i < N; i++) {
            A.push_back(Read<lli>());
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
                res += (z - i) * A[i];
            } else {
                res -= (i - z) * A[i];
            }
        }
        cout << res << endl;
    }
    return 0;
}