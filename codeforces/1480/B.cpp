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
			ll a,b,n;
			cin >> a >> b >> n;
			vector<pair<long long,long long>> v(n);
			for (int i = 0; i < n; i++) cin >> v[i].fi;
			for (int i = 0; i < n; i++) cin >> v[i].se;
			auto comp = [&](pair<long long,long long> &p1, pair<long long,long long> &p2){
				return p1.fi < p2.fi;
			};
				sort(v.begin(),v.end(),comp);
			long long cnt = 0; long long i = 0;
			while (b > 0 && i < n){
				long long temp = v[i].se;
				// while (temp > 0 && b > 0){
				//  	temp -= a;
				// 	b -= v[i].fi;
				// }
				long long atk;
				if (temp % a){
					atk = temp/a + 1;
				} else atk = temp/a;
				b -= atk * v[i].fi;
				if (b <= 0){
					if (b + v[i].fi <= 0){
						cn; goto exit;
					}
				} 
				cnt++;
				i++;
			}
			// cout << cnt << endl;
			if (cnt == n){
			cout << "YES" << '\n';
		}else cn;
			exit:;
	  }
return 0;
}

 