class Solution {
public:
    bool checkAnagram(string a, string b){
        if(a.length() != b.length()) return false;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        return a==b;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        stack<string> st;
        vector<string> ans;
        st.push(words[0]);
        for(int i = 1; i<words.size(); i++){
            if(!checkAnagram(st.top(),words[i])) st.push(words[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};