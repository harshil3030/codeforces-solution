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
        	long n;
        	cin >> n;
        	string s;
        	cin >> s;
        	long long  cnt0 = 0;
        	long long cnt00 = 0;
        	long long cnt11 = 0;
        	long long  cnt1 = 0;
        	long long mx = 0;	 
			long long mx0 = 0;
			long long  mx1 = 0;
			for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				cnt0++;
				cnt00++; 
				mx0 = max(mx0,cnt0);
			} else {
				cnt0 = 0;
			} 
			if (s[i] == '1') {
				cnt1++; 
				cnt11++;
			   mx1 = max(mx1,cnt1);
			} else {
				cnt1 = 0;
			}
		} 
		mx = max(mx,mx0*mx0); 
		mx = max(mx,mx1*mx1);
		mx = max(mx,cnt11*cnt00);
		cout << mx << endl;     	


		
	  }
return 0;
}

 