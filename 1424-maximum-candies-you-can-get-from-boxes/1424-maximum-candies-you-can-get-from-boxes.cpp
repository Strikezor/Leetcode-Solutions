class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> visited(n);
        vector<int> processing;
        unordered_set<int> lockedBoxes;

        for(int box : initialBoxes){
            if(status[box] == 1){
                visited[box] = true;
                processing.push_back(box);
            }
            else{
                lockedBoxes.insert(box);
            }
        }
        int res = 0;

        while(!processing.empty()){
            int curr = processing.back();
            processing.pop_back();
            res += candies[curr];

            for(int key: keys[curr]){
                status[key] = 1;
                if(lockedBoxes.find(key) != lockedBoxes.end()){
                    visited[key] = true;
                    lockedBoxes.erase(key);
                    processing.push_back(key);
                }
            }
            for(int box : containedBoxes[curr]){
                if(visited[box]) continue;
                if(status[box]==1){
                    processing.push_back(box);
                    visited[box]=true;
                }
                else{
                    lockedBoxes.insert(box);
                }
            }
        }
        return res;
    }
};