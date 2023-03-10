class Solution {
private:
    typedef long long ll;
    const int MOD = 1E9 + 7;
    
    int dijkstra(const vector<vector<pair<int, ll>>>& adj){
        set<pair<ll, int>> pq;
        int n = adj.size();
        vector<ll> numWays(n, 1), dist(n, LLONG_MAX);
        dist[0] = 0;
        for (int i = 0; i < n; ++i){
            pq.insert({dist[i], i});
        }
        
        while (!pq.empty()){
            int u = pq.begin()->second;
            ll uDist = pq.begin()->first;
            pq.erase(pq.begin());
            for (auto [v, w]: adj[u]){
                ll vDist = dist[v], newDist = uDist + w;
                if (vDist > newDist){
                    pq.erase({vDist, v});
                    pq.insert({newDist, v});
                    dist[v] = newDist;
                    numWays[v] = numWays[u];
                } else if (vDist == newDist){
                    numWays[v] = (numWays[v] + numWays[u]) % MOD;
                }
            }
        }
        return numWays[n - 1];
    }
    
    
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, ll>>> adj(n);
        for (auto road: roads){
            adj[road[0]].push_back({road[1], ll(road[2])});
            adj[road[1]].push_back({road[0], ll(road[2])});
        }
        return dijkstra(adj);
    }
};