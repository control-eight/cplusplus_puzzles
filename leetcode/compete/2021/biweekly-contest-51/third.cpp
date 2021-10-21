#include <iostream>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
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

void print(const vector<int> v) {
    cout << "[";
    for (int i : v) {
        cout << i << ", ";
    }
    cout << "]" << endl;
}

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        //print(arr);
        arr[0] = 1;
        int res = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (abs(arr[i] - arr[i - 1]) > 1) {
                arr[i] = arr[i - 1] + 1;
            }
            res = max(res, arr[i]);
        }
        //print(arr);
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> s1 = {2,2,1,2,1};
    cout << s.maximumElementAfterDecrementingAndRearranging(s1) << endl;
    std::vector<int> s2 = {100,1,1000};
    cout << s.maximumElementAfterDecrementingAndRearranging(s2) << endl;
    std::vector<int> s3 = {1,2,3,4,5};
    cout << s.maximumElementAfterDecrementingAndRearranging(s3) << endl;
    return 0;
}