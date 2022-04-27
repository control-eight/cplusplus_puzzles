#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

lli calc(const vector<int>& v, int index) {
    lli res = 0;
    for (int i = index; i >= 0; i--) {
        int mod = (res + v[i]) % 10;
        if (mod > 0) {
            res += 10 - mod;
        }
    }
    return res;
}

int binarySearch(const vector<int>& v, int K) {
    int lo = 0;
    int hi = v.size();
    int res = -1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        lli k = calc(v, mid);
        if (k <= K) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int K = Read<int>();
        vector<int> v;
        v.reserve(N);
        for (int i = 0; i < N; i++) {
            v.push_back(Read<char>() - '0');
        }
        int index = binarySearch(v, K);
        cout << index + 1 << endl;
    }
    return 0;
}