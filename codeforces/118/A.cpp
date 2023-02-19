#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	char s[1000];
	char st[1000];
	char str[1000];
	char ans[1000];
	cin>>s;
	int i = 0;
	int j = 0;
	int len;
	while(s[i]!='\0'){
		if (s[i]!='a' && s[i]!='A' && s[i]!='e' && s[i]!='E'
		&& s[i]!='i' && s[i]!='I' && s[i]!='o' && s[i]!='O'
		&& s[i]!='u' && s[i]!='U' && s[i]!='y' && s[i]!='Y')
		{
			st[j]=s[i];
			if (st[j]>=65 && st[j]<=90)
			{
				st[j]=st[j]+32;
			}
			j++;
		}
		i++;
		
	}

	// for (int k = 0; k < j; ++k)
	// {
	// 	str[k]='.';
	// }
	int m = 0;
	int a = 0;
	for (int l = 0; l < j ; l++)
	{
		// if (l%2)
		// {
			ans[l]=st[m];
			m++;
		// }else{
		// 	ans[l]=str[a];
		// 	a++;
		// }
		cout<<"."<<ans[l];
	}
	

return 0;
}
