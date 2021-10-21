#include <iostream>
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
        int X = Read<int>();
        if (X < N) {
            cout << "Yes" << endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (X / i == 0 && X / i <= N) {
                cout << "Yes" << endl;
                ans = 1;
                break;
            }
        }
        if (!ans) {
            cout << "No" << endl;
        }
    }
    return 0;
}