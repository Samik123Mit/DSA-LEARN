01 matrix
https://leetcode.com/problems/01-matrix/submissions/1845256146/
class Solution {
public:
//nearest distance=>bfs(multisource)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,pair<int,int>>> q;//{dis,u}
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0 && !vis[i][j]){
                    q.push({0,{i,j}}); 
                    vis[i][j]=1;
                    ans[i][j]=0;                 
                }
            }
        }
        while(!q.empty()){
            auto cur=q.front();
            q.pop();
            int dis=cur.first;
            int u=cur.second.first;
            int v=cur.second.second;
            for(int i=0;i<4;i++){
                int dr=u+dx[i];
                int dc=v+dy[i];
                if(dr<0 || dc<0 || dr>=m || dc>=n){
                    continue;
                }
                if(vis[dr][dc])continue;
                vis[dr][dc]=1;
                ans[dr][dc]=dis+1;
                q.push({dis+1,{dr,dc}});
            }
        }



return ans;

    }
};