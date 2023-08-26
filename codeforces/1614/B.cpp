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
	long long n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	vector<int> original(v);
	sort (v.rbegin(), v.rend());
	int cnt = 1;
	vector<pair<long long int,int>> vp(n);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0){
		vp[i] =make_pair(v[i], cnt);
		}else{
		vp[i] = make_pair(v[i], -(cnt));
		cnt++;
		}
	}
	multimap <int, pair<long long int,int>> mp;
	for (int i = 0; i < n; i++) {
		mp.insert(make_pair(v[i], vp[i]));
	}
	unsigned long long int sm = 0;
	for (int i = 0; i < n; i++) {
		sm += 2 * abs(vp[i].second) * vp[i].first;
	}
	cout << sm << "\n";
	cout << 0 << " ";
	for (int i = 0; i < n; i++) {
		auto it = mp.find(original[i]);
		cout << (it -> second).second << " ";
		mp.erase(it);
	} cout << "\n";
}

