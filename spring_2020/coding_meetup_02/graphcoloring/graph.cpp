/// @author Benjamin Alcocer

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

///-----------------------------------------------------------------------------
/// Breadth-first-search function for a vector of ints. This function finds
/// the level of the last node minus 1 for the Graph problem.
///
/// @source: GeeksforGeeks
/// https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
///-----------------------------------------------------------------------------
int bfs(int s, const vector<list<int>>& adjList)
{
    int reach = adjList.size();

    // Mark all the vertices as not visited
    vector<bool> visited(adjList.size(), false);

    // to avoid setting the same level more than once, we use
    // reach + 1 as an inf
    vector<int> level(adjList.size(), reach + 1);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;

    level[0] = 0;
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it 
        s = queue.front();
        queue.pop_front();

        for (auto i = adjList[s].begin(); i != adjList[s].end(); i++)
        {
            if (level[*i] == reach + 1)
            {
                level[*i] = level[s] + 1;
                queue.push_back(*i);
            }
        }
    }

    return level.back() - 1;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    vector<list<int>> graph(n);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    cout << bfs(0, graph) << endl;

    return 0;
}
