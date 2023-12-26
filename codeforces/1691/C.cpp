#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void solve();

int countt(string s, int n) {
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            string t = s.substr(i,2);
            if (t == "11") ans += 11;
            else if (t == "10") ans += 10;
            else if (t == "01") ans += 1;
        }
        return ans;
    };

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n,k; cin >> n >> k;
    string s; cin >> s;
    int in1 = -1,in2 = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            in1 = i;
            break;
        }
    }   
    if (in1 == -1) {
        cout << 0 << "\n";
        return;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '1') {
            in2 = i;
            break;
        }
    }

    
    
    int req = n - in2 - 1;
    if (in2 == n - 1 && in1 == 0) {
        cout << countt(s,n) << "\n";
    } else {
        if (k >= req) {
            swap(s[in2], s[n-1]);
            k -= req;
        }
        if (in1 != n - 1)
        if (k >= in1) {
            swap(s[in1], s[0]);
        }
        cout << countt(s,n) << "\n";
    }

}
