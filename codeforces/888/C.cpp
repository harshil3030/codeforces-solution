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
bool itcan(int k, string s) {
    int n = s.length();
    map<char, int> mp;
    map<char, int> freq;
    for (int i = 0; i < k; i++) {
        mp[s[i]]++; freq[s[i]] = 1;
    }
    for (int i = k; i < n; i++) {
        mp[s[i - k]]--;
        if (mp[s[i-k]] == 0) mp.erase(s[i-k]);
        mp[s[i]]++;
        for (int j = 0; j < 26; j++) {
            if (mp.find((char)('a' + j)) != mp.end()) {
                freq[char('a' +  j)]++;
            }
        }
    }  
    int need = n - k + 1;
    for (auto &x : freq) {
        if (x.second == need) return true;
    } 
    return false;
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
    string s; cin >> s;
    int l = 1, r = s.length();
    int ans = 0;
    while (l <= r) {
        int mid = (l + r)/2;
        if (itcan(mid, s)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << "\n";
}


