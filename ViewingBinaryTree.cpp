// horizontal distance of root node = 0;
// horizontal distance of parent node = k;
// horizontal distance of left child of parent node = k-1;
// horizontal distance of right child of parent node = k+1

#include<bits/stdc++.h>
using namespace std;


void seperator1()
{
    for(int i=0;i<65;i++)    cout<<"-";
    cout<<endl;
}

void seperator2()
{
    for(int i=0;i<40;i++)    cout<<"-";
    cout<<endl;
}

class Node
{
    int data;
    int hd;  // horizontal distance from root node
    public:
    Node* lchild;
    Node* rchild;
        Node(int);
    friend class BinaryTree;    
};

Node :: Node(int val)
{
    data = val;
    hd=0;
    lchild = NULL;
    rchild = NULL;
}

class BinaryTree
{
    bool isEmpty();
    bool isFull();
    bool isRoot(Node*);
    bool isLeaf(Node*);
    int Size();
    void PreOrder(Node*);
    void InOrder(Node*);
    void PostOrder(Node*);
    void LevelOrder(Node*);   // DFT
    void TopView(Node*);
    void BottomView(Node*);
    void LeftView(Node*);
    void RightView(Node*);
    void VerticalOrder(Node*);
    void leftBoundary(Node*);
    void leafNodes(Node*);
    void rightBoundary(Node*);
    void BoundaryTraversal(Node*);
    void ZigZagLevel(Node*);
    void ZigZagDiagonalUtil(Node*,int, map<int,vector<int>>&);
    void ZigZagDiagonal(Node*);
    int HeightOfNode(Node*);
    int Depth(Node*);
    void assignHD(Node*&,int);

    public:
        Node* root;
        int size;   // number of nodes    
        BinaryTree();
        void Create();
        void Display();  
        void DestroyTree();
        void Destroy(Node*);
};

BinaryTree :: BinaryTree(void)
{
    root = NULL;
    size = 0;    
}

bool BinaryTree :: isEmpty(void)
{
    if(root)
        return 0;
    return 1;
}

bool BinaryTree :: isFull(void)
{
    Node* newNode = new Node(0);
    if(!newNode)
    {
        delete(newNode);
        newNode = NULL;
        return 1;
    }
    else
    {
        delete(newNode);
        newNode = NULL;
        return 0;
    }
}

bool BinaryTree :: isRoot(Node* ptr)
{
    if(ptr && ptr==root)
        return 1;
    return 0;
}

bool BinaryTree :: isLeaf(Node* ptr)
{
    if(ptr && !ptr->lchild && !ptr->rchild)
        return 1;
    return 0;
}

int BinaryTree :: Size()
{
    return size;
}

int BinaryTree :: HeightOfNode(Node* ptr)
{
    // considering the leaf nodes to be at height 0
    if(!ptr) return -1;
    else if(isLeaf(ptr)) return 0;
    return 1 + max(HeightOfNode(ptr->lchild) , HeightOfNode(ptr->rchild));
}

int BinaryTree :: Depth(Node* ptr)
{
    // considering the root node to be at depth 0
    if(!ptr) return -1;
    int level = 0;
    queue<Node*>q;
    q.push(ptr);    
    Node* curr;
    Node* last = q.back();
    while(!q.empty())
    {     
        curr = q.front();  
        if(curr == ptr)
            return level;
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
        if(curr==last)
        {
            level++;            
            last = q.back();
        }                   
    }
    return -1;
}

void BinaryTree :: PreOrder(Node* ptr)
{
    if(!ptr) return;
    cout<<ptr->data<<" ";
    PreOrder(ptr->lchild);
    PreOrder(ptr->rchild);
}

void BinaryTree :: InOrder(Node* ptr)
{
    if(!ptr) return;
    InOrder(ptr->lchild);
    cout<<ptr->data<<" ";
    InOrder(ptr->rchild);
}

void BinaryTree :: PostOrder(Node* ptr)
{
    if(!ptr) return;
    PostOrder(ptr->lchild);
    PostOrder(ptr->rchild);
    cout<<ptr->data<<" ";
}

