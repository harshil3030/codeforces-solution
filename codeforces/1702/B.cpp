#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    string s; cin >> s;
    int n = s.length();
    map<char, int> mp;
    int need = 3;
    int day = 0; int temp = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
        if (mp.size() % 4 == 0){
         day++;
         // last = mp.size();
         mp.clear();
         mp[s[i]]++;
        } 
        
    }  
    if (mp.size() < 4) {
        day++;
    }
    cout << day << "\n";
}
