class Solution {
public:
    bool removeOnes(vector<vector<int>>& v, bool flaged = false) {
        if(v.size() == 0) return 0;
        if(v[0].size() == 0) return 0;
        int rows = v.size();
        int cols = v[0].size();
        
        bool answer = (flaged) ? false : removeOnes(v, true);

        int count = 0;
        vector<bool> flipped(cols, false);
        for(int c = 0; c< cols; c+= 1){
            int value = (not flaged) ? v[0][c] : 1 - v[0][c];
            if(value != 0){
                count += 1;
                flipped[c] = true;
            }
        }

        for(int r = 0; r < rows; r += 1){
            int reversed = 0;
            for(int c = 0 ; c < cols; c+= 1){
                int value = (flipped[c]) ?1 - v[r][c] : v[r][c];
                if(value != 0){
                    reversed += 1;
                }
            }
            if(reversed % cols != 0) return false;
        }
        return true;
    }
};