#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;
// numberTheory nt;
class numberTheory {    
    public:
    int mod = 1e9 + 7;
    std::vector<bool> sieve(int n) {
        std::vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
    
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    
    std::vector<int> gen(vector<bool> prime) {
        vector<int> v;
        for(int i = 2; i < prime.size(); i++) {
            if (prime[i] == true) {
                v.push_back(i);
            }
        }
        return v;
    }
    
    std::vector<int> primeFactors(int n) {
        std::vector<int> factors;
    
        while (n % 2 == 0) {
            factors.push_back(2);
            n /= 2;
        }
    
        for (int i = 3; i <= std::sqrt(n); i += 2) {
            while (n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
    
        if (n > 2) {
            factors.push_back(n);
        }
    
        return factors;
    }
    
    long long bin_expo(long long base, long long exponent, long long mod) {
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
    
    long long inverse(long long a, long long mod) {
    return bin_expo(a, mod - 2, mod);    
    }

// Fast nPr (Permutation)
    long long fastNPr(int n, int r) {
        long long result = 1;
        for (int i = n; i > n - r; --i) {
            result = (result * i) % mod;
        }
        return result;
    }
    
// Fast nCr (Combination)
    long long NCr(int n, int r) {
        if (r > n) return 0;
        long long numerator = 1, denominator = 1;
    
        for (int i = 1; i <= r; ++i) {
            numerator = (numerator * (n - i + 1)) % mod;
            denominator = (denominator * i) % mod;
        }
    
        return (numerator * inverse(denominator, mod)) % mod;
    }
    
    // Euler's Totient Function (Phi)
    int phi(int n) {
        int result = n;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n /= i;
                }
                result -= result / i;
            }
        }
        if (n > 1) {
            result -= result / n;
        }
        return result;
    }
    
    
    // Check if a number is prime
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    
    long long crt(const std::vector<long long>& a, const std::vector<long long>& m) {
        // Assumes all moduli in m are pairwise coprime
        int n = a.size();
        long long M = 1, result = 0;
    
        for (int i = 0; i < n; ++i) {
            M *= m[i];
        }
    
        for (int i = 0; i < n; ++i) {
            long long Mi = M / m[i];
            result = (result + a[i] * Mi % M * inverse(Mi, m[i])) % M;
        }
    
        return (result + M) % M;
    }
    
    int mobiusFunction(int n) {
        int result = 1;
        int count = 0;
    
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                ++count;
    
                if (count > 1 || (n / i) % i == 0) {
                    return 0;  // n is not square-free
                }
    
                n /= i;
                --i;
            }
        }
    
        if (n > 1) {
            ++count;
        }
    
        return (count % 2 == 0) ? 1 : -1;
    }
    
    int binomialCoefficientModP(int n, int r, int p) {
        if (r == 0) return 1;
    
        int ni = n % p;
        int ri = r % p;
    
        return (binomialCoefficientModP(n / p, r / p, p) *
                binomialCoefficientModP(ni, ri, p)) % p;
    }
    
    int lucasTheorem(int n, int r, int p) {
        if (r == 0) return 1;
    
        int ni = n % p;
        int ri = r % p;
    
        return (lucasTheorem(n / p, r / p, p) * binomialCoefficientModP(ni, ri, p)) % p;
    }

};
numberTheory nt;
void solve() {
    int arr[] = {4,8,15,16,23,42};
    
    // for (int i = 0; i < 6; i++) {
        // for (int j = i+1; j < 6; j++) {
            // cout << arr[i] * arr[j] << " ";
        // } cout << "\n";
    // }
    
    
    map<int, pair<int, int>> mp;
    for (int i = 0; i < 5; i++) {
        for (int j = i+1; j < 6; j++) {
            // cout << arr[i] * arr[j] << " ";
            mp[arr[i] * arr[j]] = {arr[i], arr[j]};
        } 
    }
    
    vector<int> ans(6); int k = 0;
    
    cout << "? " << 1 << " " << 2 << "\n";
    cout.flush();
    int num; cin >> num;
    vector<int> vis(43, 0);
    vis[mp[num].first] = 1, vis[mp[num].second] = 1;
    
    cout << "? " << 1 << " " << 3 << "\n";
    cout.flush();
    cin >> num;
    if (vis[mp[num].first] == 1) {
        ans[0] = mp[num].first;
        ans[2] = mp[num].second;
        vis[mp[num].second] = 1; 
    }  else {
        ans[0] = mp[num].second;
        ans[2] = mp[num].first;
        vis[mp[num].first] = 1;
    }
    // cout << "\n";
   // cout << ans[0] << " " << ans[2] << "\n";
   // cout << mp[num].first << " " << mp[num].second << "\n";
    for (int i = 1; i <= 42; i++) {
        if (vis[i] && (i != mp[num].first) && i != mp[num].second) {
            ans[1] = i;
            break;
        }
    }
    
    cout << "? " << 4 << " " << 5 << "\n";
    cout.flush();
    cin >> num;
    for (auto &x : vis) x = 0;
    // vector<int> vis(43, 0);
    vis[mp[num].first] = 1, vis[mp[num].second] = 1;
    
    cout << "? " << 4 << " " << 6 << "\n";
    cout.flush();
    cin >> num;
    if (vis[mp[num].first] == 1) {
        ans[3] = mp[num].first;
        ans[5] = mp[num].second;
        vis[mp[num].second] = 1; 
    }  else {
        ans[3] = mp[num].second;
        ans[5] = mp[num].first;
        vis[mp[num].first] = 1;
    }
    
    for (int i = 1; i <= 42; i++) {
        if (vis[i] && i != mp[num].first && i != mp[num].second) {
            ans[4] = i;
            break;
        }
    }
    
    cout.flush();
    cout << "! ";
    for (int i = 0; i < 6; i++) {
        cout << ans[i] << " ";
    } cout << "\n";
    cout.flush();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}
