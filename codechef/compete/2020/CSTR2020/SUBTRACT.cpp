//
// Created by Oleksandr Bykovskyi on 12/22/20.
//

#include <iostream>
using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = read<int>();
    int k = read<int>();
    while(k--) {
        if (n % 10 == 0) {
            n = n / 10;
        } else {
            n--;
        }
    }
    cout << n << endl;
    return 0;
}