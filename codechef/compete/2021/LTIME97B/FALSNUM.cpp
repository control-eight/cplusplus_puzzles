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
        string s = Read<string>();
        if (s[0] == '1') {
            cout << s.substr(0, 1) + "0" + s.substr(1, s.size() - 1) << endl;
        } else {
            cout << "1" + s << endl;
        }
    }
    return 0;
}