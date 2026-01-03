//cycle detection in an undirected graph
//https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

//DFS
class Solution {
  public:
  bool dfs(int node,int parent,vector<int> &vis, vector<vector<int>>&adj){
      vis[node]=1;
      for(auto nei:adj[node]){
          
          if(!vis[nei]){
             if(dfs(nei,node,vis,adj))return true;
          
      }
      else if(nei!=parent){
          return true;
      }
      }
      return false;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj))return true;
            }
            
        }
    
        return false;
    }
};

//////BFS
class Solution {
  public:
  bool detect(int src, vector<vector<int>>&adj,vector<int>&vis){
       queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src]=1;
        while(!q.empty()){
            int node=q.front().first;
            int par=q.front().second;
            q.pop();
            for(int nei:adj[node]){
                if(!vis[nei]){
                    vis[nei]=1;
                    q.push({nei,node});
                }
                else if(par!=nei)return true;
            }
        }
        return false;
  }
 
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis))return true;
            }
        }
        return false;
       
        
    }
};