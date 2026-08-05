class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree (numCourses, 0);
        vector<vector<int>> adj (numCourses);
        vector<int> output (numCourses);

        for(auto& p : prerequisites){
            indegree[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }

        queue<int> q;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int finish = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            output[numCourses - finish - 1] = node;
            finish++;

            for(int n : adj[node]){
                indegree[n]--;

                if(indegree[n]==0){
                    q.push(n);
                }
            }
        }
        if(finish != numCourses){
            return {};
        }

        return output;
    }
};
