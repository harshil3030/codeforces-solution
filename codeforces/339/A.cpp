#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

//write your code from here
	char s[100],ans[101];
	int count1=0,count2=0,count3=0,size=0;
	int i=0;
	cin>>s;
	while(s[i]!='\0'){
		
		if(i%2==0){
			if (s[i]=='1')
			{
				count1++;
			}else if (s[i]=='2')
			{
				count2++;
			}else if(s[i]=='3'){
				count3++;
			}
		} i++;size++;
	}
	for (int i = 0; i < count1*2-1; i+=2)
	{
		ans[i]='1';
		ans[i+1]='+';
	}
	for (int i = count1*2; i < (count2+count1)*2 ; i+=2)
	{
		ans[i]='2';
		ans[i+1]='+';
	}
	for (int i = (count2+count1)*2; i < (count1+count2+count3)*2; i+=2)
	{
		ans[i]='3';
		ans[i+1]='+';
	}
	ans[size]='\0';
	cout<<ans<<endl;

return 0;
}
