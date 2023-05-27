#include<bits/stdc++.h>
using namespace std;


void seperator()
{
    for(int i=0;i<40;i++)    cout<<"-";
    cout<<endl;
}

class Node
{
    int data;
    Node* lchild;
    Node* rchild;
    public:
        Node();
    friend class BinaryTree;    
};

Node :: Node(void)
{
    lchild = NULL;
    rchild = NULL;
}

class BinaryTree
{
    Node* root;
    int size;   // number of nodes    

    bool isEmpty();
    bool isFull();
    bool isRoot(Node*);
    bool isLeaf(Node*);
    int Size();
    void PreOrder(Node*);
    void InOrder(Node*);
    void PostOrder(Node*);
    void LevelOrder(Node*);   // DFT
    int HeightOfNode(Node*);
    int Depth(Node*);
    Node* deepestNode();

    public:
        BinaryTree();
        void Create();
        void Insert();
        void Display();
        void Search();
        void Delete();      
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
    Node* newNode = new Node();
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

void BinaryTree :: Create()
{
    if(!isEmpty())
    {
        cout<<"Binary Tree is already created.\n";
        return;
    }

    cout<<"NOTE: Enter -1 to finish entering the data\n";
    int val;
    cout<<"\nEnter the data to be inserted : ";
    cin>>val;    
    if(val==-1) return;
    Node* newNode = new Node();                  
    newNode->data = val; 
    root = newNode;
    size++;

    queue<Node*>q;
    Node* curr;
    q.push(root);
          
    while (!q.empty())
    {
        if(isFull())
        {
            cout<<"Binary Tree is Full!\n";
            return;
        }
        
        cout<<"Enter the data to be inserted : ";
        cin>>val;    
        if(val==-1) 
        {
            while (!q.empty())
                q.pop();            
            return;
        }
        size++;
        Node* newNode = new Node();                  
        newNode->data = val; 

        curr = q.front();
        if(!curr->lchild)
        {
            curr->lchild = newNode;
            q.push(curr->lchild);            
        }
        else if(!curr->rchild)
        {
            curr->rchild = newNode;
            q.push(curr->rchild);
            q.pop();
        }
    }            
}

void BinaryTree :: Insert()
{
    if(isFull())
    {
        cout<<"Binary Tree is Full!\n";
        return;
    }
    Node* newNode = new Node();
    cout << "Enter the value of the data to be inserted : ";
    cin >> newNode->data;

    if(isEmpty())
    {
        root = newNode;
        size++;
        return;
    }

    queue<Node*>q;
    q.push(root);
    Node* curr;

    while(!q.empty())
    {
        curr = q.front();
        if(curr->lchild)    q.push(curr->lchild);
        else 
        {
            curr->lchild = newNode;
            size++;
            return;
        }
        if(curr->rchild)    q.push(curr->rchild);
        else 
        {
            curr->rchild = newNode;
            size++;
            return;
        }
        q.pop();
    }
}

void BinaryTree :: Search()
{
    int val;
    cout<<"Enter value of element to be searched : ";
    cin>>val;

     if(isEmpty())
    {
        cout<<"The Tree is empty!\n";
        return;
    }

    queue<Node*>q;
    q.push(root);
    Node* curr;
    while (!q.empty())
    {
        curr = q.front();
        if(curr->data == val)
        {
            cout<<"Element found";
            return;
        }
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
    }
    cout<<"No such element found!\n";
    return;    
}

Node* BinaryTree :: deepestNode()   // get pointer to parent og the deepest node
{
    queue<Node*>q;
    Node* curr;
    Node* parent;
    q.push(root);
    while (!q.empty())
    {
        curr = q.front();
        if(curr->lchild) 
        {
            q.push(curr->lchild);
            parent = curr;
        }
        if(curr->rchild)
        {
            q.push(curr->rchild);
            parent = curr;
        }
        q.pop();
    }
    return parent;    
}

void BinaryTree :: Delete()
{
    // replace the data of the node to be deleted by the data in the deepest node
    // delete the deepest node
    // here, first occurence of the data will be deleted
    if(isEmpty())
    {
        cout<<"The Tree is empty!\n";
        return;
    }
    int val;
    cout<<"Enter the data to be deleted : ";
    cin>>val;

    Node* curr;
    queue<Node*>q;
    q.push(root);

    while (!q.empty())  
    {
        curr = q.front();
        if(curr->data==val)
        {
            if(isLeaf(root))
            {
                delete(root);
                root = NULL;
                return;
            }
            Node* parent = deepestNode();
            if(parent->rchild) 
            {
                curr->data = parent->rchild->data;
                parent->rchild = NULL;
            }
            else
            {
                curr->data = parent->lchild->data;
                parent->lchild = NULL;
            }
            curr = NULL;
            size--;
            return;
        }
        if(curr->lchild) q.push(curr->lchild);
        if(curr->rchild) q.push(curr->rchild);
        q.pop();
    }

    cout<<"Invalid element entered!\n";
    return;
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

void BinaryTree :: Display(void)
{
    if(isEmpty())
    {
        cout<<"The Tree is empty!";
        return;
    }
    seperator();
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
    cout<<"Size of Binary Tree : "<<Size()<<endl;
    cout<<"Height of Binary Tree : "<<HeightOfNode(root)<<endl; 
    seperator();   
}


int main(void)
{
    BinaryTree BT;
    int opt;
    cout << "***** BINARY TREE DATA STRUCTURE MENU DRIVEN *****" << endl;
    cout << "0: Display Binary Tree" << endl;
    cout << "1: Create Binary Tree" << endl;
    cout << "2: Insert an element." << endl;
    cout << "(Note: The element will be inserted at the first empty space found in the tree. )" << endl;
    cout << "3: Delete an element." << endl;
    cout << "(Note: It will shift the deepest element in place of the element that was asked to be deleted.)" << endl;
    cout << "4: Search" << endl;
    cout << "-1: Quit" << endl;
    do
    {
        cout << "\nEnter your choice : ";
        cin >> opt;
        switch (opt)
        {
        case 0:
            BT.Display();
            break;
        case 1:
            BT.Create();
            break;
        case 2:
            BT.Insert();
            break;
        case 3:
            BT.Delete();
            break;
        case 4:
            BT.Search();
            break;
        case -1:
            cout << "***** THANK YOU *****" << endl;
            break;
        default:
            cout << "Enter Valid Option...." << endl;
            break;
        }
    } while (opt != -1);

    return 0;
}


// Reference[0] :: https://github.com/Mihir-Paija/DSA