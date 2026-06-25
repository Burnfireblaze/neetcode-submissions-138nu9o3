class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                vector < vector <int>> adj(numCourses);
        vector <int> indeg(numCourses, 0);
        queue <int> q;
        vector <int> res;
        for(auto &p : prerequisites){
            int course = p[0]; int prereq = p[1];
            adj[prereq].push_back(course);
            indeg[course]++;
        }

        for(int i=0;i<numCourses;i++)
            if(indeg[i] == 0){
            q.push(i);
            res.push_back(i);
            }

        while(!q.empty()){
            int node = q.front(); q.pop();
            for (auto nei : adj[node]) {
                if(--indeg[nei] == 0) {
                    res.push_back(nei);
                    q.push(nei);
                }
            }
        }
        if (res.size() != numCourses) return {};
        return res;
    }
};
