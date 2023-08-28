#include<bits/stdc++.h>
using namespace std;
//defines
#define ll  long long
#define vll   vector<ll>
#define vvll  vector<vector<ll>>
#define pb    push_back
#define popb  pop_back
#define ff     first
#define ss     second
#define nl  "\n"
#define cy cout<<"YES"<<nl;
#define cn cout<<"NO"<<nl;
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

	ll tt;
	cin >> tt;
        while(tt--)
	solve();
return 0;
}

void solve(){
	//write down your solution from here	
	ll n;
	cin >> n;
	// vector<vector<ll>> v(n, vector <ll> (2));
	ll mx = 2*n;
	ll mn = 1;
	vector<vector<int>> v(2, vector<int> (n));
	v[0][0] = mx--;
	v[1][0] = mn++;
	v[1][n - 1] = mx--;
	ll mid = n + 1;
	for (int i = 1; i < n - 1; i++) {
		if (i % 2) {
			v[0][i] = mn++;
			v[1][i] = mid++;  
		}else {
			v[0][i] = mid++;
			v[1][i] = mn++;
		}
	}
	v[0][n - 1] = mn++;
	for (auto x : v) {
		for (auto y : x) {
			cout << y << " ";
		}cout << '\n';
	}
}

 