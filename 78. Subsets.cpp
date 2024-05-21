class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res={{}};

        for(int it:nums){
            int size = res.size();
            for(int i=0;i<size;i++){
                vector<int> subset = res[i];
                subset.push_back(it);
                res.push_back(subset);
            }
        }
        return res;
    }
};