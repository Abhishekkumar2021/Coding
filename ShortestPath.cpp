//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    struct edge
    {
        int dest;
        int weight;
        edge(int d, int w)
        {
            dest = d;
            weight = w;
        }
    };
    void add(vector<edge> adj[], int u, int v, int w)
    {
        adj[u].push_back(edge(v, w));
    }

    void print(vector<edge> adj[], int N)
    {

        for (int i = 0; i < N; i++)
        {
            cout << i << ": ";
            for (edge &e : adj[i])
            {
                cout << "(" << e.dest << "," << e.weight << ")";
            }
            cout << endl;
        }
    }

    void dfs(vector<edge> adj[], stack<int> s, bool visited[], int u)
    {
        visited[u] = true;
        for (edge &v : adj[u])
        {
            if (visited[v.dest] == false)
            {
                dfs(adj, s, visited, v.dest);
            }
        }
        s.push(u);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<edge> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            add(adj, u, v, w);
        }

        //
        print(adj, N);
        stack<int> s;
        bool visited[N];
        vector<int> dist;
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
            dist.push_back(INT_MAX);
        }
        dist[0] = 0;
        ///*
        dfs(adj, s, visited, 0);
        //*/
        ///*
        cout << "topological sort: ";
        while (s.empty() == false)
        {
            int x = s.top();
            s.pop();
            cout << x << " ";
        }
        cout << endl;
        cout << "distance :";
        while (s.empty() == false)
        {
            int x = s.top();
            s.pop();
            for (edge &temp : adj[x])
            {
                if (dist[temp.dest] > dist[x] + temp.weight)
                {
                    dist[temp.dest] = dist[x] + temp.weight;
                }
                cout << dist[temp.dest] << " ";
            }
        }
        cout << endl;
        return dist;
        //*/
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    memset()
}

// } Driver Code Ends