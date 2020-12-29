#include <iostream>
#include <cmath>
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
        int N = Read<int>();
        int K = Read<int>();
        if (N > K) {
            cout << -1 << endl;
            continue;
        }
        vector<int> ans;33333
        while (N--) {
            int degree = log2(K);
            while (K - pow(2, degree) < N) {
                degree--;
            }
            K -= pow(2, degree);
            ans.push_back(degree);
        }
        if (K != 0) {
            cout << -1;
        } else {
            for (auto degree : ans) {
                cout << static_cast<char>('a' + degree);
            }
        }
        cout << endl;
    }
    return 0;
}