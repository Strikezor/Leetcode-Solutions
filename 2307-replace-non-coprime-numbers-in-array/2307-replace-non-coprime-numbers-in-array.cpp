class Solution {
private:
    int gcd(int a,int b){
        return b==0 ? a : gcd(b, a % b);
    }
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int it : nums){
            while(!st.empty()){
                int top = st.back();
                int g = gcd(top,it);
                if(g == 1) break;
                st.pop_back();

                long long lcm = (long long)top/g * it;
                it = (int)lcm;
            }
            st.push_back(it);
        }
        return st;
    }
};