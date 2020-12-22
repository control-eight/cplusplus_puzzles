//
// Created by Oleksandr Bykovskyi on 12/21/20.
//
#include <string>
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
        auto line = read<string>();
        double count = 0;
        for (const char c : line) {
            if (c == '1') {
                count++;
            }
        }
        if ((count + (120 - N)) / 120 >= 0.75) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}