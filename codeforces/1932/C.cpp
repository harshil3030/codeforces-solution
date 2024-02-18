#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
void solve();

void pf(int n, map<int, int> &mp) {
    // std::vector<int> factors;

    while (n % 2 == 0) {
       mp[2]++;
        n /= 2;
    }

    for (int i = 3; i <= std::sqrt(n); i += 2) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }

    if (n > 2) {
        mp[n]++;
    }
}

long long power(long long base, long long exponent, long long mod) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exponent /= 2;
    }

    return result;
}




signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
    int n,m; cin >> n >> m;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    string s; cin >> s;
    
    vector<int> na;
    int i = 0;
    int j = n-1;
    
    int si = 0;
    while (i <= j) {
        if (s[si++] == 'L') {
            na.push_back(v[i++]);
        } else {
            na.push_back(v[j--]);
        }
    }
    
    int premul[n+1];
    premul[n] = 1;
    
    for (int i = n-1; i >= 0; i--) {
        premul[i] = ((premul[i+1] % m) * (na[i] % m)) % m;
    }
    
    for (int i = 0; i < n; i++) {
        cout << premul[i] << " ";
    } cout << "\n";
    
    
    
    // int i = 0; int j = n-1;
    // map<int, int> mp;
//     
    // map<int, int> fm;
    // pf(m, fm);
//     
    // for (int i = 0; i < n; i++) {
        // pf(v[i],mp);
    // } 
    
    
    
//     
    // auto findfor = [&](map<int, int> fm, map<int, int> mp) -> bool {
        // for (auto &x : fm) {
            // if (mp[x.first] < x.second) {
                // // cout << "here\n";
                // return false;
            // }
        // }
        // return true;
    // };
//     
//     
    // auto findmod = [&](map<int, int> mp, int m) -> int {
        // int ans = 1;
//         
        // for (auto &x : mp) {
            // // if (x.first > m) break;
            // ans = (ans * power(x.first, x.second, m)) % m;
            // // ans %= m;
        // }
        // return ans;
    // };
//     
    // auto removefact = [&](int n, map<int, int> &mp) {
//         
            // while (n % 2 == 0) {
               // mp[2]--;
                // n /= 2;
            // }
//         
            // for (int i = 3; i <= std::sqrt(n); i += 2) {
                // while (n % i == 0) {
                    // mp[i]--;
                    // n /= i;
                // }
            // }
//         
            // if (n > 2) {
                // mp[n]--;
            // }
    // };
//     
//     
    // int si = 0;
    // while (i <= j) {
        // if(findfor(fm, mp)) {
            // cout << 0 << " ";
        // } else {
            // cout << findmod(mp,m) << " ";
        // }       
//         
        // if (s[si] == 'L') {
            // removefact(v[i],mp);
            // i++;
            // si++;
        // } else {
            // removefact(v[j], mp);
            // j--;
            // si++;
        // }
    // }
    // cout << "\n";
//        
}
