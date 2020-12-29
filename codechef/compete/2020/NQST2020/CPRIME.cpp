#include <iostream>
#include <cmath>
using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T Read() { T a; cin >> a; return a; }

bool IsPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int boundary = sqrt(n);
    for (int i = 3; i <= boundary; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool IsPalindromic(int n) {
    std::string str = std::to_string(n);
    int i = 0;
    int j = str.size() - 1;
    while (i != j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        if ( IsPalindromic(N) && IsPrime(N)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}