// Implementing the DFS using CPP
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> adjList;

public:
    void addAdges(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printList()
    {
        for (auto val : adjList)
        {
            cout << val.first << "-> ";
            for (auto neighbour : val.second)
            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }

    void dfs(int src, unordered_map<int, bool> &visited)
    {
        visited[src] = true;

        cout << src << " ";

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of Nodes: " << endl;
    cin >> n;
    Graph g;
    g.addAdges(0, 1);
    g.addAdges(0, 2);
    g.addAdges(2, 3);
    g.addAdges(1, 4);

    g.printList();

    unordered_map<int, bool> visisted;
    for (int i = 0; i < n; i++)
    {
        if (!visisted[i])
        {
            g.dfs(i, visisted);
        }
    }
    return 0;
}