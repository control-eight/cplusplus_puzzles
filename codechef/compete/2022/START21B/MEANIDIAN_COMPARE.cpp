#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;
#define Iter(x) (x).begin(), (x).end()
using lli = long long int;

#define fr(i,j,n) for(int i=j;i<n;++i)

template<typename T>
T Read() {
    T a;
    cin >> a;
    return a;
}

lli solve(vector<lli> arr){
    int n = arr.size();
    lli sm = 0;
    for (lli i : arr) {
        sm += i;
    }
    sort(arr.begin(), arr.end());
    lli l = arr[(n-1)/2], r = arr[n-1];
    int ans = l;
    while(l <= r){
        lli m = (l+r)/2;
        lli extra = n*m - sm;
        if(extra < 0){
            l = m+1;
            continue;
        }
        lli steps = 0;

        fr(i,(n-1)/2,n){
            if(arr[i] < m)
                steps += m - arr[i];
        }

        if(steps > extra){
            l = m+1;
        }
        else{
            r = m-1;
            ans = m;
        }
    }
    return (lli)n*ans - sm;
}

vector<lli> Generate(int n) {
    vector<lli> res;
    int l = n;
    while (l--) {
        res.push_back(rand() % n + 1);
    }
    return res;
}

lli median(const vector<lli>& v) {
    int n = v.size();
    if (n % 2 != 0) {
        return v[n / 2];
    } else {
        return v[n / 2 - 1];
    }
}

lli find(vector<lli>& v) {
    sort(v.begin(), v.end());
    lli sum = 0;
    for (lli i : v) {
        sum += i;
    }
    if (median(v) * v.size() == sum) {
        return 0;
    }
    //lli m = std::ceil(binarySearch(v, sum));
    if (median(v) * v.size() > sum) {
        return median(v) * v.size() - (sum - median(v) + median(v));
    }

    lli m;
    lli int_m = (sum - median(v)) / (v.size() - 1);
    if ((sum - median(v)) % (v.size() - 1) > 0) {
        m = int_m + 1;
    } else {
        m = int_m;
    }
    lli count = m - median(v);
    return count + (m * v.size() - (sum - median(v) + m));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(555);
    int n = 6;
    for (int i = 0; i < 5000; i++) {
        vector<lli> w = Generate(n);
        int ans11 = solve(w);
        int ans22 = find(w);
        if (ans11 != ans22) {
            cout << ans11 << " != " << ans22 << ", when ";
            for (int el : w) {
                cout << el << " ";
            }
            cout << endl;
        }
    }

    return 0;
}