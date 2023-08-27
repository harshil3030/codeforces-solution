#include<bits/stdc++.h>
using namespace std;
//defines
#define ll  long long
#define vll   vector<ll>
#define vvll  vector<vector<ll>>
#define pb    push_back
#define popb  pop_back
#define fi     first
#define se     second
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
	ll n, k, q;
	cin >> n >> k >> q;
	vector <ll> v(n);
	for (auto &x : v) cin >> x;
	// int i = 0;
	long long sm = 1;
	queue <ll> que;
	for (int i = 0; i < k; i++) {
		if (v[i] > q) {
		 sm--; while (!que.empty()) que.pop(); 
		}else que.push(v[i]);
	}
	if (sm < 1) sm = 0;
	long long mx = 0;
	for (int i = k; i < n; i++) {
		if (v[i] <= q) {
			if (!que.empty() && que.size() >= k)
			que.pop();
			que.push(v[i]);
			if (que.size() >= k)
			sm++;
		}else {
			mx += ((sm * (sm + 1))/2);
			sm = 0;
			while (!que.empty()) que.pop();
		}
	}
	if (sm > 0) mx += ((sm * (sm + 1))/2);
	cout << mx << "\n";
}

 