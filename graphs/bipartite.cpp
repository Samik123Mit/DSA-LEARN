https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        // vector<int> vis(n,0);
        
for(int i=0;i<n;i++){
    if(color[i]!=-1)continue;
    queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nei:graph[node]){
                if(color[nei]==-1){
                    color[nei]=1-color[node];

                    q.push(nei);
                    // vis[nei]=1;
                    // if(color[nei]==color[node])return false;

                }
                else{
                    if(color[nei]==color[node])return false;
                }
                
            }
        }
}

        
        return true;

    }
};