class Solution {
public:
    int compress(vector<char>& chars) {
        
        map<char,int> mp;
        int n=chars.size();
   
        string str;
        mp[chars[0]]=1;
        for(int i=1;i<chars.size();i++){
            if(mp[chars[i]]==0){
         
                str+=chars[i-1];
                if(mp[chars[i-1]]!=1){
                str+=to_string(mp[chars[i-1]]);
                }
                mp[chars[i-1]]=0;
            }
            mp[chars[i]]++;
        }
        str+=chars[n-1];
        if(mp[chars[n-1]]!=1){
            str+=to_string(mp[chars[n-1]]);
        }
    
        for(int i=0;i<str.size();i++){        
            chars[i]=str[i];
        }
   
        return str.size();
    }
};