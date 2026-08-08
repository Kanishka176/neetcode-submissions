class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n);
        vector<bool> vis (n,false);

        for(const auto& e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res=0;

        for(int i=0; i<n; i++){
            if(vis[i]==false){
                bfs(adj, vis, i);
                res++;
            }


        }
        return res;
    }

private:
    void bfs(vector<vector<int>>& adj, vector<bool>&vis, int node){
        queue<int> q;
        q.push(node);
        vis[node]=true;

        while(!q.empty()){
            int cur= q.front();
            q.pop();

            for(int n : adj[cur]){
                if(!vis[n]){
                    vis[n]=true;
                    q.push(n);
                }
            }
        }
    }
};
