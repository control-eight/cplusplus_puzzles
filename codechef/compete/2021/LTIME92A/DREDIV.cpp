#include <iostream>
#include <vector>

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
        int n = Read<int>();
        int k = Read<int>();
        while (k % 2 == 0) {
            k /= 2;
        }
        vector<int> els;
        bool ans = 1;
        while(n--) {
            if (Read<int>() % k != 0) {
                ans = 0;
            }
        }
        if (ans) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}