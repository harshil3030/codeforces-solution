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
	cin>>s;
	if (s[0]>=97 && s[0]<=122)
	{
		s[0]=s[0]-32;
	}
	cout<<s;

return 0;
}
