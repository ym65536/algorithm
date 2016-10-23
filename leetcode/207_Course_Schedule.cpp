bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
{
    int visit_size = 0;
    vector<int> indegree(numCourses, 0);
    queue<int> Q;
    vector<vector<int> > G(numCourses, vector<int>());    
    
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int x = prerequisites[i].first;
        int y = prerequisites[i].second;
        G[x].push_back(y);
        indegree[y]++;
    }
    
    for (int node = 0; node < numCourses; node++)
    {
        if (indegree[node] == 0)
            Q.push(node);
    }
    
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        visit_size++;
        for (int i = 0; i < G[x].size(); i++)
        {
            int y = G[x][i];
            indegree[y]--;
            if (indegree[y] == 0)
            {
                Q.push(y);
            }
        }
    }
    
    return visit_size == numCourses;
}

