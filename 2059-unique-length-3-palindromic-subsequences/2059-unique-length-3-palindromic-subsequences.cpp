class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string> ans;
        unordered_set<char> left;
        vector<int> right(26,0);

        for(char ch:s){
            right[ch-'a']++;
        }
        for(int i = 0; i< s.length(); i++){
            right[s[i]-'a']--;
            if(right[s[i]-'a']==0) right[s[i]-'a'] = -1;
            for(int j = 0; j<26; j++){
                char ch = 'a'+j;
                if(left.count(ch) && right[j]>0){
                    ans.insert(string()+s[i]+ch);
                }
            }
            left.insert(s[i]);
        }
        return ans.size();
    }
};