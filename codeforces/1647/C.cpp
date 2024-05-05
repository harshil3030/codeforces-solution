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
    int n,m; 
    cin >> n >> m;
    string s[n];
    for (int i  =0; i < n; i++) {
        cin >> s[i];
    }

    if(s[0][0] == '1') {
        cout << "-1" << endl;
        return;
    }
    vector<vector<int>> ans;
    for (int col = 0; col < m; col++) {
        for (int row = n-1; row > 0; row--) {
            if (s[row][col] == '1') {
                vector<int> temp;
                temp.push_back(row - 1);
                temp.push_back(col);
                temp.push_back(row);
                temp.push_back(col);
                ans.push_back(temp);
            }
        }
    }

    for (int col = m-1; col > 0; col--) {
        if (s[0][col] == '1') {
                vector<int> temp;
                temp.push_back(0);
                temp.push_back(col-1);
                temp.push_back(0);
                temp.push_back(col);
                ans.push_back(temp);
        }
    }
    
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < 4; j++) {
            cout << ans[i][j] + 1 << " ";
        } cout << "\n";
    }
}
