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
        lli N = Read<int>();
        lli M = Read<int>();
        lli X = Read<int>();
        lli Y = Read<int>();

        if (N == 1 || M == 1) {
            cout << (N + M - 2) * X << endl;
        } else {
            lli p1 = (N + M - 2) * X;
            lli p2 = (std::min(N, M) - 1) * Y + std::abs(M - N) * X;
            lli mmm = std::min(N, M) - 1;
            lli p3 = mmm * Y;
            if ((N + M) % 2 == 0) {
                p3 += ((N - mmm) + (M - mmm) - 2) * Y;
            } else {
                p3 += ((N - mmm) + (M - mmm) - 3) * Y + X;
            }
            cout << std::min(std::min(p1, p2), p3) << endl;
        }
    }
    return 0;
}