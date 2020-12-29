//
// Created by Oleksandr Bykovskyi on 12/21/20.
//

#include <iostream>
using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = read<int>();
    while (T--) {
        int x = read<int>();
        int y = read<int>();
        int K = read<int>();
        int N = read<int>();

        int diff = abs(y - x);
        if (diff % K == 0 && ((diff / K) % 2 == 0)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}