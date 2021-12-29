class Solution {
public:
    
    
    int grid2D[202][202];
    int row,col;
    int distance[202][202];
    
    struct nodeOfCost
    {
        pair<int, int>verdict;
        int w;
        nodeOfCost(pair<int, int> a,int  b)
        {
            verdict=a;
            w=b;
        }
        bool operator < (const nodeOfCost& p) const
        {
            return p.w < w;
        }
    };
    
    long long dijkstra()
    {
        int dx[]={1,0};
        int dy[]={0,1};
        
        memset(distance,63,sizeof(distance));
        
        priority_queue<nodeOfCost>q;
        
        pair<int,int>src;
        src.first = 0, src.second = 0;
        q.push(nodeOfCost(src,grid2D[0][0]));
        distance[src.first][src.second]=grid2D[0][0];
        
        cout<<"  "<< distance[src.first][src.second]<<endl;
        while(!q.empty())
        {
            nodeOfCost top=q.top();
            q.pop();
            pair<int, int> u=top.verdict;
            if(u.first==row && u.second == col) return distance[u.first][u.second];
            
            cout<<"current node "<<u.first<<" "<<u.second<<endl;
            for(int i=0; i<2; i++)
            {
                pair<int,int>v;
                
                v.first=u.first+dx[i];
                v.second=u.second+dy[i];
                
               // cout<<"new current node "<<v.first<<" "<<v.second<<endl;
                    if(v.first<=row&& v.first>=0&&v.second<=col&&v.second>=0)
                    {
                        cout<<"ok current node "<<v.first<<" "<<v.second<<endl;
                        
                        if(distance[u.first][u.second]+grid2D[v.first][v.second]<distance[v.first][v.second])
                        {
                            
                            distance[v.first][v.second]=distance[u.first][u.second]+grid2D[v.first][v.second];
                            
                            cout<<"curre dis "<<distance[v.first][v.second]<<endl;
                            q.push(nodeOfCost(v,distance[v.first][v.second]));
                        }
                    }
            }
        }
        return -1;
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        row = grid.size();
        col = grid[0].size();
        cout<<row<<" "<<col<<endl;
        row--;
        col--;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                grid2D[i][j]=grid[i][j];
            }
        }
        
        cout<<grid2D[0][0]<<endl;
        return dijkstra();
    }
};
