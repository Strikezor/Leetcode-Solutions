class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<=2)return false;
        int left=INT_MAX,mid=INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid) return true;
            else if(left<nums[i] && nums[i]<mid) mid = nums[i];
            else if(nums[i]<left) left = nums[i];
        }
        return false;
    }
};