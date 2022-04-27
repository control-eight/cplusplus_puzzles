#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

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
        int N = Read<int>();
        vector<lli> els;
        els.reserve(N);
        for (int i = 0; i < N; i++) {
            els.push_back(Read<lli>());
        }
        lli res = 0;
        lli allSoFar = els.back();
        for (int i = N - 2; i >= 0; i--) {
            res |= (els[i] & allSoFar);
            allSoFar |= els[i];
        }
        cout << res << endl;
    }
    return 0;
}