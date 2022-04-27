#include <iostream>
#include <vector>
#include <set>
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

std::set<lli> primeFactors(lli n) {
    std::set<lli> res;
    while (n % 2 == 0) {
        res.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            res.insert(i);
            n = n/i;
        }
    }
    if (n > 2) {
        res.insert(n);
    }
    return res;
}

std::vector<lli> allPrimeFactors(lli n) {
    std::vector<lli> res;
    while (n % 2 == 0) {
        res.push_back(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            res.push_back(i);
            n = n/i;
        }
    }
    if (n > 2) {
        res.push_back(n);
    }
    return res;
}

void Print(std::set<lli> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        int M = Read<int>();

        std::set<lli> primes1 = primeFactors(N);
        std::set<lli> primes2 = primeFactors(M);

        lli res = 0;
        if (primes2.size() >= N) {
            res = N;
        } else {
            for (int i = 2; i <= primes2.size(); i++) {
                if (N % i == 0) {
                    res = std::max(res, (lli)i);
                }
            }
        }
        if (res == 0 && M > 1) {
            cout << 1 << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}