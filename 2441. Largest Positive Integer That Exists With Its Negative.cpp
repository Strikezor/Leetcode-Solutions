class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        int ans = -1;
        for(auto it: st){
            if(it>0){
                if(st.find(-it)!=st.end()){
                    ans = max(ans,it);
                }
            }
        }
        return ans;

    }
};