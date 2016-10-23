
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
{
    vector<int> result;
    vector<int> indegree(numCourses, 0);
    queue<int> Q;
    vector<vector<int> > G(numCourses, vector<int>());    
    
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int x = prerequisites[i].first;
        int y = prerequisites[i].second;
        G[y].push_back(x);
        indegree[x]++;
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
        result.push_back(x);
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
    if (result.size() < numCourses)
        result.clear();
        
    return result;    
}
