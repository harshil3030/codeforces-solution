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
	vector <long long> v(n);
	vector <long long> temp(n, 1);
	ll temp2 = INT_MIN;
	ll mx = INT_MIN;
	ll mx2 = v[0];
	for (int i = 0; i < n; i++) cin >> v[i];
	int flg = 0;
	ll in;
	for (int i = 1; i < n; i++){
		 if (temp[i - 1] != 0)
		 	mx2 = max(mx2, v[i - 1]);
		 if (v[i] < mx2 && (flg == 0)){
			flg = 1;
			in = i;
		}
		else if (flg == 1){
			if (temp[i - 1] != 0){
				mx = max(mx, v[i - 1]);
			}
			if (v[i] < mx || v[i] > v[0]) temp[i] = 0;
		}

		if (flg == 1 && v[in] > v[0]){
			temp[in] = 0;
			flg = 0;
		}
	}
	for (auto x : temp) cout << x;
		cout << endl;
}

 