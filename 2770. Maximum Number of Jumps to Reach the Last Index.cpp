class Solution {
public:
    int helper(vector<int>& nums, int n, int target,int i,vector<int>& dp){
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];

        int ans = -1e4;
        for(int j=i+1;j<n;j++){
            if(abs(nums[j]-nums[i])<=target){
                ans = max(ans, 1+helper(nums,n,target,j,dp));
            }
        }
        return dp[i]=ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,-1);
        int ans = helper(nums,n,target,0,dp);
        if(ans<0) return -1;
        return ans;
    }
};