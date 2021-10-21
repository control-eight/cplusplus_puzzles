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

int powmod (int a, int b, int p) {
    int res = 1;
    while (b)
        if (b & 1)
            res = int (res * 1ll * a % p),  --b;
        else
            a = int (a * 1ll * a % p),  b >>= 1;
    return res;
}

int generator (int p) {
    vector<int> fact;
    int phi = p-1,  n = phi;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            fact.push_back (i);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        fact.push_back (n);

    for (int res=2; res<=p; ++res) {
        bool ok = true;
        for (size_t i=0; i<fact.size() && ok; ++i)
            ok &= powmod (res, phi / fact[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}

int main() {
    cout << generator(1) << endl;
    cout << generator(2) << endl;
    cout << generator(3) << endl;
    cout << generator(4) << endl;
    cout << generator(5) << endl;
    cout << generator(6) << endl;
    cout << generator(7) << endl;
    cout << generator(8) << endl;
    cout << generator(9) << endl;
    cout << generator(10) << endl;
    cout << generator(11) << endl;
    cout << generator(12) << endl;
    cout << generator(13) << endl;
    cout << generator(14) << endl;
    cout << generator(15) << endl;
    cout << generator(16) << endl;
    cout << generator(17) << endl;
    cout << generator(18) << endl;
    cout << generator(19) << endl;
    cout << generator(20) << endl;
    cout << generator(21) << endl;
    cout << generator(737) << endl;
    return 0;
}