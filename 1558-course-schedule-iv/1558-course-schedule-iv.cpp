class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adjList;
       
        vector<int> indegree(numCourses, 0);
        for (auto edge : prerequisites) {
            adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> nodePre;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adj : adjList[node]) {
                nodePre[adj].insert(node);
                for (auto pre : nodePre[node]) {
                    nodePre[adj].insert(pre);
                }
                indegree[adj]--;
                if (!indegree[adj]) {
                    q.push(adj);
                }
            }
        }

        vector<bool> ans;
        for (auto q : queries) {
            ans.push_back(nodePre[q[1]].contains(q[0]));
        }
        return ans;
    }
};