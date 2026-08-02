class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int time=0;
        int fresh=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> dir= {{0,1},{0,-1},{1,0},{-1,0}};

        while(fresh>0 && !q.empty()){
            int len= q.size();

            for(int i=0; i<len; i++){
                auto curr= q.front();
                q.pop();

                int r= curr.first;
                int c= curr.second;

                for(const auto& d : dir){
                    int row = r+d.first;
                    int col = c+d.second;

                    if(row>=0 && row<n && col>=0 && col<m && grid[row][col]==1){
                        grid[row][col]=2;
                        q.push({row,col});
                        fresh--;
                    }
                }
            }
            time++;
        }  
        return fresh == 0? time:-1; 
    }
};
