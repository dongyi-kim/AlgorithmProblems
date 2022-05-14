class Solution {
public:
    int dr[4] = { 0, +1, 0, -1 };
    int dc[4] = { +1, 0, -1, 0 };
    const int USED = -1e9;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0) return {};
        int cols = matrix[0].size();
        if(cols == 0) return {};
        
        int n = rows * cols; // the number of entire cells 
        int r = 0, c = 0; // r, c indicies
        int dir = 0;
        
        vector<int> path;
        for(int i = 0 ; i < n ; i += 1){
            
            path.push_back(matrix[r][c]);
            matrix[r][c] = USED;
            
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            if( nr < 0 || nr >= rows || nc < 0 || nc >= cols || matrix[nr][nc] == USED){
                dir = (dir+1)%4;
                nr = r + dr[dir];
                nc = c + dc[dir];
            }
            r = nr, c = nc;
        }
        return path;
    }
};