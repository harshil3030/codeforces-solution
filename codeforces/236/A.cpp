#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	char s[100];
	char temp;
	int count=0;
	int len=0;
	cin>>s;
	while(s[len]!='\0'){
		len++;
	}
	for (int i = 0; i < len; ++i)
	{
		for (int j = i+1; j <= len; ++j)
		{
			if (s[i]>s[j])
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
			}
		}
	}
	for (int i = 0; i < len; ++i)
	{
		if (s[i]!=s[i+1])
		{
			count++;
		}
	}
  	if (count%2==0)
  	{
  		cout<<"CHAT WITH HER!";
  	}else
  	cout<<"IGNORE HIM!";

return 0;
}
