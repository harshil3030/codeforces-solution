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
	string s;
	cin >> s;
	int cnt0 = 0;
	int cnt1 = 0;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '1') cnt1++;
		if (s[i] == '0') cnt0++;
	}vector<int> ansvec;
	for (int i = 0; i < cnt0; i++) {
		if (s[i] == '1') {
			ans = 1;	
			ansvec.pb(i + 1); 
			// cout << "here\n";
		}
	}
	// cout << s.length() - cnt1 << endl;
	
	for (int i = s.length() - 1; i > (s.length() - cnt1 - 1); i--) {
		if (s[i] == '0') {
			ans = 1;
			ansvec.pb(i + 1);   
			// cout << "here\n";
		}
	}
	// }cout << "here" << " "; return;
	sort(ansvec.begin(), ansvec.end());
	cout << ans << endl;
	if (ans == 1) {
		cout << ansvec.size() << " ";
		for (int i = 0; i < ansvec.size(); i++) cout << ansvec[i] << " ";
		cout << endl;
	}
}

 