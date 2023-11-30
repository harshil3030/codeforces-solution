#include<bits/stdc++.h>
using namespace std;
long long t = 0;
#define ll    long long int
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1e9+7;
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
void solve () {
    int n; cin >> n;
    int v[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    if (n == 1) {
        cout << "YES\n";
        cout << 1 << "\n";
        return;
    }
    vector<int> getmin(n); int k = 0;

    for (int i = 0; i < n; i++) {
        int mx = -1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                mx = max(mx, v[i][j]);
            }
        }

        for (int j = 0; j < n; j++) {
            if (i != j) {
                mx = mx & v[i][j]; 
            }
        }
        getmin[k] = mx;
        k++;
    }


    // vector<int> sm;
    // for (int i = 0; i < n; i++) {
    //     int mn = INT_MAX;
        
    //     for (int j = 0; j < n; j++) {
    //         if (i != j) mn = min(mn, v[j][i]);
    //     } 

    //     sm.push_back(mn);
    //     int flg = 0;
    //     for (int j = 0; j < (int)i; j++) {
    //         if ((int)(getmin[j] | 0) != v[i][j]) {
    //             flg = 1;
    //             break;
    //         }
    //     }
    //     if (flg == 1 || i == 0) {
    //         getmin[k] = mn;
    //     }else getmin[k] = 0;
    //     k++;
    // }


    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i != j) {
    //             if (v[i][j] != (int)(getmin[i] | getmin[j])) {
    //                 int prev = getmin[i];
    //                 if (getmin[i] == 0) getmin[i] = sm[i];
    //                 if (v[i][j] != (int)(getmin[i] | getmin[j])) {
    //                     getmin[j] = sm[j];
    //                 }
    //                 if (v[i][j] != (int)(getmin[i] | getmin[j])) {
    //                     getmin[i] = prev;
    //                 }
    //             }
    //         }
    //     }
    // }
    // for (auto &x : getmin) cout << x << " "; cout << "\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) { 
                    if ((int)v[i][j] != (int)(getmin[i] | getmin[j])) {
                    cout << "NO\n";
                    return;
                    }
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << getmin[i] << " "; cout << "\n";
}
