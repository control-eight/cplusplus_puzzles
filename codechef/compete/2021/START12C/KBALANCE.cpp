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

int OneOp(int i, int K, std::string& S, bool dir) {
    if (!(((i - K) >= 0 && S[i - K] == '1') || ((i + K) <= (S.size() - 1) && S[i + K] == '1'))) {
        if (dir) {
            if (i + K <= S.size() - 1) {
                S[i + K] = '1';
                return 1;
            } else if (i - K >= 0) {
                S[i - K] = '1';
                return 1;
            } else {
                S[i] = '0';
                return 1;
            }
        } else {
            if (i - K >= 0) {
                S[i - K] = '1';
                return 1;
            } else if (i + K <= S.size() - 1) {
                S[i + K] = '1';
                return 1;
            } else {
                S[i] = '0';
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int K = Read<int>();
        std::string S = Read<string>();

        int i = 0;
        int j = S.size() - 1;
        int res = 0;
        while (i <= j) {
            if (S[i] == '1') {
                res += OneOp(i, K, S, true);
            }
            if (S[j] == '1') {
                res += OneOp(j, K, S, false);
            }
            i++;
            j--;
        }
        cout << res << endl;
    }
    return 0;
}