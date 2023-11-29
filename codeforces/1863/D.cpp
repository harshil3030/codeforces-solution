#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi = 3.14159265358979323846264338327950288419716939937510582097494459230;
#define int ll
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
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;  while (tt--)
        solve();
    return 0;
}
//-----------------------------------------------------------------------------------------------------------------------

//sol.
void solve() {
    int n,m; cin >> n >> m;
    vector<string> v(n); 
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<string> copy = v;
    for (int i = 0; i < m; i++) {
        int w = 0,b = 0;

        for (int j = 0; j < n; j++) {
            if (v[j][i] == 'W') w++;
            else if (v[j][i] == 'B') b++;
        }

        for (int j = 0; j < n; j++) {
            if (v[j][i] == 'U') {
                v[j][i] = 'W';
                w++;
            } else if (v[j][i] == 'D') {
                v[j][i] = 'B';
                b++;
            } else if (v[j][i] == 'L') {
                if (w > b) {
                    v[j][i] = 'B';
                    v[j][i+1] = 'W';
                    b++;
                }else {
                    v[j][i] = 'W';
                    v[j][i+1] = 'B';
                    w++;
                }
            } 
        }
    } 

    for (int i = 0; i < n; i++) {
        int w = 0, b = 0;
        
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'W') w++;
            else if (v[i][j] == 'B') b++;
        }

        if (w > b) {
            for (int j = 0; j < m; j++) {
                if (copy[i][j] == 'U') {
                    v[i][j] = 'B';
                    v[i+1][j] = 'W';
                    w--; b++;
                }
                if (w == b) break; 
            }
        } else if (b > w) {
            for (int j = 0; j < m; j++) {
                if (copy[i][j] == 'D') {
                    v[i][j] = 'W';
                    v[i-1][j] = 'B';
                    b--; w++;
                }
                if (w == b) break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int w = 0, b = 0;
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 'W') w++;
            else if (v[i][j] == 'B') b++;
        }
        if (w != b) {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        int w = 0, b = 0;
        for (int j = 0; j < n; j++) {
            if (v[j][i] == 'W') w++;
            else if (v[j][i] == 'B') b++;
        }
        if (w != b) {
            cout << -1 << "\n";
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j];
        } cout << "\n";
    }
}
