#include<bits/stdc++.h>
using namespace std;

vector<int>vec[10001];
int vis[100001];
int path[10001];
void all_path(int s, int d,int indx)
{
   // cout<<s<<endl;
    vis[s]=1;
    path[indx++]=s;
    int x, i;
    if(s==d)
    {
        for( i=0; i<indx; i++)
            cout<<path[i]<<" ";
        cout<<endl<<endl;
    }

    for(i=0; i<vec[s].size(); i++)
    {
        x=vec[s][i];
        if(vis[x]==0)
        {
            all_path(x,d,indx);
        }
    }
   // cout<<"false "<<s<<endl;
    indx--;
    vis[s]=0;
}
int main()
{
    int n,i;
    vec[1].push_back(2);
    vec[2].push_back(3);
    vec[3].push_back(3);

    vec[1].push_back(3);
    vec[1].push_back(6);


    vec[2].push_back(6);

    vec[3].push_back(4);
    vec[4].push_back(5);
    vec[5].push_back(3);
    vec[3].push_back(6);
    vec[4].push_back(6);
    vec[5].push_back(2);
    vec[5].push_back(7);


    n=7;
    for(i=1; i<=n; i++)
        vis[i]=0;

    all_path(1,6,0);
    return 0;
}

