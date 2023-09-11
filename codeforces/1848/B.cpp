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

	ll tt; cin >> tt;
	while(tt--)
	solve();
return 0;
}

void solve(){
	//write down your solution from here	
	ll n, k;
	cin >> n >> k;
	vector<vector<ll>> v(k + 1);
	vector<pair<ll,ll>> colorin;
	
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v[x].push_back(i);
	}
	/*
	for (ll j = 1; j <= k; j++) {
		ll mx = INT_MIN;
		if (v[j].size() > 0){
		for (int i = 1; i < v[j].size(); i++){
				mx = max(mx, v[j][i] - v[j][i - 1]);
			}
			mx = max(mx, v[j][0]);
			mx = max(mx, n - 1 - v[j][v[j].size() - 1]);
			colorin.push_back(make_pair(mx, j));
		}
	}
	ll color = 0;
	ll mn = INT_MAX;
	for (ll i = 0; i < colorin.size(); i++) {
		// cout << "here1" << " ";
		if (mn > colorin[i].first) {
			// cout << "here2" << " ";
			color = colorin[i].second;
			mn = colorin[i].first;
		}
	}
	
	if (mn == 0) {
			cout << 0 << "\n"; return;
	}
	vector<ll> diff;
	for (ll i = 1; i < v[color].size(); i++) {
		diff.push_back(v[color][i] - v[color][i - 1] - 1);
	}

	// if (diff.size() != 0){ 
	// diff.push_back(n - 1 - v[color][v[color].size() - 1]);
	// diff.push_back(v[color][0]);
	// }

	// cout << "color :" << color << "\n"; 	
	// cout << "hellow" << '\n';
	// return;
	if (v[color].size() == 1) {
		diff.push_back(v[color][0]);
		diff.push_back(n - 1 -  v[color][0]);
	}else{
		diff.push_back(v[color][0]);
		diff.push_back(n - 1 - v[color][v[color].size() - 1]);
	}
	sort(diff.rbegin(), diff.rend());
	cout << diff[0] << " ";
	if (diff.size() == 1) {
		cout << diff[0]/2 << "\n";
		return;
	}
	cout << diff[1] << " ";
	cout << max(diff[0]/2, diff[1]) << "\n";
	*/
		if (n == 0 || n == 1 || n == 2 || k == 0 || k == 1) {
			cout << 0 << "\n";
			return;
		}
	 vector<vector<ll>> diff(k + 1);
	 for (int i = 1; i <= k ; i++) {
	 	if (!v[i].empty())
	 	diff[i].push_back(v[i][0]);
	 	for (int j = 1; j < v[i].size(); j++) {
	 			diff[i].push_back(v[i][j] - v[i][j - 1] - 1);
	 		}
	 	if (!v[i].empty())
	 	diff[i].push_back(n - 1 - v[i][v[i].size() - 1]);	
	 		}


	 	ll mn = INT_MAX;
	 	for (int i = 1; i <= k; i++) {
	 		sort(diff[i].rbegin(), diff[i].rend());
	 		ll mx = INT_MIN;
	 		if (!diff[i].empty())
	 		mx = max (mx, max(diff[i][0]/2, diff[i][1]));
	 		if (!diff[i].empty())
	 		mn = min(mn, mx);
	 	}

	 	cout << mn << "\n";
	}

 