class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int totalSum = 0;
        for(int it: nums) totalSum |= it;

        return totalSum << (nums.size()-1);
    }
};