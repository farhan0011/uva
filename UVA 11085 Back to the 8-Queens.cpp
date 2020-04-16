#include<bits/stdc++.h>
using namespace std;
int n=8,cnt = 0,cnt1=10;
int coltaken[12],d1taken[12],d2taken[12];
int board[10][10];
vector<vector<int>>V;
int A[8];
bool f(int r)
{
    if(r == n)
        {
            int tm = 0 ;
            vector<int>v;
           for(int i=0;i<8;i++)
            {
              for(int j=0; j<8; j++)
                {
                    if(board[j][i] == 1)
                        v.push_back(j);
                }
                //cout<<endl;
            }
            V.push_back(v);
             return true;
        }
    for(int c=0; c<n; c++)
    {
        if(coltaken[c])
            continue;
        int d1 = r+c;
        int d2 = r+n-c-1;
        if(d1taken[d1])
            continue;
        if(d2taken[d2])
            continue;
        coltaken[c] = 1;
        d1taken[d1] = 1;
        d2taken[d2] = 1;
        board[r][c] = 1;
        if(f(r+1))
            cnt++;

           //return true;
        coltaken[c] = 0;
        d1taken[d1] = 0;
        d2taken[d2] = 0;
        board[r][c] = 0;
    }
    return false;
}
int main()
{
    int t =0,col = 0;
    f(0);
    while(scanf("%d%d%d%d%d%d%d%d",&A[0],&A[1],&A[2],&A[3],&A[4],&A[5],&A[6],&A[7])!=EOF)
    {
        t++;
        int ans = 10 ;
        for(int i=0;i<92;i++)
        {
            int mis =0;
            for(int j=0;j<8;j++)
                {
                    //cout<<V[i][j]<<" ";
                    if(V[i][j]!=(A[j]-1))
                        mis++;
                }
                if(mis<ans)
                    ans = mis;
                //cout<<endl;
        }
        //cout<<endl;
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
}
