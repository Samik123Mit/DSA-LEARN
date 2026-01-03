//no. of provinces
https://leetcode.com/problems/number-of-provinces/submissions/1842618228/
class Solution {
public:
 void dfsh(int node,vector<vector<int>>& adj,vector<int>&vis){
      vis[node]=1;
      for(auto nei:adj[node]){
          if(!vis[nei]){
              dfsh(nei,adj,vis);
          }
      }
  }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfsh(i,adj,vis);
                cnt++;
        }
        }
        return cnt;
    }
};