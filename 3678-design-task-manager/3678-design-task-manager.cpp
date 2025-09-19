class TaskManager {
public: 
    unordered_map<int,pair<int,int>> mp;
    priority_queue<tuple<int,int,int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it: tasks){
            int user = it[0], taskId = it[1], priority = it[2];
            mp[taskId] = {user,priority};
            pq.emplace(priority,taskId,user);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId,priority};
        pq.emplace(priority,taskId,userId);
    }
    
    void edit(int taskId, int newPriority) {
        auto [user,_] = mp[taskId];
        mp[taskId] = {user, newPriority};
        pq.emplace(newPriority,taskId,user);
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [pri,task,user] = pq.top();
            if(!mp.count(task)){
                pq.pop();
                continue;
            }
            auto [currUser,currPri] = mp[task];
            if(currPri!=pri){
                pq.pop();
                continue;
            }

            pq.pop();
            mp.erase(task);
            return user;
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */