class Solution {    
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    bool doesAliceWin(string s) {
        for(char ch : s){
            if(isVowel(ch)) return true;
        }
        return false;
    }
};