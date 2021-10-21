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

int solve(lli N) {
    if (N == 0) {
        return 0;
    }
    if (N % 2 == 1) {
        return solve(N-1) + 1;
    } else {
        int count = 1;
        lli X = N;
        while ((X >> 1)%2 == 0) {
            X >>= 1;
            count++;
        }
        int p1 = solve(N / static_cast<lli>(pow(2, count))) + 1;
        if (count > 1) {
            int p2 = solve(N / static_cast<lli>(pow(2, count - 1))) + 1;
            return (p1 % 2 == 0)? p2: p1;
        } else {
            return p1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli N = Read<lli>();
        if (solve(N) % 2 == 0) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }
    return 0;
}