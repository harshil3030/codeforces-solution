#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
//-----------------------------------------------------------------------
void solve();
int bin_expo(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b % 2) {
            ans = ans * a;
        } b/=2;
        a = a * a;
    } return ans;
}
//-----------------------------------------------------------------------
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}
//-----------------------------------------------------------------------
void solve() {
    int n; cin >> n;
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int x; cin >> x;
        for (int j = 0; j < x; j++) {
            string phone; cin >> phone;
            mp[s].push_back(phone);
        }
    }
    cout << mp.size() << "\n";
    for (auto &x : mp) {
        vector<string> extra = x.second;
        int len = x.second.size();
        auto comp = [&](string s1, string s2) {
            return s1.size() < s2.size();
        };
        sort(extra.begin(), extra.end(), comp);
        map<string, int> need; 
        for (int i = 0; i < len; i++) {
            need[extra[i]]++;
        }
        for (int i = len - 1; i >= 0; i--) {
            int m = extra[i].size();
            for (int j = 0; j < m; j++) {
                string sub = extra[i].substr(j ,m-j);
                if (need.find(sub) != need.end()) {
                    need[sub]--; 
                }
            }
        }
        set<string> st;
        vector<string> ans;
        for (int i = 0; i < len; i++) {
            if(need[extra[i]] >= 0) {
                st.insert(extra[i]);
            }
        }
        ans.insert(ans.end(), st.begin(), st.end());
        cout << x.first << " ";
        cout << ans.size() << " ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        } cout << "\n";
    }
}


