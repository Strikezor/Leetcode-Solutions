class Solution {
public:
    int solve(vector<int> &e, int start, int jumps, vector<int> & dp){
        if(start >= e.size()) return 0;
        if(dp[start]!= -1) return dp[start];

        return dp[start] = e[start] + solve(e,start+jumps, jumps,dp);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int ans = INT_MIN;
        int n = energy.size();
        vector<int> dp(n,-1);
        for(int i = 0; i<n; i++){
            ans = max(ans,solve(energy,i, k, dp));
        }
        return ans;
    }
};