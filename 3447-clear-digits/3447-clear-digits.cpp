class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto it:s){
            if(it>='a' && it<='z'){
                st.push(it);
            }
            if(it>='0' && it<='9' && st.top()>='a' && st.top()<='z'){
                st.pop();
            }
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};