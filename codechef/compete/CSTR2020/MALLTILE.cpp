//
// Created by Oleksandr Bykovskyi on 12/22/20.
//

#include <iostream>
#include <cmath>

using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = read<int>();
    int m = read<int>();
    int a = read<int>();
    cout << ceil(n * 1.0 / a) * ceil(m * 1.0 / a) << endl;
    return 0;
}