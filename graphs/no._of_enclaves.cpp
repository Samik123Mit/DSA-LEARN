

https://leetcode.com/problems/number-of-enclaves/submissions/1845324358/

class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&grid, vector<vector<int>> &vis){
    int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int dr=r+dx[i];
            int dc=c+dy[i];
            if(dr<0 || dc<0 || dr>=m || dc>=n )continue;
            if(vis[dr][dc])continue;
            if(grid[dr][dc]==1)dfs(dr,dc,grid,vis);
        }
}

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(0,i,grid,vis);
            }
             if(!vis[m-1][i] && grid[m-1][i]==1){
                dfs(m-1,i,grid,vis);
            }
             
        }
         for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,grid,vis);
            }
             if(!vis[i][n-1] && grid[i][n-1]==1){
                dfs(i,n-1,grid,vis);
            }
             
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0 ;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    vis[i][j]=1;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};