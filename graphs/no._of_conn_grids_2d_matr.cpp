no. of conn. grids in a 2d matrix

https://www.naukri.com/code360/library/find-the-number-of-connected-grids-of-a-given-size-in-a-2d-matrix

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int dfs(vector<vector<int>>& visited, vector<vector<int>>& grid, int i, int j){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()) return 0;
    if(visited[i][j] || grid[i][j]==0) return 0;

    visited[i][j] = 1;

    int cnt = 1;
    cnt += dfs(visited,grid,i+1,j);
    cnt += dfs(visited,grid,i-1,j);
    cnt += dfs(visited,grid,i,j+1);
    cnt += dfs(visited,grid,i,j-1);
    return cnt;
}

unordered_map<int,int> findFrequency(vector<vector<int>>& grid){
    unordered_map<int,int> freq;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));

    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(!visited[i][j] && grid[i][j]==1){
                int size = dfs(visited,grid,i,j);
                freq[size]++;
            }
        }
    }
    return freq;
}

int main(){
    vector<vector<int>> grid{
        {1,1,1,1,1,1},
        {1,1,0,0,0,0},
        {0,0,0,1,1,1},
        {0,0,0,1,1,1},
        {0,0,1,0,0,0},
        {1,0,0,0,0,0}
    };

    vector<int> queries{6,1,8,2};

    unordered_map<int,int> freq = findFrequency(grid);
    for(int q : queries) cout << freq[q] << endl;
}
