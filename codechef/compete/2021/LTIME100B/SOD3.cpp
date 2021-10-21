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

lli SOD(lli n) {
    lli sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        lli L = Read<lli>();
        lli R = Read<lli>();
        lli L1 = SOD(L)%3 != 0? L + (3 - SOD(L)%3): L;
        lli R1 = SOD(R)%3 != 0? R - SOD(R)%3: R;
        if (R1 >= L1) {
            lli count = (R1-L1)/3 + 1;
            cout << count << endl;
        } else if (L1 > R1) {
            if (SOD(R) % 3 == 0 || SOD(L) % 3 == 0) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }  else {
            cout << 0 << endl;
        }
        /*int c = 0;
        for (int i = L; i <= R; i++) {
            if (SOD(i) % 3 == 0) {
                c++;
            }
        }
        cout << "T: " << c << endl;*/
    }
    return 0;
}