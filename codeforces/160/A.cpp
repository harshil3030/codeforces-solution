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
    int sum1 = 0;
    int sum = 0; int cnt = 0;
    // int a[n];
    vector <int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum1+=a[i];
    }
    sort(a.rbegin(),a.rend());
    // if(sum1%2){
    //     sum1/=2;
    //     sum1++;
    // }else{
    //     sum1/=2;
    // }

    // for(int i = 0; i < n; i++){

    // }
    int j = 0;
    while(sum<=sum1/2){
        sum+=a[j];
        j++;
        cnt++;
    }
    cout<<cnt<<endl;

return 0;
}
