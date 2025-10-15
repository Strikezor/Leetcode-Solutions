class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return n;

        vector<int> end(n,1),start(n,1);

        for(int i = 1; i<n; ++i){
            if(nums[i] > nums[i-1]) end[i] = end[i-1] + 1;
        }

        for(int i = n-2; i>=0; --i){
            if(nums[i] < nums[i+1]) start[i] = start[i+1] + 1;
        }

        int ans = 1;

        for(int i = 0; i+1 < n; ++i){
            ans = max(ans,min(end[i], start[i+1]));
        }
        return ans;
    }
};