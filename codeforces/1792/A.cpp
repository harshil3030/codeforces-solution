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
	cin >> n;	
	while(n--){
		int t;
		cin>>t;
		int arr[t];
		int temp[t];		
		int cnt = 0;int count = 0;
		int count1 = 0; int count2 = 0;
		for (int i = 0; i < t; ++i)
		{
			cin>>arr[i];
		}
		sort(arr,arr+t);
		int k = 0;
		for (int i = 0; i < t; ++i)
		{
			if(arr[i]<=2){
				temp[k] = arr[i];
				k++;
				count++;
			}
		}

		for (int i = k; i < t; ++i)
		{
			
				cnt++;
		}
		
		for (int i = 0; i < count; ++i)
		{
			if (temp[i]==1)
			{
				count1++;
			}else if(temp[i]==2){
				count2++;
			}
		}
		if(count1%2){
			cnt+=count1/2+1;
		}else{
			cnt+=count1/2;
		}
		cnt+=count2;
		cout<<cnt<<endl;
	}
return 0;
}
