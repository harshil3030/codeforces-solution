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
        while(tt--){
	    //write down your solution from here
        	int n;
        	cin >> n;
        vector<int> v(n);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
        	cin >> v[i];  if (v[i] == 0)cnt++;
        }
        if (cnt) {
        	cout << n - cnt <<"\n";
        	continue;
        }
        sort(v.begin(),v.end()); int flag = 1;
        for (int i = 0; i < n - 1; i++) {
        		if (v[i] == v[i+1]){
        			cout << n << endl;
        			flag = 0; break; 
        		}
        } if(flag == 0) continue;
       	cout << n + 1 << "\n";

		
	  }
return 0;
}

 