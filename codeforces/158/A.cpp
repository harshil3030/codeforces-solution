#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	int n,k;
	cin>>n>>k;
	int a[n];
	int temp;
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	temp=a[k-1];
	for (int i = 0; i < n; ++i)
	{
		if (a[i]>0 && a[i]>=temp)
		{
			count++;
		}
	}
	cout<<count<<endl;
return 0;
}
