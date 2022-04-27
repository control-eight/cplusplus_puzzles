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

vector<lli> primeFactors(lli n) {
    vector<lli> result;
    while (n % 2 == 0) {
        n = n/2;
        result.push_back(2);
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            n = n/i;
            result.push_back(i);
        }
    }
    if (n > 2) {
        result.push_back(n);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli N = Read<lli>();
        vector<lli> factors = primeFactors(N);
        if (factors.size() == 1) {
            cout << N + 1 << endl;
        } else {
            cout << (N / factors.front()) * (factors.front() + 1) << endl;
        }
    }
    return 0;
}