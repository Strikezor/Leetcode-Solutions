class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> results;
        unordered_set<int> colours;
        unordered_map<int, int> balls; 
        unordered_map<int, int> colourCount; 
        
        for (auto q : queries) {
            int first = q[0], second = q[1];
            
            if (balls.find(first) == balls.end()) { 
                balls[first] = second;
                colours.insert(second);
                colourCount[second]++;  
            }
            else {
                int old_colour = balls[first]; 
                
                if (old_colour != second) {
                    colourCount[old_colour]--; 
                    
                    if (colourCount[old_colour] == 0) {
                        colours.erase(old_colour); 
                    }

                    colours.insert(second); 
                    balls[first] = second;  
                    colourCount[second]++;  
                }
            }
            
            results.push_back(colours.size());  
        }
        
        return results;
    }
};