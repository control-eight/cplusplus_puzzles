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
        lli N = Read<lli>();
        lli K = Read<lli>();
        if (K == 1) {
            cout << (N - 1) * 2 << endl;
        } else if (K == 2) {
            cout << (N - 2) * 2 << endl;
        } else {
            lli left = (N - K) * 2;
            lli right = ((K - 1) / 2) * 2;
            cout << left + right << endl;
        }
    }
    return 0;
}