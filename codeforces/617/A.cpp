#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	int n;
	cin>>n;
	int ans;
	if (n%5!=0)
	{
		ans=n/5+1;
	}else
	ans = n/5;

	cout<<ans<<endl;


return 0;
}
