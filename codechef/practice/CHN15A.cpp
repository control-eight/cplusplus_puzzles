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
        int N = read<int>();
        int K = read<int>();
        int ans = 0;
        while (N--) {
            int number = read<int>();
            if ((number + K) % 7 == 0) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}