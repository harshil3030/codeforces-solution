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

//functions
void solve();
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

void solve(){
    //write down your solution from here
    string s, t; cin >> s >> t;
    bool find = false;
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == t[i] && s[i] == '0' && s[i + 1] == t[i + 1] && s[i + 1] == '1') find = true;
    }
    if (find) cout << "YES\n";
    else cout << "NO\n";
}

