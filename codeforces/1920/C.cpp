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
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    vector<int> digs;
    auto get = [&](int x, vector<int> &digs) {
        for (int i = 1; i < x; i++) {
            if ((x % i) == 0) digs.push_back(i);
        }
    };    
    get(n,digs);
    vector<int> primes;
    sieveOfEratosthenes(n, primes);

    int ans = 1;
       for (int j = 0; j < digs.size(); j++) {
         for (int i = 0; i < primes.size(); i++) {
                int flg = 0;
                for (int k = 0; k < n-digs[j]; k++) {
                    if ((v[k] % primes[i]) != (v[k + digs[j]] % primes[i])) {
                        flg = 1;
                        break;
                    }
                }

                if (!flg) {
                    ans++;
                    break;
                } 
            }
        }
        
        cout << ans << "\n";
}
