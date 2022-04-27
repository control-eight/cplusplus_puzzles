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

double binarySearch(const vector<lli>& v, double sum) {
    double lo = 0;
    double hi = sum;
    lli mmm = median(v);
    double target = mmm * v.size();
    double mm = mmm;
    while (lo < hi - 1) {
        mm = (hi - lo) / 2 + lo;
        target = mm * v.size();
        double newSum = (sum - mmm) + mm;
        if (target == newSum) {
            return mm;
        }
        if (target < newSum) {
            lo = mm;
        } else {
            if (((mm - 1) * v.size()) > ((sum - mmm) + mm - 1)) {
                hi = mm;
            } else {
                return mm;
            }
        }
    }
    return mm;
}

lli find(vector<lli>& v, lli sum) {
    double mean = static_cast<double>(sum) / v.size();
    if (median(v) == mean) {
        return 0;
    }
    //lli m = std::ceil(binarySearch(v, sum));
    if (median(v) > mean) {
        return median(v) * v.size() - (sum - median(v) + median(v));
    }

    lli m;
    lli int_m = (sum - median(v)) / (v.size() - 1);
    if ((sum - median(v)) % (v.size() - 1) > 0) {
        m = int_m + 1;
    } else {
        m = int_m;
    }
    lli count = m - median(v);
    return count + (m * v.size() - (sum - median(v) + m));
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