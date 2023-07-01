#include<bits/stdc++.h>
using namespace std;
//defines
#define f(i,k,n) for(int i = k; i < n; i++)
#define fr(i,k,n) for(int i = k; i >= n; i--)
#define ll  long long
#define i1(a)  ll a; cin >> a
#define i2(a,b)  ll a,b; cin >> a >> b
#define i3(a,b,c)  ll a,b,c; cin >> a >> b >> c
#define i4(a,b,c,d)  ll a,b,c,d; cin >> a >> b >> c >> d
#define i5(a,b,c,d,e)  ll a,b,c,d,e; cin >> a >> b >> c >> d >> e
#define i6(a,b,c,d,e,f)  ll a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f
#define vll   vector<ll>
#define vvll  vector<vector<ll>>
#define pb    push_back
#define popb  pop_back
#define fi     first
#define se     second
#define nl  "\n"
#define all(c)   (c).begin(),(c).end()
#define cy cout<<"YES"<<nl;
#define cn cout<<"NO"<<nl;
#define c1(x) cout<<(x)<<nl;
#define c2(x,y)         cout<<(x)<<" "<<(y)<<nl
#define c3(x,y,z)       cout<<(x)<<" "<<(y)<<" "<<(z)<<nl
#define c4(a,b,c,d)     cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<nl
#define c5(a,b,c,d,e)   cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<nl
#define c6(a,b,c,d,e,f) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<" "<<(e)<<" "<<(f)<<nl
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
#define cv(vec) for (auto x : vec) cout << x << " ";cout << endl;
#define inv(vec)  ll x; while(cin>>x) vec.pb(x);
const ll mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;


//functions
void invv(vvll &vec)
{
    for (auto &x : vec)
    {
        for (auto &y : x)
            cin >> y;
    }
}
void cvv(vvll &vec)
{
    for (auto x : vec)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
}

ll search(vector<ll>,ll,ll,ll);
//vector,target,start,end
ll search(vector<ll> a,ll t,ll s,ll e){
  while(s < e){
    ll mid = s + ( e - s )/ 2;
    if(a[mid] == t){
      return mid;
    }else if(a[mid] < t){
      s = mid + 1;
    }else{
      e = mid - 1;
    }
  }
}
void csort(vector <ll>);
void Burst();
bool comp(long long int a, long long int b){
	if(a % 2 == 0 && b % 2 == 0){
		return a < b;
	}
	if (a % 2 && b % 2){
		return a < b;
	}
	return a % 2 && b  % 2 == 0;
}
//taking number of testcases
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	// ll tt;
	// cin >> tt;
	// while(tt--){
		Burst();
	// }
return 0;
}

void Burst(){
	//write your solution from here
		long long int n;
		cin >> n;
		vector <long long int> v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		sort(v.begin(),v.end(),comp);

		long long int sum = 0;
		int cnt = 0;
		for (int i = n - 1; i > 0; i--){
			if (v[i] % 2) cnt++;
			sum += v[i];
		}

		if (cnt % 2) sum += v[0];

		if (cnt % 2 == 0 && v[0] % 2 == 0) sum += v[0];

		cout << sum << "\n";
		
}

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
