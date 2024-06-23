//#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//#define inf (1LL<<60)
//#define prDouble(x) cout << fixed << setprecision(10) << x
//using namespace __gnu_pbds;
//using namespace std;
//#define int long long
//typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
//
//void solve() {
//    int n;
//    cin >> n;
//    vector<int> v(n);
//    for(auto &x : v) cin >> x;
//
//    set<pair<int, int>> st;
//    int tot = 0;
//    for(int i = 0; i < n; i++) {
//        set<int> fct;
//        int tmp = v[i];
//        for(int j = 1; j*j <= tmp; j++) {
//            if (tmp % j == 0) {
//                fct.insert(j);
//                fct.insert(tmp / j);
//            }
//        }
//
//        for(auto &x : fct) {
//            if (x == (i+1)) continue;
//            int curr = x-1;
//            if (st.count({curr, i}) || st.count({i, curr})) {
//               continue;
//            };
//            if (curr < i) st.insert({curr, i});
//            else st.insert({i, curr});
//
//            if (((v[i] * v[curr]) % ((i+1)*(curr+1)) == 0)) {
//                tot++;
//            }
//        }
//    }
//    cout << tot << "\n";
//}
//
//signed main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0); cout.tie(0);
//    int tt = 1; cin >> tt; while (tt--)
//        solve();
//    return 0;
//}

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

    long long bin_expo(long long base, long long exponent, long long mod = 1e9+7) {
        long long result = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base);
            }

            base = (base * base);
            exponent /= 2;
        }

        return result;
    }

    long long inverse(long long a, long long mod) {
        return bin_expo(a, mod - 2, mod);
    }

    long long fastNPr(int n, int r) {
        long long result = 1;
        for (int i = n; i > n - r; --i) {
            result = (result * i) % mod;
        }
        return result;
    }

    long long NCr(int n, int r) {
        if (r > n) return 0;
        long long numerator = 1, denominator = 1;

        for (int i = 1; i <= r; ++i) {
            numerator = (numerator * (n - i + 1)) % mod;
            denominator = (denominator * i) % mod;
        }

        return (numerator * inverse(denominator, mod)) % mod;
    }

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
        int count = 0;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                ++count;

                if (count > 1 || (n / i) % i == 0) {
                    return 0;
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
class SGtree {
public:
    vector<int> seg;
    SGtree(int n) {
        seg.resize(4*n);
    }
    void build(int ind, int low, int high, vector<int> arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (high + low) >> 1;
        build (2*ind + 1, low, mid, arr);
        build (2*ind + 2, mid + 1, high, arr);
        seg[ind] = min(seg[2*ind + 1], seg[2*ind+2]);
    }

    int query(int ind, int low, int high, int l, int r) {
        if (l > high || r < low) {
            return INT_MAX;
        }
        if (l <= low &&  high <= r ) {
            return seg[ind];
        }

        int mid = (high + low) >> 1;
        int ff = query(2*ind + 1, low, mid, l, r);
        int ss = query(2*ind + 2, mid + 1, high, l, r);
        return min(ff, ss);
    }

    void update(int ind, int low, int high, int val, int i) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) update(2*ind + 1, low, mid, val, i);
        else update(2*ind + 2,mid + 1, high, val, i);
        seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
    }
};
long long getresult(long long a, long long b, char op) {
    if (op=='+')return a + b;
    else return a * b;
}

int getval(string s, int pos, int cnt, vector<vector<int>> &dp) {
    if (cnt == 0) return stol(s.substr(pos));
    if (dp[pos][cnt]!= -1) return dp[pos][cnt];
    int res = 1e18;
    for (int i = pos; i < s.size() - cnt; i++) {
        int a = stol(s.substr(pos, i - pos + 1));
        int b = getval(s,i+1,cnt-1, dp);
        res = min(res, getresult(a, b, '+'));
        res = min(res, getresult(a, b, '*'));
    }
    return dp[pos][cnt] = res;
}


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(25, vector<int> (25, -1));
    cout << getval(s, 0, n - 2, dp) << "\n";

    for(int i = 0; i < 10000; i++) {
        //get correct!!!
    }
}


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}
