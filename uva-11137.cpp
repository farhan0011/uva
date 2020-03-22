#include<bits/stdc++.h>
using namespace std;
int coin[21]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
#define ll long long
ll dp[25][10000];
int n;
ll f(int in,int rem)
{
    if(rem < 0)
        return 0;
    if(in >= 21)
    {
        if(rem == 0)
            return 1;
        else
            return 0;
    }
    if(dp[in][rem] != -1)
        return dp[in][rem];
    ll a = f(in,rem - coin[in]);
    ll b = f(in + 1,rem);
    return dp[in][rem] = a + b;
}
int main()
{
    while(cin>>n)
    {
        memset(dp,-1,sizeof(dp));
        cout<<f(0,n)<<endl;
    }
}
