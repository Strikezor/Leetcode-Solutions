class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double minCost = DBL_MAX;
        double qualityTilNow = 0;

        vector<pair<double,int>> wageQualityRatio;
        for(int i=0;i<n;i++){
            wageQualityRatio.emplace_back(static_cast<double>(wage[i])/quality[i],quality[i]);
        }
        sort(wageQualityRatio.begin(),wageQualityRatio.end());

        priority_queue<int> highQualityWorkers;

        for(int i=0;i<n;i++){
            double ratio = wageQualityRatio[i].first;
            int qty = wageQualityRatio[i].second;

            qualityTilNow += qty;
            highQualityWorkers.push(qty);

            if(highQualityWorkers.size() > k){
                qualityTilNow -= highQualityWorkers.top();
                highQualityWorkers.pop();
            }

            if(highQualityWorkers.size() ==k){
                minCost = min(minCost, qualityTilNow * ratio);
            }
        }
        return minCost;
    }
};