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

lli highestPowerOf2(lli x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    x |= x >> 32;
    return ((x ^ (x >> 1)) << 1) - 1;
}

lli highestPowerof2(lli n) {
    lli p = (lli)log2(n);
    lli res = (lli)pow(2, p);
    return (res << 1) - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli N = Read<lli>();
        lli ans = 0;
        while (N > 0) {
            lli tmp = highestPowerOf2(N);
            lli x = tmp ^ N;
            if (x == 0) {
                N--;
                continue;
            }
            ans += tmp * (N - x + 1);
            N = x - 1;
        }
        cout << ans << endl;
    }
    return 0;
}