void BinaryTree :: LevelOrder(Node* ptr)
{
    int level = 1;
    queue<Node*>q;
    q.push(ptr);
    cout<<endl<<level<<" -> ";
    Node* curr;
    Node* last = q.back();
    while(!q.empty())
    {     
        curr = q.front();  
        cout<<curr->data<<" ";
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
        if(!q.empty() && curr==last)
        {
            level++;            
            cout<<endl<<level<<" -> ";            
            last = q.back();
        }                   
    }
}

void BinaryTree :: TopView(Node* ptr)
{
    // create a hashmap <hd,data>
    // do level order traversal
    map<int,int>mp;
    queue<Node*>q;
    q.push(ptr);
    Node* curr;
    Node* last = q.back();
    while(!q.empty())
    {     
        curr = q.front();  
        // cout<<curr->data<<" ";
        if(!mp[curr->hd]) mp[curr->hd] = curr->data;
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
        if(!q.empty() && curr==last)
        {
            last = q.back();
        }                   
    }
    for(auto x:mp)  cout<<x.second<<" ";
}

void BinaryTree :: BottomView(Node* ptr)
{
    // create a hashmap <hd,data>
    // do level order traversal
    map<int,int>mp;
    queue<Node*>q;
    q.push(ptr);
    Node* curr;
    Node* last = q.back();
    while(!q.empty())
    {     
        curr = q.front();  
        // cout<<curr->data<<" ";
        mp[curr->hd] = curr->data;
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
        if(!q.empty() && curr==last)
        {
            last = q.back();
        }                   
    }
    for(auto x:mp)  cout<<x.second<<" ";
}

void BinaryTree :: LeftView(Node* ptr)
{
    // we just need first node of each level
    vector<int>v( HeightOfNode(ptr)+1 , 0);
    int level=0;
    queue<Node*>q;
    q.push(ptr);
    Node* curr;
    Node* last = q.back();
    while(!q.empty())
    {     
        curr = q.front();  
        // cout<<curr->data<<" ";
        if(!v[level]) v[level]=curr->data;
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
        if(!q.empty() && curr==last)
        {
            level++;
            last = q.back();
        }                   
    }
    for(auto x:v) cout<<x<<" ";
}

void BinaryTree :: RightView(Node* ptr)
{
// we just need last node of each level
    vector<int>v( HeightOfNode(ptr)+1 , 0);
    int level=0;
    queue<Node*>q;
    q.push(ptr);
    Node* curr;
    Node* last = q.back();
    while(!q.empty())
    {     
        curr = q.front();  
        // cout<<curr->data<<" ";
        if(!v[level]) v[level]=curr->data;
        if(curr->rchild) q.push(curr->rchild);
        if(curr->lchild) q.push(curr->lchild);
        q.pop();
        if(!q.empty() && curr==last)
        {
            level++;
            last = q.back();
        }                   
    }
    for(auto x:v) cout<<x<<" ";
}

void BinaryTree :: VerticalOrder(Node* ptr)
{
    map<int,vector<int>>mp;
    queue<Node*>q;
    q.push(ptr);
    Node* curr;
    Node* last = q.back();
    while(!q.empty())
    {     
        curr = q.front();  
        // cout<<curr->data<<" ";
        mp[curr->hd].push_back(curr->data);
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
        if(!q.empty() && curr==last)
        {
            last = q.back();
        }                   
    }
    for(auto x:mp)  
    {
        cout<<endl;
        for(auto y:x.second)  cout<<y<< " ";
    }
}

void BinaryTree :: ZigZagDiagonalUtil(Node* ptr, int d, map<int,vector<int>>&mp)
{
    if(!ptr) return;
    mp[d].push_back(ptr->data);
    ZigZagDiagonalUtil(ptr->lchild,d+1,mp);
    ZigZagDiagonalUtil(ptr->rchild,d,mp);
    return;
}

void BinaryTree :: ZigZagDiagonal(Node* ptr)
{
    map<int,vector<int>>mp;
    ZigZagDiagonalUtil(ptr,0,mp);

    for(auto x:mp)
    {
        cout<<endl;
        for(auto y:x.second) cout<<y<<" ";
    }
}

