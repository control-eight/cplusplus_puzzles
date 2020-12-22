//
// Created by Oleksandr Bykovskyi on 12/22/20.
//

#include <iostream>
using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = read<int>();
    while (N--) {
        int number = read<int>();
        int even = 0;
        int odd = 0;
        while (number > 0) {
            int digit = number % 10;
            if (digit % 2 == 0) {
                even += digit;
            } else {
                odd += digit;
            }
            number /= 10;
        }
        if (even % 4 == 0 || odd % 3 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}