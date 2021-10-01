#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void traverse(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << ": ";
        for (auto u : adj[i])
        {
            cout << u << " ";
        }

        cout << endl;
    }
}

bool dfs_rec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for (auto a : adj[s])
    {
        if (visited[a] == false)
        {
            if (dfs_rec(adj, a, visited, s) == true)
                return true;
        }

        else if (a != parent)
            return true;
    }

    return false;
}

void detect(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    bool flag = dfs_rec(adj, s, visited, -1);

    cout << flag;
}

int main()
{
    int v = 4;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);
    addEdge(adj, 1, 3);

    //traverse(adj, v);
    detect(adj, v, 0);
}