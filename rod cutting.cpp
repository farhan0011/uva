#include<bits/stdc++.h>
using namespace std;
int dp[55][55];
int A[55];
int n;
int f(int st,int ed)
{
    if(st+1 == ed)
        return 0;
    if(dp[st][ed]!=-1)
        return dp[st][ed];
    int ans = INT_MAX;
    for(int i=st+1; i<ed; i++)
    {
        int temp = f(st,i)+f(i,ed)+A[ed]-A[st];
        if(temp<ans)
            ans = temp;
    }
    return dp[st][ed] = ans;
}
int main()
{
    while(1)
    {
        int l;
    cin>>l;
    if(l == 0)
        break;
    memset(dp,-1,sizeof dp);
    cin>>n;
    A[0]=0;
    A[n+1] = l;
    for(int i=1; i<=n; i++)
        cin>>A[i];
    cout<<"The minimum cutting is "<<f(0,n+1)<<"."<<endl;
    }
}
