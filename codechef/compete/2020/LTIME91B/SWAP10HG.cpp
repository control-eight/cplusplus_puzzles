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
        std::string S = Read<std::string>();
        std::string P = Read<std::string>();
        int ones_count_S = 0;
        int ones_count_P = 0;
        int zeros_diff = 0;
        bool ans = true;
        for (int i = 0; i < N; i++) {
            if (S[i] == '1') {
                ones_count_S++;
            }
            if (P[i] == '1') {
                ones_count_P++;
            }
            if (S[i] != P[i]) {
                if (S[i] == '0') {
                    zeros_diff++;
                } else {
                    zeros_diff--;
                }
            }
            if (zeros_diff > 0) {
                ans = false;
                break;
            }
        }
        if (ans && ones_count_S == ones_count_P) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}