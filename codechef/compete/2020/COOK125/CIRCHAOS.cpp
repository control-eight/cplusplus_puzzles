//
// Created by Oleksandr Bykovskyi on 12/21/20.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

int Gcd(int x, int y) {
    if (x == 0) return y;
    return Gcd(y % x, x);
}

int GcdVector(vector<int> v) {
    int ans = v[0];
    for (int i = 1; i < v.size(); i++) {
        ans = Gcd(v[i], ans);
    }
    return ans;
}

int LpfStar(int n, int max) {
    while (n % 2 == 0) {
        n >>= 1;
        if (n < max) {
            return n;
        }
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n /= i;
            if (n < max) {
                return n;
            }
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = read<int>();
    while (T--) {
        int N = read<int>();
        int M = read<int>();
        vector<int> p;
        while (M--) {
            p.push_back(read<int>());
        }
        int gcd = GcdVector(p);
        if (gcd % N == 0) {
            cout << 0 << endl;
        } else {
            if (gcd < N) {
                cout << N - gcd << endl;
            } else {
                int lpf = LpfStar(gcd, N);
                cout << N - lpf << endl;
            }
        }
    }
    return 0;
}