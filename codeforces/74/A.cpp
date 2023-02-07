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
	char s[n][50];
	int a[n][7];
	int ans[n];
	int sum=0;
	int max=-32000;
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin>>s[i];
		for (int j = 0; j < 7; ++j)
		{
			cin>>a[i][j];
		}
		for (int j = 0; j < 2; ++j)
		{
			if (j==0)
			{
				sum+=a[i][j]*100;
			}else
			sum=sum-a[i][j]*50;
		}
		for (int j = 2; j < 7 ; ++j)
		{
			sum+=a[i][j];
		}ans[i]=sum;
		sum=0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (max<ans[i])
		{
			max=ans[i];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if(ans[i]==max){
			cout<<s[i]<<endl;
		}
	}

return 0;
}
