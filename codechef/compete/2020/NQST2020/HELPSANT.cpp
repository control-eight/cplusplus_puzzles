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

std::vector<bool> FilterOutDuplicatesAndSort(std::vector<int> numbers) {
    std::vector<bool> ans(31, false);
    for (int el : numbers) {
        ans[el] = true;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //int T = Read<int>();
    //while (T--) {
        int N = Read<int>();
        std::vector<int> numbers;
        while (N--) {
            numbers.push_back(Read<int>());
        }
        std::vector<bool> ans = FilterOutDuplicatesAndSort(numbers);
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i]) {
                cout << i << " ";
            }
        }
        cout << endl;
    //}
    return 0;
}