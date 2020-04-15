#include<bits/stdc++.h>
using namespace std;
int n,r;
int isTaken[30];
vector<char> perm;
string s;
void f(int in)
{
    //cout<<"YES"<<endl;
    if(in == r)
    {
        for(int i=0; i<in; i++)
            cout<<perm[i];
        cout<<endl;
        return ;
    }
    for(int i=0; i<n;i++)
    {
        if(perm.size()>0 && perm[perm.size()-1]>s[i])
            continue;
        if(!isTaken[i])
        {
            isTaken[i] = 1;
            perm.push_back(s[i]);
            //getchar();
            //cout<<"go to in +1 = "<<in<<" with char "<<perm[in]<<" i = "<<i<<endl;
            f(in+1);
            isTaken[i] = 0;
           // getchar();
            //cout<<"back to in = "<<in<<" char is "<<perm[in]<<" i = "<<i<<endl;
            if(perm.size()>0)
            {
                cout<<"IN F"<<endl;
            for(int j=0; j<perm.size(); j++)
            {
                cout<<perm[j];
            }
            cout<<endl;
            }
            //perm.pop_back();
            while(s[i] == s[i+1] && i+1<n)
                i++;
        }


    }
}
int main()
{
    while(cin>>s>>r)
    {
    n = s.size();
    memset(isTaken,0,sizeof isTaken);
    sort(s.begin(),s.end());
    f(0);
    }
}
