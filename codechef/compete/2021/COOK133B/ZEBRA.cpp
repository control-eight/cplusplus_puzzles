#include <iostream>

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
        int N = Read<int>();
        int K = Read<int>();
        string s = Read<string>();

        bool color = s[0] == '1';
        int jumps = 0;
        int last = -1;
        for (int i = 1; i < N; i++) {
            bool check_color = s[i] == '1';
            if (check_color != color) {
                if (K - jumps == 1) {
                    last = i;
                } else {
                    jumps++;
                    color = !color;
                }
            }
        }
        if (jumps < K && last == -1) {
            cout << -1 << endl;
        } else {
            cout << last + 1 << endl;
        }
    }
    return 0;
}