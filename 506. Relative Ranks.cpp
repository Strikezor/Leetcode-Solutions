class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }

        vector<string> rank(n);
        int place = 1;
        while(!pq.empty()){
            int idx = pq.top().second;
            pq.pop();
            switch(place){
                case 1: rank[idx]="Gold Medal"; break;
                case 2: rank[idx]="Silver Medal"; break;
                case 3: rank[idx]="Bronze Medal"; break;
                default: rank[idx]=to_string(place); break;
            }
            place++;
        }
        return rank;
    }
};