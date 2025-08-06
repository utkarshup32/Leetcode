class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            graph[b].push_back(a);
            indegree[a]++;
        }
     
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }
        //step3 process queue
        int count = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            //we find dependent neighbour
        for(int j = 0; j < graph[curr].size(); j++)
        {
            int neighbour = graph[curr][j];
            indegree[neighbour]--;

            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    //step 4 all course is completed
    return count == numCourses;
    }
};