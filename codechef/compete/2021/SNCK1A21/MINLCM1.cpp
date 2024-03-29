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
        lli X = Read<lli>();
        lli K = Read<lli>();

        cout << 2 * X << " ";
        lli a2 = X * K * (X * K - 1);
        cout << a2 << endl;
    }
    return 0;
}