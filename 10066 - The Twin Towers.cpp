#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int A[105],B[105];
int n,m;
int f(int i,int j)
{
    if(i == n || j == m)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int a=0,b=0,c=0;
    if(A[i] == B[j])
        a = 1 + f(i+1,j+1);
    b = f(i+1,j);
    c = f(i,j+1);
    return dp[i][j] = max(a,max(b,c));
}
int main()
{
    int cnt = 1;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)
            return 0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)
            cin>>A[i];
        for(int i=0;i<m;i++)
            cin>>B[i];
            cout<<"Twin Towers #"<<cnt<<endl;
            cnt++;
        cout<<"Number of Tiles : "<<f(0,0)<<endl;
        cout<<endl;
    }
}
