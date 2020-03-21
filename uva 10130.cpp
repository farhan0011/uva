#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],n;
int p[1010];
int w[1010];
int knap(int in,int rem)
{
    if(rem < 0)
        return INT_MIN;
    if(in == n)
        return 0;
        if(dp[in][rem] !=-1)
        return dp[in][rem];
    int a,b;
    a = p[in] + knap(in+1,rem - w[in]);
    b = knap(in +1,rem );
    dp[in][rem] = max(a,b);
    return dp[in][rem];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(p,0,sizeof(p));
        memset(w,0,sizeof(w));
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>p[i]>>w[i];
        int g;
        cin>>g;
        int G[g];
        for(int i=0;i<g;i++)
            cin>>G[i];
        int ans = 0;
        for(int i=0;i<g;i++)
        {
            memset(dp,-1,sizeof(dp));
            int x = knap(0,G[i]);
            cout<<x<<endl;
            if(x>0)
                ans+=x;
        }
        cout<<ans<<endl;
    }
}
