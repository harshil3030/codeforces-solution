#include<bits/stdc++.h>
using namespace std;
//defines
#define ll    long long
#define vll   vector<ll>
#define vvll  vector<vector<ll>>
#define pb    push_back
#define popb  pop_back
#define ff    first
#define ss    second
#define pll   pair<ll,ll>
#define nl    "\n"
#define cy    cout<<"YES"<<nl;
#define cn    cout<<"NO"<<nl;
#define gcd(a, b) __gcd((a), (b))
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

	// ll tt; cin >> tt;
	// while(tt--)
	solve();
return 0;
}

void solve(){
	//write down your solution from here	
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (auto &x : v) cin >> x;
	vector<ll> months (72);
	for (int i = 0; i < 72; i++) {
		months[i] = 31;
	}
	months[1] = 28;
	months[13] = 28;
	months[25] = 29;
	months[37] = 28;
	months[49] = 28;
	months[61] = 28;

	for (int i = 3; i < 72; i += 12) {
		months[i] = 30;
	}
	for (int i = 5; i < 72; i += 12) {
		months[i] = 30;
	}
	for (int i = 8; i < 72; i += 12) {
		months[i] = 30;
	}
	for (int i = 10; i < 72; i += 12) {
		months[i] = 30;
	}

	vector<ll> comp;
	for (int i = 0; i < n; i++) {
		comp.push_back(months[i]);
	}
	if (comp == v) {
		cy; return;
	}
	for (int i = n; i < 72; i++) {
		comp.push_back(months[i]);
		comp.erase(comp.begin());
		if (comp == v) {
			cy; return;
		}
		// for (auto x : comp) cout << x << " ";
		// 	cout << '\n';
	}
	cn;
}

 