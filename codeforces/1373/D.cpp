#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int t = 0;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;

    vector<int> even;
    vector<int> odd;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) even.push_back(v[i]);
        else odd.push_back(v[i]);
    }   
    int sm = 0;
    int smOfEven = 0;
    for (auto &x : even) smOfEven += x;

    int mxdiff = 0;
    if (n % 2) {
        for (int i =0; i < even.size(); i++) {
            if (i == 0 && n == 1){
                continue;
            }else if (i == 0) {
                mxdiff = max(mxdiff, odd[i] - even[i]);
            }else if (i == (even.size() - 1)){
                mxdiff = max(mxdiff, odd[i-1] - even[i]);
            } else {
                mxdiff = max(mxdiff, odd[i] - even[i]);
                mxdiff = max(mxdiff, odd[i-1] - even[i]);
            }
        }
    } else {
        for (int i = 0; i < even.size(); i++) {
            if (i == 0) {
                mxdiff = max(mxdiff, odd[i] - even[i]);
            } else {
                mxdiff = max(mxdiff, odd[i] - even[i]);
                mxdiff = max(mxdiff, odd[i-1] - even[i]);
            }
        }
    }
    int totsm = 0;
    for (int i = 0; i < odd.size(); i++) {
        totsm += odd[i] - even[i];
        if (totsm < 0) {
            totsm = 0;
            continue;
        }
        mxdiff = max(mxdiff, totsm);
    } 
    totsm = 0;
    for (int i = 1; i < even.size(); i++) {
        totsm += odd[i-1] - even[i];
        if (totsm < 0) {
            totsm = 0;
            continue;
        }
        mxdiff = max(mxdiff, totsm);
    }

    cout << smOfEven + mxdiff << "\n";
}
