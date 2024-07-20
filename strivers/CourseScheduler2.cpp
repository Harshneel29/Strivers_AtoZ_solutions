class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> ind(n,0);
        vector<vector<int>> adj(n);

        for(auto it : p){
            ind[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(ind[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it] == 0) q.push(it);
            }
        }

        if (ans.size() == n)return ans;
        else return {};
    }
};