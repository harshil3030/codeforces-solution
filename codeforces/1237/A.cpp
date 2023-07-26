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
	solve();
return 0;
}

void solve(){
	//write down your solution from here
	long long n;
	cin >> n;
	vector <long long> v(n);
	ll smpos = 0;
	ll smneg = 0;
	for (int i = 0; i < n; i++){
		cin >> v[i];
		if (v[i] > 0) smpos += abs(v[i]/2);
		if (v[i] < 0) smneg += abs(v[i]/2);
	}
	if (smpos > smneg){
		ll diff = smpos - smneg;
		int in = 0;
		for (int i = 0; i < n && diff > 0; i++){
			if (v[i] < 0 && abs(v[i]) % 2){
				diff--;
				v[i]/=2; v[i] -= 1;
			}else{
				v[i] /= 2;
			}
			in = i;
		}in++;
		for (int i = in; i < n; i++) v[i]/=2;
	} else if (smneg > smpos){
		ll diff = smneg - smpos; int in = 0;
		for (int i = 0; i < n && diff > 0; i++){
			if (v[i] > 0 && v[i] % 2){
				v[i]/=2; v[i] += 1;			
				diff--;

			}else {
				v[i] /= 2;
			} 
			in = i;
		}in++;
		for (int i = in; i < n; i++) v[i] /= 2;
	} else{
		for (int i = 0; i < n; i++) v[i] /= 2;
	}
	for (auto x : v) {
		cout << x << endl; 
	}

}

 