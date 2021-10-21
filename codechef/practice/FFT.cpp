#include <iostream>
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

template <bool inverse>
void AndConvolution(std::vector<lli>& P) {
    lli len, i, j;
    lli u, v;
    for (len = 1; 2 * len <= P.size(); len <<= 1) {
        for (i = 0; i < P.size(); i += 2 * len) {
            for (j = 0; j < len; j++) {
                u = P[i + j];
                v = P[i + len + j];
                if (!inverse) {
                    P[i + j] = v;
                    P[i + len + j] = u + v;
                }
                else {
                    P[i + j] = -u + v;
                    P[i + len + j] = u;
                }
            }
        }
    }
}

template<bool inv>
void or_convolution(int n, int *a) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        if (!inv) {
            a[i + (1 << (n - 1))] += a[i];
        } else {
            a[i + (1 << (n - 1))] -= a[i];
        }
    }
    or_convolution<inv>(n - 1, a);
    or_convolution<inv>(n - 1, a + (1 << (n - 1)));
}

template<bool inv>
void and_convolution(int n, int *a) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        if (!inv) {
            a[i] += a[i + (1 << (n - 1))];
        } else {
            a[i] -= a[i + (1 << (n - 1))];
        }
    }
    and_convolution<inv>(n - 1, a);
    and_convolution<inv>(n - 1, a + (1 << (n - 1)));
}

int main() {
    int x[16];
    fill(x, x + 16, 0);
    std::vector<lli> P(16);
    P[2] = 1;
    P[3] = 1;
    P[5] = 1;
    //
    x[3] = 1;
    x[7] = 1;
    x[8] = 1;
    x[11] = 1;
    AndConvolution<false>(P);
    AndConvolution<true>(P);
    for (lli v : P) {
        cout << v << endl;
    }
    cout << " " << endl;
    or_convolution<false>(4, x);
    //or_convolution<true>(4, x);
    for (lli v : x) {
        cout << v << endl;
    }
    return 0;
}