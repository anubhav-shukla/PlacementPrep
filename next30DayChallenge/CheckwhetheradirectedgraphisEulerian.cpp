#include <iostream>
#include <vector>
using namespace std;
 
struct Edge {
    int src, dest;
};
 
class Graph
{
public:
    vector<vector<int>> adjList;
 
    vector<int> in;
 
    // Constructor
    Graph(int n)
    {
        adjList.resize(n);
        in.resize(n);
    }
 
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        in[v]++;
    }
};
 
void DFS(Graph const &graph, int u, vector<bool> &visited)
{
    visited[u] = true;
 
    for (int v: graph.adjList[u])
    {
        if (!visited[v]) {
            DFS(graph, v, visited);
        }
    }
}
 
Graph getUndirectedGraph(Graph const &graph, int n)
{
    Graph g(n);
 
    for (int u = 0; u < n; u++)
    {
        for (int v: graph.adjList[u])
        {
            g.addEdge(v, u);
            g.addEdge(u, v);
        }
    }
    return g;
}
 
bool isConnected(Graph const &graph, int n)
{
    vector<bool> visited(n);
 
    for (int i = 0; i < n; i++)
    {
        if (graph.adjList[i].size())
        {
            DFS(graph, i, visited);
            break;
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph.adjList[i].size() > 0) {
            return false;
        }
    }
 
    return true;
}
 
bool hasEulerPath(Graph const &graph, int n)
{
   
 
    bool x = false, y = false;
    for (int i = 0; i < n; i++)
    {
        int out_degree = graph.adjList[i].size();
        int in_degree = graph.in[i];
 
        if (out_degree != in_degree)
        {
            if (!x && out_degree - in_degree == 1) {
                x = true;
            }
            else if (!y && in_degree - out_degree == 1) {
                y = true;
            }
            else {
                return false;
            }
        }
    }
 
    return isConnected(getUndirectedGraph(graph, n), n);
}
 
int main()
{
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}, {1, 4},
        {4, 3}, {3, 0}, {0, 5}, {5, 4}
    };
 
    int n = 6;
 
    Graph graph(n);
 
    for (auto &edge: edges) {
        graph.addEdge(edge.src, edge.dest);
    }
 
    if (hasEulerPath(graph, n)) {
        cout << "The graph has an Eulerian path" << endl;
    }
    else {
        cout << "The Graph doesn't have an Eulerian path" << endl;
    }
 
    return 0;
}
