class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans, indegree(numCourses);
        // adjacency list
        vector<vector<int>> adj(numCourses);
        queue<int> q;

        // calculating indegree and forming adjacency list
        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }

        // push all nodes with indegree 0
        // push all courses with  no pre-req
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            // since curr has no pre-req, take it
            ans.push_back(curr);
            
            for(auto nextCourse: adj[curr]) {
                // reduce indegree of all adj nodes
                indegree[nextCourse]--;
                // if there is a next course with 0 pre-req remaining
                // then we can take it
                if(indegree[nextCourse] == 0) q.push(nextCourse);
            } 
        }

        
        if (ans.size() == numCourses) return ans;
        
        // if all courses cant be taken then return {}
        return {};
    }
};