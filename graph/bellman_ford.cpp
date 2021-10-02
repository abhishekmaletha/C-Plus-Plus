// A C++ program for Bellman-Ford's single source
// The Bellman–Ford algorithm is an algorithm that
// computes shortest paths from a single source vertex
// to all of the other vertices in a weighted digraph.
#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void addEdge(vector<pair<pair<int, int>, int>> &V, int a, int b, int w)
{
    // if there is an edge from a to b with weight w
    // then {{a,b},w} represents it.
    V.push_back({{a, b}, w});
}
void bellman_ford(vector<pair<pair<int, int>, int>> &Graph, int v, int e, int s)
{
    vector<int> distance(v, INT_MAX);
    distance[s] = 0;
    // initializes distances from the source to all
    // vertices as infinite and distance to the source itself as 0
    // We iterate through all the edges vertices - 1 times
    // Every time we analyze an edge such that a -> (w) -> b
    // which implies an edge from a to b with weight w
    // if distance of a from source plus weight of the edge is lesser than distance of b from source
    // we relax it
    // if (distance[a] != infinity && distance[a] + w < distance[b])
    // then: distance[b] = distance[a] + w;
    for (int i = 0; i < v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int src = Graph[j].first.first;
            int des = Graph[j].first.second;
            int weight = Graph[j].second;
            if (distance[src] != INT_MAX && distance[src] + weight < distance[des])
            {
                distance[des] = distance[src] + weight;
            }
        }
    }
    // Checking negative weight edges having a cycle
    // if we get shorter path even after vertices-1 iterations
    // then we conclude that there is a negative weight edge cycle in the graph.
    for (int j = 0; j < e; j++)
    {
        int src = Graph[j].first.first;
        int des = Graph[j].first.second;
        int weight = Graph[j].second;
        if (distance[src] != INT_MAX && distance[src] + weight < distance[des])
        {
            cout << "Graph contains negative weight edge cycle" << endl;
        }
    }
    cout << "Distances of vertices from sources vertex " << s << " is:\n";
    for (int i = 0; i < v; i++)
        cout << i << "\t\t" << distance[i] << endl;
}
int main()
{
    int vertices = 0, edges = 0;
    cout << "enter number of vertices\n";
    cin >> vertices;
    cout << "enter number of edges\n";
    cin >> edges;
    // creating graph
    vector<pair<pair<int, int>, int>> Graph;
    for (int i = 0; i < edges; i++)
    {
        // taking input for edges
        cout << "enter source destination weight\n";
        int a, b, w;
        cin >> a >> b >> w;
        addEdge(Graph, a, b, w);
    }
    int s;
    cout << "enter the source node\n";
    cin >> s;
    // invoking bellman_ford
    bellman_ford(Graph, vertices, edges, s);
    cout << endl;
    return 0;
}
