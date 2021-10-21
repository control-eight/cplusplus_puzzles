#include <iostream>
#include <vector>
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
        int N = Read<int>();
        lli ans = 0;
        while (N--) {
            int M = Read<int>();
            std::vector<int> ants;
            while (M--) {
                ants.push_back(Read<int>());
            }
            lli neg = 0;
            lli pos = 0;
            for (int ant : ants) {
                if (ant < 0) {
                    neg++;
                } else {
                    pos++;
                }
            }
            lli min = std::min(pos, neg);
            lli max = std::max(pos, neg);
            ans += ((max - min) + max - 1)*(min)/2;
            ans += (1 + min - 1)*(min - 1)/2;
            ans += min;
        }
        cout << ans << endl;
    }
    return 0;
}