// Implementing BFS in C++
#include <iostream>
#include <unordered_map>
#include <queue>
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
        cout << "Printing List" << endl;
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

    void bfs(int src, unordered_map<int, bool> &visited)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            cout << top << " ";

            for (auto neighbour : adjList[top])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout << endl;
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
            g.bfs(i, visisted);
        }
    }
    return 0;
}