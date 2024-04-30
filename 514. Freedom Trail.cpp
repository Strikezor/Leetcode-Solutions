class Solution {
public:
    unordered_map<char, vector<int>> index;
    int find(int i, string& key, string &ring, int j, vector<vector<int>> & dp){
        if(i>=key.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        char curr = key[i];
        int ans =  INT_MAX;

        for(int it: index[curr]){
            int left = abs(it-j);
            int right = ring.size()- left;

            ans = min(ans,min(left,right) + find(i+1,key,ring,it,dp));
        }
        return dp[i][j] = 1+ans;
    }
    int findRotateSteps(string ring, string key) {
        int m = key.size(),n = ring.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<n;i++){
            index[ring[i]].push_back(i);
        }
        return find(0,key,ring,0,dp);
    }
};