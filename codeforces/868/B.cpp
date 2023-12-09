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
    int h,m,s,t1,t2; cin >> h >> m >> s >> t1 >> t2;
    vector<int> v(13*59*59 + 1, 0);
    h %= 12;
    int hour = h * 3600 + m * 60 + s;
    int temp1 = m/5;
    int temp2 = s/5;
    int minute = temp1 * 3600 + m * 60 + s; 
    int second = temp2 * 3600 + s * 60 + s;
    v[hour] = -1;
    v[minute] = -1;
    v[second] = -1;
    t1 %= 12;
    t2 %= 12;
    int st = t1 * 3600;
    int en = t2 * 3600;
    int gotend = 0; int gotend2 = 0;
    int flg = 0, flg2 = 0;
    for (int i = st + 1; i < 13*59*59; i++) {
        if (v[i] == -1) {
            flg = 1;
        }
        if (i == en - 1) {
            gotend = 1;
            break;
        }
    }
    if(!gotend)
    for (int i = 0; i < en; i++) {
        if (v[i] == -1) {
            flg = 1;
            break;
        }
    }
 for (int i = en + 1; i < 13*59*59; i++) {
        if (v[i] == -1) {
            flg2 = 1;
        }
        if (i == st - 1) {
            gotend2 = 1;
            break;
        }
    }
    if(!gotend2)
    for (int i = 0; i < st; i++) {
        if (v[i] == -1) {
            flg2 = 1;
            break;
        }
    }

    if (!flg || !flg2) {
        cout << "YES\n";
    } else cout << "NO\n";
}


