#include<bits/stdc++.h>
using namespace std;

#define ll    long long int
#define ff    first
#define ss    second
#define gcd(a, b) __gcd((a), (b))
#define lcm(a, b) (a * b) / gcd(a, b)
const ll mod = 1000000007;
const long double pi=3.14159265358979323846264338327950288419716939937510582097494459230;
void solve();
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	// ll tt; cin >> tt;  while(tt--)
	solve();
return 0;
}
void solve() {
	long long n; cin >> n;
	long long sm = (n * (n + 1))/2;
	if (sm % 2 == 1) {
		cout << 1 << "\n";
	} else cout << 0 << "\n";	
	vector<int> ans; 
	sm /= 2;
	for (int i = n; i >= 1; i--) {
		if (i <= sm) {
			sm -= i;
			ans.push_back(i);
		}
	}
	cout << ans.size() << " ";
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
		cout << "\n";
}