void BinaryTree :: ZigZagLevel(Node* ptr)
{
    // we maintain 2 stacks 1.currlvl 2.nextlvl
    // from currlvl -> lchild to rclild
    // from nextlvl -> rchild to lclild
    stack<Node*>currlvl;
    stack<Node*>nextlvl;

    currlvl.push(ptr);
    while(!currlvl.empty() || !nextlvl.empty())
    {
        if(currlvl.empty())
        {
            while(!nextlvl.empty())
            {
                if(nextlvl.top()->rchild) currlvl.push(nextlvl.top()->rchild);
                if(nextlvl.top()->lchild) currlvl.push(nextlvl.top()->lchild);
                cout<<nextlvl.top()->data<<" ";
                nextlvl.pop();
            }
        }
        else
        {
            while(!currlvl.empty())
            {
                if(currlvl.top()->lchild) nextlvl.push(currlvl.top()->lchild);
                if(currlvl.top()->rchild) nextlvl.push(currlvl.top()->rchild);
                cout<<currlvl.top()->data<<" ";
                currlvl.pop();
            }
        }
    }
}

void BinaryTree :: leftBoundary(Node* ptr)
{
    if(!ptr) return;
    if(ptr) 
    {
        if(!isLeaf(ptr)) cout<<ptr->data<<" ";
        leftBoundary(ptr->lchild);
    }
    else leftBoundary(ptr->rchild);
    return;
}

void BinaryTree :: leafNodes(Node* ptr)
{
    // sort of inorder traversal
    if(!ptr) return;
    leafNodes(ptr->lchild);
    if(isLeaf(ptr)) cout<<ptr->data<<" ";
    leafNodes(ptr->rchild);
}

void BinaryTree :: rightBoundary(Node* ptr)
{
    if(!ptr) return;
    if(ptr)
    {
        rightBoundary(ptr->rchild);
        if(!isLeaf(ptr)) cout<<ptr->data<<" "; 
    }
    else rightBoundary(ptr->lchild);
    return;
}

void BinaryTree :: BoundaryTraversal(Node* ptr)
{
    // 1. Left Boundary(top-down)(except leaf node)
    // 2. Leaf Nodes(left-right)
    // 3. Right Boundary(bottom-up)(except leaf node)
    cout<<ptr->data<<" ";
    leftBoundary(ptr->lchild);
    leafNodes(ptr->lchild);
    leafNodes(ptr->rchild);
    rightBoundary(ptr->rchild);
}

void BinaryTree :: assignHD(Node*& ptr, int i)  //assign horizontal distance
{
    if(isRoot(ptr)) ptr->hd = 0;
    else ptr->hd = i;
    if(ptr->lchild) assignHD(ptr->lchild,i-1);
    if(ptr->rchild) assignHD(ptr->rchild,i+1);
    return;
}

void BinaryTree :: Display(void)
{
    if(isEmpty())
    {
        cout<<"The Tree is empty!";
        return;
    }
    seperator2();
    cout<<"PreOrder :: ";
    PreOrder(root);
    cout<<endl;
    cout<<"InOrder :: ";
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder :: ";
    PostOrder(root);
    cout<<endl;
    cout<<"LevelOrder :: ";
    LevelOrder(root);
    cout<<endl;
    assignHD(root,0);
    cout<<"VerticalOrder :: ";
    VerticalOrder(root);
    cout<<endl;
    cout<<"TopView :: ";
    TopView(root);
    cout<<endl;
    cout<<"BottomView :: ";
    BottomView(root);
    cout<<endl;
    cout<<"LeftView :: ";
    LeftView(root);
    cout<<endl;
    cout<<"RightView :: ";
    RightView(root);
    cout<<endl;
    cout<<"ZigZagLevelOrderTraversal :: ";
    ZigZagLevel(root);
    cout<<endl;
    // Diagonals move from root to right-bottom
    cout<<"ZigZagDiagonalTraversal ::";
    ZigZagDiagonal(root);
    cout<<endl;
    cout<<"BoundaryTraversal ::";
    BoundaryTraversal(root);
    cout<<endl;
    cout<<"Size of Binary Tree : "<<Size()<<endl;
    cout<<"Height of Binary Tree : "<<HeightOfNode(root)<<endl; 
    seperator2();   
}

