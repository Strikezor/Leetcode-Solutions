class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0,end = 0,cnt=0,maxLen=0;
        while(end<nums.size() && start<=end){
            if(nums[end]==0){
                cnt++;
            }
            while(cnt>k && start<=end){
                if(nums[start]==0){
                    cnt--;
                }
                start++;
            }
            maxLen= max(maxLen,end-start+1);
            end++;
        }
        return maxLen;
    }
};