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

        // while(tt--)
	solve();
return 0;
}

void solve(){
	//write down your solution from here	
	long n; cin >> n;
	vector<long long> v(n); for (int i = 0; i < n; i++) cin >> v[i];
	int ecnt = 0;
	int ocnt = 0;
	for (int i = 0; i < n; i++){
		if (v[i] % 2){ocnt++;}
		else ecnt++;
	}
	long long sm = 0;
	// cout << ocnt << " " << ecnt << endl;
	int diff = abs(ecnt - ocnt);
	// cout << diff << endl;
	if (diff <= 1){cout << 0 << endl;}
	else{
		diff--;
		auto comp = [&](long long &a1, long long &a2){
			return a1 % 2 && a2 % 2 == 0;
		};
		sort(v.begin(),v.end(),comp);
		int in = 0;
		for (int i = 0; i < n; i++){
			if (v[i] % 2) in = i;
		}sort(v.begin(), v.begin() + in + 1);
		sort(v.begin() + in + 1, v.end());

		// for (int i = 0; i < n; i++) cout << v[i] << " ";
		if (ecnt > ocnt){

			int i = ocnt;
			while (diff--){
				sm += v[i]; i++;
			}
		}else{
			int i = 0;
			while (diff--){
				sm += v[i]; i++;
			}
		}
		cout << sm << endl;
	}
}



 