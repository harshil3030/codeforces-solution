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
    int less; cin >> less;
    int poi = 0;
    for (int i = 0; i < n; i++) poi += s[i] - 'a' + 1;
    int del = poi - less;
    
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) {
        vp[i] = {s[i] - 'a' + 1*1ll, i};
    }
    int in = n-1;
    int sm = 0;
    sort(vp.rbegin(), vp.rend());
    for (int i = 0; i < n; i++) {
        sm += vp[i].first;
        if (sm >= del) {
            in = i;
            break;
        }
    }
    if (del <= 0) {
        cout << s << "\n";
        return;
    }
    in++;
    if (in >= n) {
        cout << "" << "\n";
        return;
    } else {
        vector<pair<int, int>> temp;
        temp.insert(temp.end(),vp.begin() + in, vp.end());
        auto comp = [](pair<int, int> p1, pair<int, int> p2) {
            return p1.second < p2.second;
        };
        sort(temp.begin(), temp.end(), comp);
        for (int i = 0; i < temp.size(); i++) {
            cout << char((temp[i].first - 1) + 'a');
        } cout << "\n";
    }
}
