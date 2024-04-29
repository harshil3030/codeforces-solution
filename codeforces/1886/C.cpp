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
    int pos; cin >> pos;
    int termsToBeDeleted = 0;
    for(int t = n; t >= 1; t--) {
        if (pos <= t) {
            break;
        }
        pos -= t;
        termsToBeDeleted++; 
    }   
    int prev = 0, next = 1;
    vector<int> vis(n, -1);
    int numberOfDeletion = 1;
    while (next < n) {
        while(prev >= 0 && vis[prev] != -1) {
            prev-=1;
        }
        if (prev == -1) {
            next += 1;
            prev = next - 1;
        }
        if (next < n && s[prev] > s[next]) {
            vis[prev] = numberOfDeletion++;
            prev--;
        }else {
            next++, 
            prev = next - 1;
        }
    }
    next = n-1;
    while (next >= 0) {
        if (vis[next] == -1) {
            vis[next] = numberOfDeletion++;
        }
        next -= 1;
    }

    for(int i = 0; i < n; i++) {
        if (vis[i] <= termsToBeDeleted) continue;
        pos--;
        if (pos == 0) {
            cout << s[i];
            break;
        }
    }
}