void BinaryTree :: Destroy(Node* ptr)
{
    if(!ptr) return;
    Destroy(ptr->lchild);
    Destroy(ptr->rchild);
    delete ptr;
}

void BinaryTree :: DestroyTree()
{
    Destroy(root);
    root = NULL;
    size = 0;
    return;
}

int main(void)
{
    seperator1();
    cout<<"*****VIEW AND TRAVERSE A BINARY TREE FROM VARIOUS ANGLES*****"<<endl;
    seperator1();
    cout<<endl;

    
        seperator2();
        cout<<"\t***BINARY TREE 1***"<<endl;
        BinaryTree tree1;
            Node* newNode = new Node(1);
            tree1.root = newNode;
            newNode = NULL;
            newNode = new Node(2);
            tree1.root->lchild = newNode;
            newNode = NULL;
            newNode = new Node(3);
            tree1.root->rchild = newNode;
            newNode = NULL;
            newNode = new Node(4);
            tree1.root->lchild->lchild = newNode;
            newNode = NULL;
            newNode = new Node(5);
            tree1.root->lchild->rchild = newNode;
            newNode = NULL;
            newNode = new Node(6);
            tree1.root->rchild->lchild = newNode;
            newNode = NULL;
            newNode = new Node(7);
            tree1.root->rchild->rchild = newNode;
            newNode = NULL;
            tree1.size = 7;
            tree1.Display();
            tree1.Destroy(tree1.root);
            cout<<endl;
          
        seperator2();
        cout<<"\t***BINARY TREE 2***"<<endl;
        BinaryTree tree2;
            newNode = new Node(1);  
            tree2.root = newNode;
            newNode = NULL;
            newNode = new Node(2);
            tree2.root->lchild = newNode;
            newNode = NULL;
            newNode = new Node(3);
            tree2.root->rchild = newNode;
            newNode = NULL;
            newNode = new Node(4);
            tree2.root->lchild->rchild = newNode;
            newNode = NULL;
            newNode = new Node(5);
            tree2.root->lchild->rchild->rchild = newNode;
            newNode = NULL;
            newNode = new Node(6);
            tree2.root->lchild->rchild->rchild->rchild = newNode;
            newNode = NULL;
            tree2.size = 6;
            tree2.Display();
            tree2.Destroy(tree2.root);
            cout<<endl;

        seperator2();
        cout<<"\t***BINARY TREE 3***"<<endl;
        BinaryTree tree3;
            newNode = new Node(1);
            tree3.root = newNode;
            newNode = NULL;
            newNode = new Node(2);
            tree3.root->lchild = newNode;
            newNode = NULL;
            newNode = new Node(3);
            tree3.root->rchild = newNode;
            newNode = NULL;
            newNode = new Node(4);
            tree3.root->lchild->lchild = newNode;
            newNode = NULL;
            newNode = new Node(5);
            tree3.root->lchild->rchild = newNode;
            newNode = NULL;
            newNode = new Node(6);
            tree3.root->rchild->lchild = newNode;
            newNode = NULL;
            newNode = new Node(7);
            tree3.root->rchild->rchild = newNode;
            newNode = NULL;
            newNode = new Node(8);
            tree3.root->lchild->rchild->lchild = newNode;
            newNode = NULL;
            newNode = new Node(9);
            tree3.root->lchild->rchild->rchild = newNode;
            newNode = NULL;
            newNode = new Node(10);
            tree3.root->lchild->rchild->lchild->lchild = newNode;
            newNode = NULL;
            newNode = new Node(11);
            tree3.root->lchild->rchild->rchild->rchild = newNode;
            newNode = NULL;
            tree3.size = 11;
            tree3.Display();
            tree3.Destroy(tree3.root);
            cout<<endl;
    
    return 0;
}