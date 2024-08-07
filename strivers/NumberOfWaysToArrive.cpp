class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];

        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<long long, long long>,
                       vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        vector<long long> dist(n,1e18), ways(n,0);
        dist[0] = 0;
        ways[0] = 1;

        pq.push({0,0});
        int mod = (int)(1e9 + 7);


        while(!pq.empty()){
            auto iter = pq.top();
            pq.pop();
            long long dis = iter.first;
            long long node = iter.second;

            for(auto it : adj[node]){
                long long edw = it.second;
                long long adjn = it.first;

                if(dis + edw < dist[adjn]){
                    dist[adjn] = dis + edw;
                    pq.push({dis + edw, adjn});
                    ways[adjn] = ways[node];
                }
                else if(dis + edw == dist[adjn]){
                    ways[adjn] = (ways[adjn] + ways[node]) % mod; 
                }
            }
        }

        return ways[n-1]%mod;
    }
};