//
// Created by Oleksandr Bykovskyi on 12/21/20.
//
#include <iostream>
using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

lli factorial(int number) {
    lli result = 1;
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = read<int>();
    while (T--) {
        int number = read<int>();
        lli ans = factorial(number);
        cout << ans << endl;
    }
    return 0;
}