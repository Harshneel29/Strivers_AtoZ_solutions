class Solution {
public:

    void dfs(int node, vector<int> adj[], vector<bool>& vis){
        vis[node] = true;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> aj[n];
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0;j < n; j++){
                if(isConnected[i][j] == 1){
                    aj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n,false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans++;
                dfs(i,aj,vis);
            }
        }

        return ans;
    }
};