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

	// ll tt;
	// cin >> tt;
   //      while(tt--)
	solve();
return 0;
}

void solve(){
	//write down your solution from here	
	long long n, m;
	cin >> n >> m;
	vector<string> vs (n);
	for (auto &X : vs) cin >> X;

	unordered_map <string, int> mp;
	long long len = 0;
	string left = "";
	string mid = "";
	string right = "";
	string rev = ""; int flg = 0;
	for (auto x : vs) mp[x]++;
	for (int i = 0; i < n; i++) {
		string t = vs[i];
		reverse (t.begin(), t.end());
		if (t == vs[i]){
		 if (flg == 1 && rev == t) mid += t; 
		 if (flg == 0){
		 mid = t; flg = 1;
		 if (rev == "") rev = mid;
			}
		}
		else if (mp[t] > 0 && mp[vs[i]] > 0) {
			left += vs[i];
			right += vs[i];
			mp[vs[i]]--; mp[t]--;
		}
	}
	len = left.length() * 2 + mid.length();
	cout << len << "\n";
	reverse (right.begin(), right.end());
	cout << left << mid << right << "\n";
}

 