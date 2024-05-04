class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto &a:asteroids){
            bool survive = true;
            while(!res.empty() && res.back()>0 && a<0){
                if(res.back() + a<0) res.pop_back();
                else if(res.back() + a>0){
                    survive = false; 
                    break;
                }
                else{
                    res.pop_back();
                    survive = false;
                    break;
                }
            }
            if(survive) res.push_back(a);
        }
        return res;
    }
};