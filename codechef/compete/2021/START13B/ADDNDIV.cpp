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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli a = Read<lli>();
        lli b = Read<lli>();
        if (a == 1) {
            cout << "YES" << endl;
        } else if (b == 1) {
            cout << "NO" << endl;
        } else {
            int g = 0;
            while (g != 1) {
                g = gcd(a, b);
                a /= g;
            }
            if (a != 1) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}