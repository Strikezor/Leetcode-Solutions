class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.length();
        string ans;
        for(char ch:s){
            ans.push_back(ch);
            while(ans.find(part)<ans.length()){
                for(int i = 0; i<n; i++){
                    ans.pop_back();
                }
            }
        }
        return ans;
    }
};