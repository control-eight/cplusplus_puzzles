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
        string S = read<string>();
        if (S.length() % 2 == 1) {
            cout << -1 << endl;
        } else {
            int count = 0;
            for (const char c : S) {
                if (c == '1') {
                    count++;
                }
            }
            if (count == S.length() / 2) {
                cout << 0 << endl;
            } else if (count == 0 || count == S.length()) {
                cout << -1 << endl;
            } else {
                cout << abs(static_cast<int>(S.length()) - 2 * count)/2 << endl;
            }
        }
    }
    return 0;
}