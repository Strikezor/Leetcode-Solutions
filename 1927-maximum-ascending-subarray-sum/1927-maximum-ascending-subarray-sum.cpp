class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int count = nums[0];
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                count += nums[i];
            }
            else{
                count = nums[i];
            }
            ans = max(ans,count);
        }
        return ans;
    }
};