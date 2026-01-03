surrounded-regions

https://leetcode.com/problems/surrounded-regions/submissions/1845308876/
We need to flip only those 'O' that are completely surrounded by 'X'.But any 'O' touching the border (directly or through a chain of 'O's) can never be surrounded, so it must NOT be flipped.

class Solution {
public:
void dfsh(int r, int c, vector<vector<char>> &board,vector<vector<int>> &vis){
   int m=board.size();
    int n=board[0].size();
    vis[r][c]=1;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    for(int k=0;k<4;k++){
        int dr=dx[k]+r;
        int dc=dy[k]+c;
        if(dr<0 || dc<0 || dr>=m || dc>=n){
            continue;
        }
        if(vis[dr][dc])continue;
        if(board[dr][dc]=='O'){
            dfsh(dr,dc,board,vis);
        }
    }


}
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));

        //step 1 mark the border O's as safe -> ones which r connected to border O's should ot be flipped-> so use dfs
          for(int j=0;j<n;j++){
                if(board[0][j]=='O' && !vis[0][j]){
                    dfsh(0,j,board,vis);
                }
        }
        for(int j=0;j<n;j++){
                if(board[m-1][j]=='O' && !vis[m-1][j]){
                    dfsh(m-1,j,board,vis);
                }}

                for(int j=0;j<m;j++){
                if(board[j][0]=='O' && !vis[j][0]){
                    dfsh(j,0,board,vis);
                }
                }

                 for(int j=0;j<m;j++){
                if(board[j][n-1]=='O' && !vis[j][n-1]){
                    dfsh(j,n-1,board,vis);
                }}

             // mark all other ones as X   
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]){
                    // dfsh(i,j,board,vis);
                    board[i][j]='X';
                    vis[i][j]=1;
                }
            }
        }
      
                

    }
};