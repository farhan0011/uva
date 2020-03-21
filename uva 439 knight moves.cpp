#include<bits/stdc++.h>
using namespace std;
#define LIM 1003
#define pi pair<int,int>
#define MAX 10000007
int dis[9][9];
int grid[LIM][LIM];
//int dr[]={-1,-1,-1, 0, 0,+1,+1,+1};
//int dc[]={ 0,+1,-1,+1,-1, 0,-1,+1};
int dr[]={-2,-2,-1,-1,+2,+2,+1,+1};
int dc[]={+1,-1,+2,-2,+1,-1,+2,-2};
void bfs(int sr,int sc)
{
    dis[sr][sc]=0;
    queue<pi>q;
    q.push(pi(sr,sc));
    while(!q.empty())
    {
        pi u=q.front();
        q.pop();
        int ur=u.first;
        int uc=u.second;
        for(int i=0;i<8;i++)
        {
            int vr=ur+dr[i];
            int vc=uc+dc[i];
            if(vr<1||vr>8||vc<1||vc>8)
                continue;
            if((dis[ur][uc]+1)<dis[vr][vc])
            {
                dis[vr][vc]=dis[ur][uc]+1;
                //cout<<vr<<" "<<vc<<" "<<dis[vr][vc]<<endl;
                q.push(pi(vr,vc));
            }
        }
    }
}
int main()
{
        string s,s1;
        while(cin>>s>>s1)
        {
            for(int i=1;i<=8;i++)
             {
            for(int j=1;j<=8;j++)
                dis[i][j]=MAX;
              }
            int ur=s[1]-'0';
            int uc=s[0]-'a'+1;
            int vr=s1[1]-'0';
            int vc=s1[0]-'a'+1;
            //cout<<dis[vr][vc]<<endl;
            //cout<<ur<<" "<<uc<<" "<<vr<<" "<<vc<<endl;
            bfs(ur,uc);
            cout<<"To get from "<<s<<" to "<<s1<<" takes "<<dis[vr][vc]<<" knight moves."<<endl;
        }

}
/*
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
*/
