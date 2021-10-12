#include <iostream>
#include <vector>
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

const int MAX = 1000000000;
int spf[MAX];
bool cache[MAX] = { false };

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        spf[i] = i;
    }
    for (int i = 4; i < MAX; i += 2) {
        spf[i] = 2;
    }
    for (int i = 3; i * i < MAX; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAX; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void getFactorizationUsingSPF(int x) {
    int spf_el;
    while (x != 1) {
        spf_el = spf[x];
        if (x % spf_el == 0) {
            cache[spf[x]] = true;
            x = x / spf[x];
        }
        while (x % spf_el == 0) {
            x = x / spf_el;
        }
    }
}


bool CheckCoprimeInArray(int x) {
    int spf_value;
    while (x != 1) {
        spf_value = spf[x];
        if (x % spf_value == 0) {
            if (cache[spf_value]) {
                return false;
            }
        }
        while (x % spf_value == 0) {
            x = x / spf_value;
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
        vector<int> numbers;
        for (int i = 0; i < N; i++) {
            int V = Read<int>();
            if (V % 2 == 0) {
                numbers.push_back(V/2);
            }
        }
        int target_size = ceil(N / 2.0);
        if (target_size > numbers.size()) {
            cout << "NO" << endl;
            continue;
        }
        sieve();
        for (int el : numbers) {
            getFactorizationUsingSPF(el);
        }
        bool found = false;
        for (int el : numbers) {
            if (CheckCoprimeInArray(el)) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}