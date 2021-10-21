#include <iostream>
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

void Print(unordered_map<lli, lli> ans, int M, int N) {
    for (int i = 0; i < M * N; i++) {
        cout << i + 1 << " = " << ans[i + 1] << endl;
    }
}

void Print(unordered_map<lli, lli> map) {
    int sum = 0;
    for (auto[k, v] : map) {
        sum += v;
        cout << k << " = " << v << endl;
    }
    cout << "Total: " << sum << endl;
}

int ModInverse(lli a, lli m) {
    lli m0 = m;
    lli y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        lli q = a / m;
        lli t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

long long degree(long long a, long long k, long long p) {
    long long res = 1;
    long long cur = a;

    while (k) {
        if (k % 2) {
            res = (res * cur) % p;
        }
        k /= 2;
        cur = (cur * cur) % p;
    }
    return res;
}

long long combinations(int n, int k, long long p) {
    int num_degree = degree(n, p, 1) - degree(n - k, p, 1);
    int den_degree = degree(k, p, 1);

    if (num_degree > den_degree) {
        return 0;
    }
    long long res = 1;
    for (long long i = n; i > n - k; --i) {
        long long ti = i;
        while(ti % p == 0) {
            ti /= p;
        }
        res = (res * ti) % p;
    }
    for (long long i = 1; i <= k; ++i) {
        long long ti = i;
        while(ti % p == 0) {
            ti /= p;
        }
        res = (res * degree(ti, p-2, p)) % p;
    }
    return res;
}

lli fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

unordered_map<lli, lli> Solve(int M, int N, int K, int modulo) {
    unordered_map<lli, lli> res{{1, K}};
    if (M == 1) {
        for (int i = 1; i <= N - 1; i++) {
            //int structure = fact(N - 1) / (fact(i) * fact(N - 1 - i));
            lli structure = combinations(N - 1, i, modulo);
            lli pairs = K * degree(K - 1, i, modulo);
            res[i + 1] = (pairs * structure) % modulo;
        }
    } else {
        int size = M * N;
        lli P = 0;
        if (K >= 3) {
            P = fact(K - 1) / fact(K - 3);
        }
        lli P1 = fact(K) / (fact(2) * fact(K - 2));
        lli P2 = fact(K) / fact(K - 2);
        int odd = 1;
        for (int i = 2; i <= size; i++) {
            //int structure = fact(N - 1) / (fact(i) * fact(N - 1 - i));
            //works
            lli structure = combinations(size, i, modulo);
            //for even also works
            lli pairs = 0;
            if (i % 4 == 0 ) {
                // (4 по 3) - (K - 1 + K - 2)
                pairs = 2 * P1 * (P2 - (K - 1 + K - 2));
            } else if (i % 2 == 0) {
                pairs = K * degree(K - 1, i - 1, modulo);
            } else if (P > 0) {
                pairs = K * degree(P, odd, modulo);
                odd++;
            }
            res[i] = (pairs * structure) % modulo;
        }
    }
    return res;
}

int main() {
    //cout << combinations(100000, 500, 998244353) << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int M = Read<int>();
    int N = Read<int>();
    int K = Read<int>();

    int modulo = 998244353;
    unordered_map<lli, lli> res = {{1, 1}};
    if (K > 1) {
        res = Solve(M, N, K, modulo);
    }
    Print(res);
    // Calc Answer:
    lli P = 0;
    for (auto [count, value] : res) {
        P += (count * value) % modulo;
    }
    //cout << P << endl;
    lli Q = ModInverse(pow(K, M*N), modulo);
    cout << ((P * Q) % modulo) << endl;
    return 0;
}