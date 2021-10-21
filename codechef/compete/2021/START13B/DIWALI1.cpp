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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli P = Read<lli>();
        lli a = Read<lli>();
        lli b = Read<lli>();
        lli c = Read<lli>();
        lli x = Read<lli>();
        lli y = Read<lli>();

        lli z = y * a + c;
        if ((x * a + b) < (y * a + c)) {
            z = x * a + b;
        }

        cout << P/z << endl;
    }
    return 0;
}