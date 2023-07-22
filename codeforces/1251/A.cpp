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
	string s;
	cin >> s;
	if (s.length() == 1){
		cout << s << "\n";
		return;
	}
	set<char> ans;
	unordered_map<char,int> mp;
	for (int i = 0; i < s.length(); i++) mp[s[i]]++;
	for (int i = 0; i < s.length() - 1; i++){
		if (s[i] == s[i + 1]){
			  i++;
		}else{
			ans.insert(s[i]); 
		}
	}
	for (auto x : mp){
		// cout << x.fi << " " << x. se << endl;
		if (x.second % 2) ans.insert(x.first);
	}
	 if (s[s.length() - 1] != s[s.length() - 2]){
		ans.insert(s[s.length() - 1]);
	}
	if (ans.size() == 0){
		cout << " " << "\n";
	}else {
		for (auto x : ans) cout << x;
		cout << "\n";
	}
}

 