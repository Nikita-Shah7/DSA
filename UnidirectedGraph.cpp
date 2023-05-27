// index ---> (index,weight)
// 1 ---> (2,7) -> (3,8)
// 2 ---> (1,7) -> (3,3) -> (4,6)
// 3 ---> (1,8) -> (2,3) -> (4,4) -> (5,3)
// 4 ---> (2,6) -> (3,4) -> (5,2) -> (6,5)
// 5 ---> (3,3) -> (4,2) -> (6,2)
// 6 ---> (4,5) -> (5,2)

//           6
//      2 --------- 4
//   7 /|         / |\ 5
//    / |3      /   | \
//   1  |   4 /     |  6
//    \ |   /     2 | / 2
//   8 \| /         |/
//      3 --------- 5
//           3

#include <bits/stdc++.h>
using namespace std;

class Node
{
    int index;
    char data;
    int weight;
    bool visited;
    int degree;

public:
    Node(char);
    friend class Graph;
};

Node ::Node(char ch)
{
    index = 0;
    data = ch;
    // visited = 0;
    weight = 0;
    degree = 0;
}

class Graph
{
    int e;
    int v;
    vector<list<Node *>> adjacency_list;
    void displayNodes();
    void getOtherDetailsFromData(Node *&);
    int getOtherDetailsFromIndex(int);
    void bfs();
    void dfs();

public:
    Graph(int, int);
    void create();
    void Display();
    void Destroy();
};

Graph ::Graph(int edg, int ver)
{
    e = edg;
    v = ver;
    adjacency_list.resize(ver);
}

void Graph ::getOtherDetailsFromData(Node *&ptr)
{
    for (auto &list : adjacency_list)
    {
        Node *head = list.front();
        if (!list.empty())
        {
            if (head->data == ptr->data)
            {
                ptr->index = head->index;
                ptr->degree = head->degree;
                head = NULL;
                return;
            }
        }
        head = NULL;
    }
}

int Graph ::getOtherDetailsFromIndex(int i)
{
    for (auto &list : adjacency_list)
    {
        Node *head = list.front();
        if (!list.empty())
        {
            if (head->index == i)
                return head->data;
        }
        head = NULL;
    }
    return 0;
}

//  edge from a to a has weight = 0
// there can be more than one edges for a given pair of nodes
// weight of edge from a to b and from b to a can be different
void Graph ::create()
{
    cout << "\nEnter Details of all vertices : ";
    for (int i = 0; i < v; i++)
    {
        char val;
        cout << "\nVertex " << i << " :: ";
        cout << "\nData : ";
        cin >> val;
        Node *newNode = new Node(val);
        cout << "Degree of this vertex : ";
        cin >> newNode->degree;
        newNode->index = i;
        adjacency_list[i].push_back(newNode);
    }
    displayNodes();
    cout << endl;
    int i = 0;
    for (auto &list : adjacency_list)
    {
        Node *head = list.front();
        int k = head->degree;
        cout << "\nEnter details for Vertex " << i << " :: ";
        for (int j = 0; j < k; j++)
        {
            char ch;
            int w;
            cout << "\n\tAdjacent vertex " << j + 1 << " : ";
            cout << "\n\tData : ";
            cin >> ch;
            cout << "\tWeight of the edge connecting this vertex to vertex " << j + 1 << " : ";
            cin >> w;
            Node *newNode = new Node(ch);
            getOtherDetailsFromData(newNode);
            newNode->weight = w;
            adjacency_list[i].push_back(newNode);
            // cout<<newNode->index<<endl<<newNode->data<<endl<<newNode->weight<<endl<<newNode->noOfAdjNodes<<endl;
            newNode = NULL;
        }
        i++;
        head = NULL;
    }
}

void Graph ::bfs()
{
    bool visit[v];
    queue<int> q;
    // we begin from node with 0 index
    int startInd = 0;
    q.push(startInd);
    visit[startInd] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        char val = getOtherDetailsFromIndex(curr);
        cout << "(" << curr << "," << val << ") ";

        for (Node *node : adjacency_list[curr])
        {
            if (!visit[node->index])
            {
                q.push(node->index);
                visit[node->index] = 1;
            }
        }
    }
}

void Graph ::dfs()
{
    vector<bool> visit(v, 0);
    vector<bool> inStack(v, 0);
    stack<int> st;
    // we begin with index 0
    int startInd = 0;
    st.push(startInd);
    inStack[startInd] = 1;
    while (!st.empty())
    {
        int curr = st.top();
        bool flag = 0;
        for (auto &node : adjacency_list[curr])
        {
            if (node->index != curr && !inStack[node->index])
            {
                st.push(node->index);
                inStack[node->index] = 1;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            char val = getOtherDetailsFromIndex(curr);
            cout << "(" << curr << "," << val << ") ";
            visit[curr] = 1;
            st.pop();
            inStack[curr] = 1;
        }
    }
}

void Graph ::displayNodes()
{
    cout << "\n\nDetails of all Vertices (index, data, degree) ::\n";
    for (auto &list : adjacency_list)
    {
        Node *head = list.front();
        if (!list.empty())
            cout << "(" << head->index << "," << head->data << "," << head->degree << ")  ";
        else
            cout << "( )  ";
        head = NULL;
    }
}

void Graph ::Display()
{
    cout << "\n (index, data)";
    for (auto &list : adjacency_list)
    {
        Node *head = list.front();
        for (auto &adjNode : list)
            cout << "\n (" << head->index << "," << head->data << ") ----" << adjNode->weight << "----> (" << adjNode->index << "," << adjNode->data << ")";
    }
    cout << "\nBFS :: ";
    bfs();
    cout << "\nDFS :: ";
    dfs();
}

void Graph ::Destroy()
{
    for (auto &list : adjacency_list)
    {
        for (Node *node : list)
        {
            delete node;
        }
        list.clear();
    }
    adjacency_list.clear();
}

int main()
{
    int edg, ver;
    cout << "Enter number of verties : ";
    cin >> ver;
    cout << "Enter number of edges : ";
    cin >> edg;
    Graph graph(edg, ver);
    graph.create();
    graph.Display();
    graph.Destroy();
    return 0;
}