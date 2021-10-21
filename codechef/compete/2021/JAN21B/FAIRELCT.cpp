#include <iostream>
#include <vector>
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
        int M = Read<int>();
        vector<int> ns;
        while(N--) {
            ns.push_back(Read<int>());
        }
        vector<int> ms;
        while(M--) {
            ms.push_back(Read<int>());
        }
        lli ns_sum = 0;
        for (int el : ns) {
            ns_sum += el;
        }
        lli ms_sum = 0;
        for (int el : ms) {
            ms_sum += el;
        }
        if (ns_sum > ms_sum) {
            cout << 0 << endl;
        } else {
            sort(ns.begin(), ns.end());
            sort(ms.begin(), ms.end());
            int i = 0;
            int j = ms.size() - 1;
            int swaps = 0;
            while (i < ns.size() && j >= 0) {
                //if (ms[j] <= ns[i]) {
                //    break;
                //}
                if (ns_sum > ms_sum) {
                    break;
                }
                ns_sum -= ns[i];
                ns_sum += ms[j];

                ms_sum -= ms[j];
                ms_sum += ns[i];

                i++;
                j--;
                swaps++;
            }
            if (ns_sum > ms_sum) {
                cout << swaps << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}