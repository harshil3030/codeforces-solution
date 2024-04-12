#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

void sieveOfEratosthenes(int n, vector<int>& primes) {
    vector<bool> isPrime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p)
                isPrime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (isPrime[p])
            primes.push_back(p);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n,m,k; cin >> n >> m >> k;
    int path = n-1 + m-1;
    if (k < path) {
        cout << "NO\n";
        return;
    } else {
        k -= path;
        if (k % 2) {
            cout << "NO\n";
            return;
        } else {
            int type = 0;
            char forRow[n][m-1];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m-1; j++) {
                    if ((i == 0 && j == 0) || (i == 1 && j == 0)) {
                        forRow[i][j] = 'R';
                        type = 1;
                    } else {
                        if (type) {
                            forRow[i][j] = 'B';
                            type ^= 1;
                        } else {
                            forRow[i][j] = 'R';
                            type ^= 1;
                        }
                    }
                } 
            }
            type = 1;
            char forCol[n-1][m];
            for (int j = 0; j < m; j++) {
                if (type) {
                    forCol[0][j] = 'B';
                    type ^= 1;
                } else {
                    forCol[0][j] = 'R';
                    type ^= 1;
                }
            }
            forCol[0][1] = 'B';
            for (int i = 0; i < n-1; i++) {
                if (type) {
                    forCol[i][m-1] = 'B';
                    type ^= 1;
                } else {
                    forCol[i][m-1] = 'R';
                    type ^= 1;
                }
            }
            type^=1;
            char setLast = type == 1 ? 'B' : 'R';
            forRow[n-2][m-2] = setLast;
            forRow[n-1][m-2] = setLast;
            setLast = setLast == 'B' ? 'R' : 'B';
            forCol[n-2][m-2] = setLast;
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m-1; j++) {
                    if (forRow[i][j] == 'B' || forRow[i][j] == 'R') {
                        cout << forRow[i][j] << " ";
                    } else {
                        cout << "B" << " ";
                    }
                } cout << "\n";
            }
            
            for (int i = 0; i < n-1; i++) {
                for (int j = 0; j < m; j++) {
                    if (forCol[i][j] == 'B' || forCol[i][j] == 'R') {
                        cout << forCol[i][j] << " ";
                    } else {
                        cout << 'B' << " ";
                    }
                } cout << "\n";
            }
            
        }
    }
}
