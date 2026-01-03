//find the arr of conn components in an undirected graph
https://www.geeksforgeeks.org/problems/connected-components-in-an-undirected-graph/1
class Solution {
  public:
  void dfsh(int node,vector<vector<int>>& adj,vector<int>&vis, vector<int> &c ){
      vis[node]=1;
      c.push_back(node);
      for(auto nei:adj[node]){
          if(!vis[nei]){
              
              dfsh(nei,adj,vis,c);
          }
      }
  }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> ans;
        vector<int> vis(V,0);
        vector<vector<int>> adj(V);
        for(auto e:edges){
            auto u=e[0];
            auto v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            }
            for(int i=0;i<V;i++){
                if(!vis[i]){
                    vector<int> c;
                    dfsh(i,adj,vis,c);
                    ans.push_back(c);
                }
                
            }
            return ans;
        
        
    }
};
