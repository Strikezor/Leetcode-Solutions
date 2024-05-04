class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans = 0;
        map<vector<int>,int> count;

        for(int i=0;i<grid[0].size();i++){
            vector<int> col;
            for(int j=0;j<grid.size();j++){
                col.push_back(grid[j][i]);
            }
            count[col]++;
        }

        for(auto row:grid){
            ans+=count[row];
        }
        return ans;
    }
};