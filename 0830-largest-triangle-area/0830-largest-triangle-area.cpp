class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;

        for(int i = 0; i<points.size(); i++){
            for(int j = i+1; j<points.size(); j++){
                for(int k = j+1; k<points.size(); k++){
                    double area = fabs(points[i][0] * (points[j][1] - points[k][1]) +
                    points[j][0] * (points[k][1] - points[i][1]) +
                    points[k][0] * (points[i][1] - points[j][1]))/2.0;
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};