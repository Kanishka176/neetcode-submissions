class Solution {
    int rows, columns;
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

public:
    void solve(vector<vector<char>>& board) {
        rows= board.size();
        columns= board[0].size();

        capture(board);

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if(board[i][j]=='O'){
                    board[i][j]= 'X';
                }
                else if(board[i][j]=='T'){
                    board[i][j]='O';
                }
            }
        }
    }

private:
    void capture(vector<vector<char>>& board){
        queue<pair<int,int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<columns; j++){
                if((i==0 || i==rows-1 || j==0 || j==columns-1) && board[i][j]=='O'){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [r,c]= q.front();
            q.pop();

            if(board[r][c]== 'O'){
                board[r][c]= 'T';

                for( auto& dir : directions){
                    int nr= r + dir.first;
                    int nc= c + dir.second;

                    if(nr>=0 && nr<rows && nc>=0 && nc<columns){
                        q.push({nr,nc});
                    }
                }
            }
        }
    }
};
