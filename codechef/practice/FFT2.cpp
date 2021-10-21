#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
const int max_n = 1 << 20, inf = 1000111222;

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

int t, n, m, a[max_n] = {}, b[max_n] = {}, ans[max_n] = {}, tmp[max_n] = {};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        int mx = 0;
        while (n--) {
            int x;
            scanf("%d", &x);
            a[x] = 1;
            mx = max(mx, x);
        }
        while (m--) {
            int x;
            scanf("%d", &x);
            b[x] = 1;
            mx = max(mx, x);
        }
        int lev = 0;
        while (mx >= (1 << lev)) {
            ++lev;
        }
        a[0] = 1;
        b[(1 << lev) - 1] = 1;
        or_convolution<false>(lev, a);
        and_convolution<false>(lev, b);
        ans[0] = 1;
        for (bool change = true; change; ) {
            copy(ans, ans + (1 << lev), tmp);
            or_convolution<false>(lev, tmp);
            for (int i = 0; i < (1 << lev); ++i) {
                tmp[i] *= a[i];
            }
            or_convolution<true>(lev, tmp);
            for (int i = 0; i < (1 << lev); ++i) {
                tmp[i] = tmp[i] > 0;
            }
            and_convolution<false>(lev, tmp);
            for (int i = 0; i < (1 << lev); ++i) {
                tmp[i] *= b[i];
            }
            and_convolution<true>(lev, tmp);
            change = false;
            for (int i = 0; i < (1 << lev); ++i) {
                tmp[i] = tmp[i] > 0;
                change |= ans[i] != tmp[i];
                ans[i] = tmp[i];
            }
        }
        int tot = accumulate(ans, ans + (1 << lev), 0);
        printf("%d\n", tot);
        fill(a, a + (1 << lev), 0);
        fill(b, b + (1 << lev), 0);
        fill(ans, ans + (1 << lev), 0);
    }
    return 0;
}
