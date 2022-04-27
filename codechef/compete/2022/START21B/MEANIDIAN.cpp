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

lli median(const vector<lli>& v) {
    int n = v.size();
    if (n % 2 != 0) {
        return v[n / 2];
    } else {
        return v[n / 2 - 1];
    }
}

lli find(vector<lli>& v, lli sum) {
    double mean = static_cast<double>(sum) / v.size();
    lli count = 0;
    if (median(v) == mean) {
        return 0;
    }
    lli m = median(v);
    while (m < mean) {
        lli delta = static_cast<lli>(std::ceil(mean - m));
        count += delta;
        mean += (static_cast<double>(delta)/v.size());
        m += delta;
    }
    if (m == mean) {
        return count;
    }
    double diff = round((m - mean) * 1000000000.0) / 1000000000.0;
    return count + (std::ceil(diff*v.size()));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        std::vector<lli> v;
        lli sum = 0;
        for (int i = 0; i < N; i++) {
            v.push_back(Read<lli>());
            sum += v.back();
        }
        sort(v.begin(), v.end());
        cout << find(v, sum) << endl;
    }
    return 0;
}