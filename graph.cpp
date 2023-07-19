#include <iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <set>
#include<vector>
#include<queue>

class graph
{

public:
    unordered_map<int, list<int> > adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }

            cout << endl;
        }
    }

   
};

 void BFS(unordered_map<int, list<int> > adj, vector<int> &ans, unordered_map<int, bool> &visited, int node)
    {
        queue<int> q;
        q.push(node);
        visited[node] = 1;

        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto i:adj[frontNode])
            {
                if(!visited[i])
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    // Time Complexity: O(V+E)
    // Where V is the number of vertices and E is the number of edges in the graph.

    // Space Complexity: O(V)
    // We used an array(ans) of size V to store the BFS traversal. 
    // We also used an array of size V to keep track of visited vertices. 
    // We used a queue of size V to store the vertices.

    void DFS(unordered_map<int, list<int> > adj, vector<int> &ans, unordered_map<int, bool> &visited, int node)
    {
        visited[node] = 1;

        ans.push_back(node);

        for(auto i : adj[node])
        {
            if(!visited[i])
                DFS(adj, ans, visited, i);
        }

    }

    // Time complexity: O(V + E), where V is the number of vertices and E is 
    //                  the number of edges in the graph.
    // Auxiliary Space: O(V), since an extra visited array of size V is required.

void printBFS(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }cout<<endl;
    
}

void printEdges(vector<pair<int, int> > &edges)
{
    for(auto i:edges)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{

    int n;
    cout << "Enter the no. of nodes/vertices : " << endl;
    cin >> n;

    int e;
    cout << "Enter the no. of edges : " << endl;
    cin >> e;

    vector<int> ans;
    pair<int, int> p;
    vector<pair<int, int>> edges;
    unordered_map<int, bool> visited;

    graph g;

    cout << "Enter edges : " << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        p.first = u;
        p.second = v;

        edges.push_back(p);

        g.addEdge(u, v, 0);
    }

    cout << "\nAdjecency list : " << endl;
    g.printAdjList();


    // BFS FUNCTION CALL

    for (int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            BFS(g.adj,ans, visited, i);
        }
    }

    cout << "\n BFS Traversal : " << endl;
    printBFS(ans);


    // DFS FUNCTION CALL
    // DFS(g.adj, ans, visited, 6);
    // cout << "\nDFS Traversal : " << endl;
    // printBFS(ans);
    

    return 0;
}

//  1- 2-3
// / \/\/\  
// 4-5-6- 7

// Difference between BFS and DFS ? Which one is better?
// Also discuss in terms of time and space complexity. 

// =>

// BFS is better when target is closer to Source.
// BFS requires more memory space.

// DFS is better when target is far from source.
// DFS requires less memory space.