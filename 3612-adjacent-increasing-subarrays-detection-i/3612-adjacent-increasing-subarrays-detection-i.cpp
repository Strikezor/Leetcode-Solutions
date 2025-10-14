class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev = 0;
        int curr = 1;
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(nums[i-1] < nums[i]) curr++;
            else {
                prev = curr;
                curr =1;
            }
            if((curr>=k && prev >= k) || curr == k * 2) return true;
        }
        return false;
    }
};