#include<bits/stdc++.h>
using namespace std;
int C[5] = {50,25,10,5,1};
int dp[1010][1010];
int f(int in,int rem)
{
    if(rem == 0)
        return 1;
        if(rem<0)
            return 0;
    if(in >= 5)
        return 0;
    if(dp[in][rem] != -1)
        return dp[in][rem];
    int a = f(in,rem - C[in]);
    int b = f(in +1 ,rem);
    return dp[in][rem] = a + b;
}
int main()
{
    int n;
    while(cin>>n){
            memset(dp,-1,sizeof(dp));
        cout<<f(0,n)<<endl;
    }
}
