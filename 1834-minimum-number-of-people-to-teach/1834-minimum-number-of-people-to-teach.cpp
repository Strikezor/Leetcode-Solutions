class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> need;
        for(auto it: friendships){
            int u = it[0] - 1,v = it[1] -1;
            bool flag = false;
            for(int x : languages[u]){
                for(int y : languages[v]){
                    if(x==y){
                        flag = true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag){
                need.insert(u); 
                need.insert(v);
            }
        }

        int res = languages.size() + 1;
        for(int i = 1; i<=n; i++){
            int cnt = 0;
            for(int v: need){
                bool found = false;
                for(int c : languages[v]){
                    if(c == i) {
                        found = true;
                        break;
                    }
                }
                if(!found) ++cnt;
            }
            res = min(res,cnt);
        }
        return res;
    }
};