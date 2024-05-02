class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    int maxVowels(string s, int k) {
        double ans = INT_MIN;
        int start = 0,end = 0;
        double cnt = 0;
        while(end<s.size()){
            if(isVowel(s[end])){
                cnt++;
            }
            if(end-start+1 == k){
                ans = max(ans, cnt);
                if(isVowel(s[start])){
                    cnt--;
                }
                start++;
            }
            end++;
        }
        return ans;
    }
};