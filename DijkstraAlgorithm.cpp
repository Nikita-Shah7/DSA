//
//      2 --------- 4
//     /|         / |\ 
//    / |       /   | \
//   1  |     /     |  6
//    \ |   /       | /
//     \| /         |/
//      3 --------- 5
//

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int e;
    int v;
    vector<vector<pair<int, int>>> adjacency_list;
    void bfs();
    void dfs();
    void printPath(int, vector<int> &);
    void Dijkstra(int);

public:
    Graph(int, int);
    void addEdge(int, int, int);
    void Display();
};

Graph ::Graph(int ver, int edg)
{
    e = edg;
    v = ver;
    adjacency_list.resize(ver + 1);
}

void Graph ::addEdge(int u, int v, int wt)
{
    adjacency_list[u].push_back({wt, v});
    adjacency_list[v].push_back({wt, u});
}

void Graph ::bfs()
{
    bool visit[v];
    queue<int> q;
    // we begin from node with 1 index
    int startInd = 1;
    q.push(startInd);
    visit[startInd] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";

        for (auto x : adjacency_list[curr])
        {
            if (!visit[x.second])
            {
                q.push(x.second);
                visit[x.second] = 1;
            }
        }
    }
}

void Graph ::dfs()
{
    vector<bool> visit(v, 0);
    vector<bool> inStack(v, 0);
    stack<int> st;
    // we begin with index 1
    int startInd = 1;
    st.push(startInd);
    inStack[startInd] = 1;
    while (!st.empty())
    {
        int curr = st.top();
        bool flag = 0;
        for (auto x : adjacency_list[curr])
        {
            if (x.second != curr && !inStack[x.second])
            {
                st.push(x.second);
                inStack[x.second] = 1;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << curr << " ";
            visit[curr] = 1;
            st.pop();
            inStack[curr] = 1;
        }
    }
}

void Graph::printPath(int s, vector<int> &p)
{
    if (s == -1)
        return;
    printPath(p[s], p);
    cout << s << " ";
}

void Graph ::Dijkstra(int src)
{
    // minHeap {distanceLabel,nodeIndex}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> parent(v + 1, -1);
    vector<int> dist(v + 1, 1000000009);
    vector<bool> visit(v + 1, 0);
    pq.push({0, src}); // distance label of src vertex = 0
    dist[src] = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        if (visit[top.second])
            continue;
        visit[top.second] = 1;
        for (auto x : adjacency_list[top.second])
        {
            if (dist[top.second] + x.first < dist[x.second])
            {
                dist[x.second] = dist[top.second] + x.first;
                parent[x.second] = top.second;
                pq.push(make_pair(dist[x.second], x.second));
            }
        }
    }
    cout << "FRO --> TO   DISTANCE   PATH\n";
    for (int i = 1; i <= v; i++)
    {
        if (i != src)
        {
            cout << src << "  --->  " << i << "\t" << dist[i] << "\t";
            printPath(i, parent);
            cout << endl;
        }
    }
}

void Graph ::Display()
{
    for (int i = 1; i <= v; i++)
    {
        cout << i << " -> ";
        for (auto y : adjacency_list[i])
            cout << y.second << " ; ";
        cout << endl;
    }
    cout << "\nBFS :: ";
    bfs();
    cout << "\nDFS :: ";
    dfs();
    cout << "\n\nDijkstra's shortest path algorithm ::\n";
    for (int i = 1; i <= v; i++)
        Dijkstra(i);
}

int main()
{
    // Graph g1(5, 5);
    // g1.addEdge(1, 5);
    // g1.addEdge(5, 3);
    // g1.addEdge(5, 2);
    // g1.addEdge(2, 1);
    // g1.addEdge(3, 4);
    // g1.Display();

    // Graph g2(10, 11);
    // g2.addEdge(3, 5);
    // g2.addEdge(1, 2);
    // g2.addEdge(2, 3);
    // g2.addEdge(4, 7);
    // g2.addEdge(7, 8);
    // g2.addEdge(3, 4);
    // g2.addEdge(5, 6);
    // g2.addEdge(4, 6);
    // g2.addEdge(5, 9);
    // g2.addEdge(6, 10);
    // g2.addEdge(9, 10);
    // g2.Display();

    Graph g3(6, 9);
    g3.addEdge(1, 2, 7);
    g3.addEdge(1, 3, 8);
    g3.addEdge(2, 3, 3);
    g3.addEdge(2, 4, 6);
    g3.addEdge(4, 5, 2);
    g3.addEdge(3, 5, 3);
    g3.addEdge(3, 4, 4);
    g3.addEdge(6, 5, 2);
    g3.addEdge(4, 6, 5);
    g3.Display();

    return 0;
}