#include<bits/stdc++.h>
using namespace std;
#define for(i,k,n) for(int i = k; i < n; i++)
void Burst();
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
	// int tt;
 int n; cin >> n;
    int a[n]; for(i,0,n) {cin >> a[i];}
    int cnt = 1;
    int max = 0;
    if(n==1){cout << cnt << endl;}
    else{
    for(i,0,n-1){
    	if(a[i]<=a[i+1]){
    		cnt++;
    	}else{
    		// if(cnt>max){
    			// max = cnt;
    			cnt = 1;
    		}
       if(cnt > max){
       	max = cnt;
       }
    	// }
    }
    cout << max << endl;
}
	// cin >> tt;
	// while(tt--){
		// Burst();
	// }
return 0;
}

  // void? Burst(){
	//write your solution from here

// }