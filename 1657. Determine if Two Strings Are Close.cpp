class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1=word1.length();
        int l2=word2.length();
        if(l1!=l2) return false;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(auto it:word2) mp1[it]++;
        for(auto it:word1) 
        {
            if(mp1.find(it)==mp1.end()) return false;
            mp2[it]++;
        }

        vector<int> v1,v2;
        for(auto it: mp1)
        {
            v1.push_back(it.second);
        }
        for(auto it: mp2)
        {
            v2.push_back(it.second);
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());

        
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i]) return false;
        }

        return true;
    }
};