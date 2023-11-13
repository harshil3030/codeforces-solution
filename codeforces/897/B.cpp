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

//sol.
void solve(){
	long long n, m; cin >> n >> m;
    long long sm = 0;
    for (ll i = 0; i < n; i++) {
    	string s = to_string(i + 1);
    	string t = s;
    	reverse(t.begin(), t.end());
    	s += t;
    	long long got = stoll(s);
    	sm = (sm % m + got % m) % m;
    }
	cout << sm % m << "\n";
}
//maths
//check n how to generate the sum right there must be pattern here
/*11, 22, 33, .... , 99 // jump of 11 ... 9 terms
than direct 
1001, 1012 ? no .. but 1111 ... 1221 ... 1331 .. // jump of 110 90 terms..
2002, 2112... still 110 gaps. 
100001, //jump of 1100
100001 + 1100 
101101, 102201, 103301, .... //jump of 1100 
123321, 100001, 10000
*/
