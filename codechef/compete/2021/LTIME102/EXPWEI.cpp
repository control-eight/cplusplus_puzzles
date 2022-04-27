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

lli gcdExtended(lli a, lli b, lli *x, lli *y) {
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
    lli x1, y1;
    lli gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}

lli modInverse(lli a, lli m) {
    lli x, y;
    gcdExtended(a, m, &x, &y);
    int res = (x%m + m) % m;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    lli modulo = 998244353;
    while (T--) {
        lli N = Read<lli>();
        lli p = ((1 + N) * N) / 2;
        p = (p % modulo) * (p % modulo);
        lli q = N;
        lli x = modInverse(q, modulo);
        cout << ((p % modulo) * (x % modulo)) % modulo << endl;
    }
    return 0;
}