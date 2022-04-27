#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

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

        if (N == 1 && K > 1 || N > 1 && K == 1) {
            cout << -1 << endl;
            continue;
        }
        int s = K - 1;
        for (int i = 1; i <= s; i++) {
            cout << i << " ";
        }
        for (int i = N; i >= s + 1; i--) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}