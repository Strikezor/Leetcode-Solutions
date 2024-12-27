int dp[50000];
class Solution {
public:
    int score = 0;
    int solve(int i, vector<int>& val){
        if(i<0) return 0;
        if(dp[i]!=0) return dp[i];
        int x = val[i], prev = solve(i-1,val);
        score = max(score, prev+x-i);
        return dp[i] = max(prev,x+i);
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        const int n = values.size();
        fill(dp,dp+n,0);
        solve(n-1,values);
        return score;
    }
};