#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
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
    string s; cin >> s;
    
    map<char, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }   
    if (n % 2) {
        cout << "-1\n";
        return;
        
    }
    for (auto &x : mp) {
        if (x.second > n/2) {
            cout << "-1\n";
            return;
        }
    }
     
    int cnt = 0;
    map<char, int> freq;
    int i = 0, j = n-1;
    while (i < j) {
        if (s[i] == s[j]) {
            cnt++;
            freq[s[i]]++;
        }
        i++, j--;
    }
    
    int mx = 0;
    for (auto &x : freq) {
        mx = max(mx, x.second);
    }
    
    cout << max((cnt+1)/2,mx)  << "\n";
}
