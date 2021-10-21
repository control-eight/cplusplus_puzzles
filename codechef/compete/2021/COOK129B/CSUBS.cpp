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
        int N = Read<int>();
        int K = Read<int>();
        unordered_map<int, int> freq [K];
        for (int i = 0; i < N; i++) {
            int ll = Read<int>();
            freq[i % K][ll]++;
        }
        int ans = 0;
        for (int i = 0; i < K; i++) {
            int t = 0;
            int mmax = 0;
            for (const auto& [number, count] : freq[i]) {
                t += count;
                mmax = max(mmax, count);
            }
            ans += t - mmax;
        }
        cout << ans << endl;
    }
    return 0;
}