//
// Created by Oleksandr Bykovskyi on 12/22/20.
//

#include <iostream>
#include <vector>
using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int gcdVector(vector<int> v) {
    int ans = v[0];
    for (int i = 1; i < v.size(); i++) {
        ans = gcd(v[i], ans);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = read<int>();
    while (T--) {
        int N = read<int>();
        vector<int> reqs;
        int sum = 0;
        while (N--) {
            int req = read<int>();
            reqs.push_back(req);
            sum += req;
        }
        int gcd = gcdVector(reqs);
        cout << gcd << " "  << sum / gcdVector(reqs) << endl;
    }
    return 0;
}