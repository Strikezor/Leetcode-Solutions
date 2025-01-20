class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<int> row(mat.size(),0);
        vector<int> col(mat[0].size(),0);
        unordered_map<int,pair<int,int>> mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<arr.size();i++){
            row[mp[arr[i]].first]++;
            col[mp[arr[i]].second]++;
            if(row[mp[arr[i]].first]==mat[0].size()||col[mp[arr[i]].second]==mat.size()){
                return i;
            }
        }
        return 0;
    }
};