#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

// int tc = 0;
void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, vector<int>> mp1;
    map<pair<int, int>, vector<int>> mp2;
    map<pair<int, int>, vector<int>> mp3;
    vector<int> v(n);
    for(auto &x : v) cin >> x;
    // tc++;
    // if(tc == 1110) {
    //     string s = to_string(n);
    //     s+="//";
    //     for(int i = 0; i < n; i++) {
    //         s += to_string(v[i]);
    //         s+="//";
    //     }
    //     cout << s << "\n";
    //     return;
    // }

    for(int i = 0; i < n-2; i++) {
        int ff = v[i];
        int ss = v[i+1];
        int tt = v[i+2];

        mp1[{ff, ss}].push_back(tt);
        mp2[{ss, tt}].push_back(ff);
        mp3[{ff, tt}].push_back(ss);
    }  
    int sm = 0;
    for(auto &x : mp1) {
        vector<int> tmp = x.second;
        map<int, int> cnt;
        for(auto &y : tmp) cnt[y]++;
        if (cnt.size() == 1) continue;
        
        int sm2 = 0;
        for(auto &x : cnt) {
            sm2 += x.second;
        }        
        for(auto &x : cnt) {
            sm2 -= x.second;
            sm += sm2*x.second;
            sm2 += x.second;
        }
    }


    for(auto &x : mp2) {
        vector<int> tmp = x.second;
        map<int, int> cnt;
        for(auto &y : tmp) cnt[y]++;
            if (cnt.size() == 1) continue;
        // int first = (*cnt.begin()).second;
        // cnt.erase(cnt.begin());

    
        int sm2 = 0;
        for(auto &x : cnt) {
            sm2 += x.second;
        }        
        for(auto &x : cnt) {
            sm2 -= x.second;
            sm += sm2*x.second;
            sm2 += x.second;
        }

    }

    //     cout << "here " << " " << " ";
    // cout << sm << "\n";

    for(auto &x : mp3) {
        vector<int> tmp = x.second;
        map<int, int> cnt;
        for(auto &y : tmp) cnt[y]++;
            if (cnt.size() == 1) continue;
        // int first = (*cnt.begin()).second;
        // cnt.erase(cnt.begin());

        int sm2 = 0;
        for(auto &x : cnt) {
            sm2 += x.second;
        }        
        for(auto &x : cnt) {
            sm2 -= x.second;
            sm += sm2*x.second;
            sm2 += x.second;
        }
    }
    cout << sm/2 << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}