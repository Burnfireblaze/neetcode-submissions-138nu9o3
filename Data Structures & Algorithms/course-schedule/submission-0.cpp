class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector < vector <int>> adj(numCourses);
        vector <int> indeg(numCourses, 0);
        queue <int> q;
        for(auto &p : prerequisites){
            int course = p[0]; int prereq = p[1];
            adj[prereq].push_back(course);
            indeg[course]++;
        }

        for(int i=0;i<numCourses;i++)
            if(indeg[i] == 0) q.push(i);

        int count = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();
            count++;
            for (auto nei : adj[node]) {
                if(--indeg[nei] == 0) q.push(nei);
            }
        }
        return count == numCourses;
    }
};
