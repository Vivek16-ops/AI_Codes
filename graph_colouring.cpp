// Graph Colouring Program in C++
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
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
            cout << endl;
        }
    }

    bool isPossible(int node, int col, vector<int> &colour)
    {
        for (auto nbr : adjList[node])
        {
            if (col == colour[nbr])
            {
                return false;
            }
        }
        return true;
    }

    bool mColoured(int node, int m, vector<int> &colour)
    {
        // Base Case
        if (node == adjList.size())
        {
            return true;
        }

        for (int col = 1; col <= m; col++)
        {
            if (isPossible(node, col, colour))
            {
                colour[node] = col;
                if (mColoured(node + 1, m, colour))
                {
                    return true;
                }
                colour[node] = 0;
            }
        }
        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.printList();

    vector<int> colour(4, 0);
    if(g.mColoured(0, 3, colour)) {
        cout << "Possible to colour" << endl;
        for(int i=0; i<4; i++) {
            cout << i << " : " << colour[i] << endl;
        }
    } else {
        cout << "Not Possible!!" << endl;
    }
    return 0;
}