rotten oranges
https://leetcode.com/problems/rotting-oranges/
class Solution {
public:
//min minutes=>bfs
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>> vis(m,vector<int>(n,0)); // no need of vis as grid does the job
        queue<pair<int,int>> q;
        int fresh=0;// track of fresh oranges
      
      //step 1. initial 2 wale ele in q and count of fresh ones
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && grid[i][j]==2){
                q.push({i,j});
                vis[i][j]=1;
                
            }
            else if(grid[i][j]==1)fresh++;


        }
       }
       //condn 1 
       if (fresh==0)return 0;

//step 2 use bfs 
       int cnt=0;
       vector<vector<int>> dirs{{1,0},{-1,0},{0,-1},{0,1}};
       while(!q.empty()){
        int sz=q.size();
        cnt++;
        while(sz--){
            auto [r,c]=q.front();
            q.pop();
            for(auto & d:dirs){//check all dirns
                int nr=r+d[0];
                int nc=c+d[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});
                    
                                    }
            }

        }

       
        }
        //necessary condn
        return fresh==0?cnt-1:-1;// since oranges rot after the 1st addn into the q of 2 ele , but algo does take that into account too

    }
};