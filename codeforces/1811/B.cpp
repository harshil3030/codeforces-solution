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
ll find (ll x1, ll y1, ll n);
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
	ll n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	ll belt1 = find (x1, y1, n);
	ll belt2 = find (x2, y2, n);
	cout << abs (belt1 - belt2) << '\n';
 }

ll find (ll x1, ll y1, ll n) {
	if (x1 > n/2 && y1 > n/2) {
		return max(abs(x1 - (n/2 + 1)) , abs(y1 - (n/2 + 1)));
	}else if (x1 > n/2) {
		return max(abs(x1 - (n/2 + 1)) , abs(y1 - (n/2)));
	}else if (y1 > n/2) {
		return max(abs(x1 - (n/2)) , abs(y1 - (n/2 + 1)));
	}else {
		return max(abs(x1 - (n/2)) , abs(y1 - (n/2)));		
	}
}

 