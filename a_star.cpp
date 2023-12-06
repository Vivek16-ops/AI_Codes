#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printList()
    {
        for (auto val : adjList)
        {
            cout << val.first << "-> ";
            for (auto nbr : val.second)
            {
                cout << nbr << " ";
            }
            cout<<endl;
        }
    }

    vector<int> astar(int src, unordered_map<int, bool> &viisted, int nodes)
    {
        vector<int> path;
        priority_queue<int, vector<int>, greater<int>> minheap;
        minheap.push(src);
        viisted[src]=true;
        while (!minheap.empty())
        {
            int top = minheap.top();
            minheap.pop();

            path.push_back(top);
            for (auto nbr : adjList[top])
            {
                if (!viisted[nbr])
                {
                    viisted[nbr] = true;
                    minheap.push(nbr);
                }
            }
        }
        cout << path[0] << " ";
        for (int i = 1; i < path.size(); i+=2)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.printList();
    unordered_map<int,bool>visited;
    for (int i = 0; i < 6; i++)
    {
        if (!visited[i])
        {
            g.astar(i,visited,6);
        }
    }
    return 0;
}