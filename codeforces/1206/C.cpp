#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;


void solve() {
    int n;
    cin >> n;
    int last = 2*n;
    int curr = 2;
    vector<int> v(2*n);

    bool mn = true;
    for (int i = 0; i < n; i++) {
        if (mn) {
            v[i] = curr - 1;
            v[i + n] = curr;
            mn = false;
        } else {
            v[i] = curr;
            v[i + n] = curr - 1;
            mn = true;
        }
        curr += 2;
    }

    bool ok = true;
    vector<int> sm;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
    }
    sm.push_back(sum);
    for (int i = n; i < 2*n; i++) {
        sum += v[i];
        sum -= v[i-n];
        sm.push_back(sum);
    }
    for(int i = 0; i < n; i++) {
        sum += v[i];
        sum -= v[n+i];
        sm.push_back(sum);
    }

    int mini = *min_element(sm.begin(), sm.end());
    int maxi = *max_element(sm.begin(), sm.end());
    if (maxi - mini > 1) ok = false;
    if (!ok) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 0; i < 2*n; i++) {
            cout << v[i] << " ";
        } cout << "\n";
    }


}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}