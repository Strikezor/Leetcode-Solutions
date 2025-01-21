class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> topPrefix(n+1,0),bottomPrefix(n+1,0);
        for(int i = 0; i < n ; i++){
            topPrefix[i+1] = topPrefix[i] + grid[0][i];
            bottomPrefix[i+1] = bottomPrefix[i] + grid[1][i];
        }

        long long res = LLONG_MAX;
        for(int i = 0; i < n;i++){
            long long top_remaining = topPrefix[n] - topPrefix[i+1];
            long long bottom_remaining = bottomPrefix[i];

            long long player2score = max(top_remaining,bottom_remaining);
            res = min(res,player2score);
        }
        return res;
    }
};