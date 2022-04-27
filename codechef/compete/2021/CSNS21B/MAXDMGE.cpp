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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = Read<int>();
    while (T--) {
        int N = Read<int>();
        vector<lli> elements;
        for (int i = 0; i < N; i++) {
            elements.push_back(Read<lli>());
        }
        cout << (elements.front() & elements[1]) << " ";
        for (int i = 1; i < N - 1; i++) {
            cout << std::max(elements[i] & elements[i - 1], elements[i] & elements[i + 1]) << " ";
        }
        cout << (elements.back() & elements[elements.size() - 2]) << endl;
    }
    return 0;
}