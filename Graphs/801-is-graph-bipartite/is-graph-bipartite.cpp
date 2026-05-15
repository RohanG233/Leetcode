class Solution {
public:
bool res = true;
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);

        for(int i=0;i<n;i++)
        {
            if(colors[i] == -1)
            {
                dfs(graph, i, 0, colors);
            }
        }
        return res;
    }

    void dfs(vector<vector<int>> &graph, int node, int c, vector<int> &colors)
    {
        colors[node] = c;

        for(auto it : graph[node])
        {
            if(colors[it] != -1 && colors[it] == c)
            {
                res = false;
            }
            if(colors[it] == -1)
            {
                dfs(graph, it, 1-c, colors);
            }
        }
        return;
    }
};