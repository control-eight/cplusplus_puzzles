//
// Created by Oleksandr Bykovskyi on 12/22/20.
//

#include <iostream>
#include <unordered_map>

using namespace std;
#define iter(x) (x).begin(), (x).end()
using lli = long long int;
template <typename T> T read() { T a; cin >> a; return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N = read<int>();
    std::unordered_map<int, int> numbers;
    int tmpN = N;
    while (tmpN--) {
        numbers[read<int>()]++;
    }
    tmpN = N + 1;
    while (tmpN--) {
        numbers[read<int>()]--;
    }
    for (auto [number, count] : numbers) {
        if (count != 0) {
            cout << number << endl;
        }
    }
    return 0;
}