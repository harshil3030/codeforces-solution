#include<bits/stdc++.h>
using namespace std;
//defines
#define ll    long long
#define pb    push_back
#define popb  pop_back
#define ff    first
#define ss    second
#define pll   pair<ll,ll>
#define nl    "\n"
#define gcd(a, b) ((b) == 0 ? (a) : gcd((b), (a) % (b)))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;
ll tc = 0;

//functions
void solve();
ll bin_expo(ll a, ll b, ll MOD = mod) {
    ll ans = 1;
    while (b) {
        if (b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    } return ans;
}

ll inverse(ll a) {
    return bin_expo(a, mod - 2, mod);
}

void csort(vector <ll>);
void csort(vector <int>);
void csort(vector <ll> &v){
    ll i = 0;
    while(i < v.size()){
        ll cur = v[i] - 1;
        if(cur < v.size() && v[i] != v[cur]){
            swap(v[i],v[cur]);
        }else
            i++;
    }
}
void csort(vector <int> &v){
    ll i = 0;
    while(i < v.size()){
        ll cur = v[i] - 1;
        if(cur < v.size() && v[i] != v[cur]){
            swap(v[i],v[cur]);
        }else
            i++;
    }
}

vector<int> sieve_of_eratosthenes(int limit) {
    std::vector<bool> primes(limit + 1, true);
    primes[0] = primes[1] = false;  // 0 and 1 are not prime
    for (int num = 2; num * num <= limit; ++num) {
        if (primes[num]) {
            for (int multiple = num * num; multiple <= limit; multiple += num) {
                primes[multiple] = false;
            }
        }
    }
    std::vector<int> prime_numbers;
    for (int num = 2; num <= limit; ++num) {
        if (primes[num]) {
            prime_numbers.push_back(num);
        }
    }
    return prime_numbers;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll tt; cin >> tt;
    while(tt--)
        solve();
    return 0;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for (auto &x : v) cin >> x;
    int x = -1; int y = INT_MAX;
    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            int sm = v[i] + v[i+1];
            if (sm % 2) sm++;
            x = max(x,sm/2);
//            y = min(y,sm/2);
        }
    }
    bool haveit = false;
    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            haveit = true;
            break;
        }
    }
    if (!haveit) {
        cout << 0 << "\n";
        return;
    }
//    vector<int> temp = v;
//    for (int i = 0; i < n; i++) {
//        temp[i] = abs(temp[i] - y);
//    }
    int flg1 = 1;
//    int flg2 = 1;
    for (int i = 0; i < n; i++) {
        v[i] = abs(v[i] - x);
    }
    for (int i = 0; i < n-1; i++) {
        if (v[i] > v[i+1]) {
            flg1 = 0;
            break;
        }
    }

//    for (int i = 0; i < n-1; i++) {
//        if (temp[i] > temp[i + 1]) {
//            flg2 = 0;
//            break;
//        }
//    }
    if (!flg1) {
        cout << -1 << "\n";
        return;
    }
    if (x == -1) {
        cout << 0 << "\n";
        return;
    }
//    if (flg1)
        cout << x << "\n";
//    else cout << y << "\n";
}