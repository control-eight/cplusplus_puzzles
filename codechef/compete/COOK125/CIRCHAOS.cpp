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

int smallestDivisor(int n) {
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
    return n;
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
        int min = *min_element(iter(p));
        int max = *max_element(iter(p));
        if (max > N) {
            int d = smallestDivisor(max);
            if (d == max) {
                cout << N - 1 << endl;
            } else {
                cout << std::min(N - N / d, N - 1) << endl;
            }
        } else {
            cout << std::max(N - min, 0) << endl;
        }
    }
    return 0;
}