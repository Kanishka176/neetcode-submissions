class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>> visited (n, vector<bool>(m, false));

        for(int a=0; a<n; a++){
            for(int b=0; b<m; b++){
                if(grid[a][b] == '1' && !visited[a][b]){
                    dfs(a, b, visited, grid, n, m);
                    islands++;
                }
            }
        }
        return islands;
    }

    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]!='1'){
            return;
        }
        visited[i][j]=true;

        dfs(i-1, j, visited, grid, n, m);
        dfs(i+1, j, visited, grid, n, m);
        dfs(i, j-1, visited, grid, n, m);
        dfs(i, j+1, visited, grid, n, m);
    }
};
