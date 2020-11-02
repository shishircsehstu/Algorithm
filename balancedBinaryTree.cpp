#include<bits/stdc++.h>
using namespace std;
#define Max_size 5001
vector<int>graph[Max_size]; // size of graph
int visited[Max_size];
bool flag = true;


int  dfs(int src)
{
    int left_height = 0;
    int right_height = 0;

    if (visited[src] == 1) return 0;
    visited[src]=1;

    if (src!=1&&graph[src].size()==0)
    {
        return 1; //leaf node
    }
    for(int i=0; i<graph[src].size(); i++)
    {
        if (i==0)
            left_height = dfs(graph[src][i]);
        else
            right_height = dfs(graph[src][i]);
    }


    if (abs(right_height-left_height)>1)
        flag = false;

        /* if final result of flag is true
        we can say the tree is
        balanced binary tree
        otherwise not balanced
        */

    return max(left_height,right_height)+1;

}
void take_Graph()
{
    int i,j,u,v,numOfnode;
    scanf("%d",&numOfnode);
    for(i = 0; i<numOfnode-1; i++)
    {
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        /*
        Here we take a directed
        graph and create a
        link between u->v
        */
    }
}
int main()
{
    take_Graph();
    dfs(1); // route value always be 1
    if (flag == true)
        cout<<"Balance tree\n";
    else cout<<"Not balanced\n";


}
/*
7
1 3
1 2
2 4
2 5
5 6
3 7


*/
