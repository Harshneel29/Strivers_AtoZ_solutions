class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(auto it : prerequisites){
            ind[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }



        queue<int> q;
        int cnt = 0;


        for(int i = 0; i < n; i++){
           if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it] == 0) q.push(it);
            }
        }

        return cnt ==  n;
    }
};