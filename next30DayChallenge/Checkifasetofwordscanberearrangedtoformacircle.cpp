#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define CHAR_SIZE 128
 
class Graph
{
public:
 
    vector<vector<int>> adjList;
 
    Graph(int n)
    {
        // resize the vector to hold `n` elements
        adjList.resize(n);
    }
 
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
};
 
void DFS(Graph const &graph, int u, vector<bool> &visited)
{
    // mark the current node as visited
    visited[u] = true;
 
    // do for every edge (u, v)
    for (int v: graph.adjList[u])
    {
        // recur if `v` is not visited
        if (!visited[v]) {
            DFS(graph, v, visited);
        }
    }
}
 
Graph transpose(Graph const &graph, int n)
{
    Graph g(n);
 
    // for every edge (u, v), create a reverse edge (v, u)
    for (int u = 0; u < n; u++)
    {
        for (int v: graph.adjList[u]) {
            g.addEdge(v, u);
        }
    }
    return g;
}
 
bool isVisited(Graph const &graph, const vector<bool> &visited)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (graph.adjList[i].size() && !visited[i]) {
            return false;
        }
    }
    return true;
}
 
bool isSC(Graph const &graph, int n)
{
    vector<bool> visited(n);
 
    int i;
    for (i = 0; i < n; i++)
    {
        if (graph.adjList[i].size())
        {
            DFS(graph, i, visited);
            break;
        }
    }
 
    if (!isVisited(graph, visited)) {
        return false;
    }
 
    fill(visited.begin(), visited.end(), false);
 
    Graph g = transpose(graph, n);
 
    DFS(g, i, visited);
 
    return isVisited(g, visited);
}
bool checkArrangement(vector<string> const &words)
{
    Graph graph(CHAR_SIZE);
 
    vector<int> in(CHAR_SIZE);
    for (const string &s: words)
    {
        int src = s.front();
        int dest = s.back();
        graph.addEdge(src, dest);
 
        in[dest]++;
    }
 
    for (int i = 0; i < CHAR_SIZE; i++)
    {
        if (graph.adjList[i].size() != in[i]) {
            return false;
        }
    }
    return isSC(graph, CHAR_SIZE);
}
 
int main()
{
    vector<string> words = {
        "ANT", "OSTRICH", "DEER", "TURKEY", "KANGAROO",
        "TIGER", "RABBIT", "RAT", "TOAD", "YAK", "HYENA"
    };
 
    if (checkArrangement(words)) {
        cout << "The given words can be rearranged";
    }
    else {
        cout << "The given words cannot be rearranged";
    }
 
    return 0;
}
