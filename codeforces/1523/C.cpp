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
int q; cin >> q;
    vector<int> v(q);
    int k = 0;
    for(int i = 0; i < q; i++) cin >> v[k++];
    vector<int> temp;
    for(int i = 0; i < k; i++) {
        if(v[i] != 1) while (!temp.empty() && temp.back() + 1 != v[i]) temp.pop_back();
        if(v[i] != 1) temp.pop_back();
         temp.push_back(v[i]);
        for(int ind = 0; ind < temp.size(); ind++) {
            cout << temp[ind];
            if(temp.size() - 1 != ind) cout << ".";
        } cout << "\n";
    }   
}
