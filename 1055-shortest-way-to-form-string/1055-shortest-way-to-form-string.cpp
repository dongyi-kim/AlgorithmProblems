class Solution {
public:
    int shortestWay(string b, string a) {
        unordered_map<char, vector<int> > indicies;
        for(int i = 0 ; i < b.length() ; i += 1){
            indicies[b[i]].push_back(i);
        }
        int pieces = 0;
        int j = b.size();
        for(int i = 0 ; i < a.length() ; i += 1){
            auto &v = indicies[a[i]];
            if(v.size() == 0) return -1;
            auto nj = lower_bound(v.begin(), v.end(), j);
            if(nj == v.end()) {
                nj = lower_bound(v.begin(), v.end(), 0);
                pieces += 1;
            }
            j = *nj + 1;
        }
        return pieces;
    }
};