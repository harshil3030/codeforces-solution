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
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif


	int x;
	cin >> x;
	// bool  is_prime = true;
	// vector <int> prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

	// for (int i = 2; i*i < x; i++) {
	// 	if (x%i == 0){ 
	// 		is_prime = false;
	// 	break;
	//   }
	// }
	// if (x == 1) is_prime = true;
	// if (x == 4) {
	// 	cout << -1 << endl;
	// 	goto final;
	// }
	if (x == 1){
	 cout << -1 <<"\n";
	}else if (x <= 4){
		cout << x << " " << x << endl;

	}else {
				int a;
				int b;
				if (x % 2 == 0) {
					 a = x - 2;
					b = 2;
				}else {
					a =  x - 1;
					b = 2;
				}
				cout << a <<" " << b << endl;
		
	}
	 
	 
return 0;
}

 