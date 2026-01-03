// dfs of a graph
https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
  public:
  void dfsh(int node,vector<vector<int>>& adj,vector<int>&vis, vector<int> &ans ){
      vis[node]=1;
      ans.push_back(node);
      for(auto nei:adj[node]){
          if(!vis[nei]){
              
              dfsh(nei,adj,vis,ans);
          }
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
           if(!vis[i]) dfsh(i,adj,vis,ans);
        }
        return ans;
        
        
        
    }
};