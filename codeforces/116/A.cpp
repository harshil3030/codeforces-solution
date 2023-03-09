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

    int a[2*n];
    for(int i = 0; i < 2*n; i++){
        cin >> a[i];
    }
    int sum = 0;
    int max = 0;
    for(int i = 0; i < 2*n; i++){
        if(i%2==0){
            sum-=a[i];
        }else{
            sum+=a[i];
        }

        if(sum>=max){
            max = sum;
        }
    }
    cout<<max<<endl;
    



return 0;
}
