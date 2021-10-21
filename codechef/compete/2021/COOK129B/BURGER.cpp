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
        int X = Read<int>();
        int Y = Read<int>();

        if (Y % X != 0) {
            cout << -1 << endl;
            continue;
        }
        double target = Y / X;
        int ans = 0;
        unordered_set<int> met;
        while (target > 0) {
            int i = log2(target) + 1;
            if (pow(2, i) - 1 > target) {
                i--;
            }
            while (i >= 0 && !met.insert(i).second) {
                i--;
            }
            if (i == -1) {
                ans = -1;
                break;
            }
            target -= pow(2, i) - (i > 0? 1: 0);
            ans += i + 1;
        }
        ans = ans > 0? ans-1: ans;
        cout << ans << endl;
    }
    return 0;
}