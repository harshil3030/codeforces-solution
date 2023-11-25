#include<bits/stdc++.h>
using namespace std;
int t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
#define int ll
#define ff first
#define ss second
const int mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}

//sol.
void solve() {
    int n; cin >> n;
    vector<string> v(n); for (auto &x : v) cin >> x;
    map<pair<int,int>,int> mp;
    for (int i = 0; i < n; i++) {
        int len = v[i].length();
        int cnt = 0;
        for (auto &x : v[i]) cnt += x - '0';
        mp[{cnt, len}]++;
    }
    int pairs = 0;
    for (int i = 0; i < n; i++) {
        int len = v[i].length();
        if (len % 2) {
            if (len == 1) {
                int cnt = v[i][0] - '0';
                pairs += mp[{cnt, 1}];
            }else if (len == 3) {
                int cnt = 0;
                for (int j = 0; j < 3; j++) cnt += v[i][j] - '0';
                pairs += mp[{cnt, 3}];
                int begin = (v[i][0] - '0');
                int last = (v[i][2] - '0');
                pairs += mp[{cnt - 2*begin,1}] + mp[{cnt- 2*last,1}];
            } else {
                int cnt = 0;
                for (int j = 0; j < 5; j++) cnt += v[i][j] - '0';
                pairs += mp[{cnt, 5}];
                int firsthalf = 0;
                for (int j = 0; j < 2; j++) firsthalf += v[i][j] - '0';
                int secondhalf = 0;
                for (int j = 3; j < 5; j++) secondhalf += v[i][j] - '0';
                pairs += mp[{cnt-2*firsthalf, 1}] + mp[{cnt-2*secondhalf, 1}];
                int firsthalf2 = v[i][0] - '0';
                int secondhalf2 = v[i][4] - '0';
                pairs += mp[{cnt - 2*firsthalf2, 3}] + mp[{cnt - 2*secondhalf2, 3}];
            }
        }else {
            if (len == 2) {
                int cnt = 0;
                for (int j = 0; j < 2; j++) cnt += v[i][j] - '0';
                pairs += mp[{cnt, 2}];
            }else if (len == 4) {
                int cnt = 0;
                for (int j = 0; j < 4; j++) cnt += v[i][j] - '0';
                pairs += mp[{cnt, 4}];
                int firsthalf = v[i][0] - '0';
                int secondhalf = v[i][3] - '0';
                pairs += mp[{cnt - 2*firsthalf, 2}] + mp[{cnt - 2*secondhalf, 2}]; 
            }
        }
    }
    cout << pairs << "\n";
}

    




