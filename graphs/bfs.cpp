//bfs of a graph
https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> q;
        int n=adj.size();
        vector<int> ans;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        ans.push_back(0);
       
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            for(auto nei:adj[node]){
                if(!vis[nei]){
                    q.push(nei);
                    vis[nei]=1;
                    ans.push_back(nei);
                }
            }
        }
        return ans;
    }
};