// `delete ptr` refers to deleting the node pointed to by the ptr pointer. 
// It deallocates the memory occupied by the node.

#include<bits/stdc++.h>
using namespace std;


void seperator()
{
    for(int i=0;i<40;i++)    cout<<"-";
    cout<<endl;
    return;
}

class Node
{
    int data;
    Node* lchild;
    Node* rchild;
    public:
        Node();
    friend class BinarySearchTree;    
};

Node :: Node(void)
{
    lchild = NULL;
    rchild = NULL;
}

class BinarySearchTree
{
    Node* root;
    int size;   // number of nodes    

    bool isEmpty();
    bool isFull();
    bool isRoot(Node*);
    bool isLeaf(Node*);
    int Size();
    int Depth(Node*);
    int HeightOfNode(Node*);
    int internalNodes(Node*);
    int externalNodes(Node*);
    void PreOrder(Node*);
    void InOrder(Node*);
    void PostOrder(Node*);
    void LevelOrder(Node*);   // DFT
    void InsertNode(Node*,Node*);
    bool SearchNode(int,Node*);
    bool DeleteNode(int,Node*&);
    void Destroy(Node*);

    public:
        BinarySearchTree();
        void Create();
        void Insert();
        void Display();
        void Search();
        void Delete();      
        void DestroyTree();
};

BinarySearchTree :: BinarySearchTree(void)
{
    root = NULL;
    size = 0;    
}

bool BinarySearchTree :: isEmpty(void)
{
    if(root)
        return 0;
    return 1;
}

bool BinarySearchTree :: isFull(void)
{
    Node* newNode = new Node();
    if(!newNode)
    {
        delete newNode;
        newNode = NULL;
        return 1;
    }
    else
    {
        delete newNode;
        newNode = NULL;
        return 0;
    }
}

bool BinarySearchTree :: isRoot(Node* ptr)
{
    if(ptr && ptr==root)
        return 1;
    return 0;
}

bool BinarySearchTree :: isLeaf(Node* ptr)
{
    if(ptr && !ptr->lchild && !ptr->rchild)
        return 1;
    return 0;
}

int BinarySearchTree :: Size()
{
    return size;
}

int BinarySearchTree :: HeightOfNode(Node* ptr)
{
    // considering the leaf nodes to be at height 0
    if(!ptr) return -1;
    else if(isLeaf(ptr)) return 0;
    return 1 + max(HeightOfNode(ptr->lchild) , HeightOfNode(ptr->rchild));
}

int BinarySearchTree :: Depth(Node* ptr)
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

int BinarySearchTree :: internalNodes(Node* ptr)
{
    if(!ptr) return 0;
    if( isLeaf(ptr) ) return 1;
    else return internalNodes(ptr->lchild) + internalNodes(ptr->rchild);
}

int BinarySearchTree :: externalNodes(Node* ptr)
{
    return size - internalNodes(ptr);
}

void BinarySearchTree :: InsertNode(Node* ptr, Node* parent)
{
    if(!root)
    {
        root = ptr;
        return;
    }
    if(ptr->data < parent->data)
    {
        if(parent->lchild) InsertNode(ptr,parent->lchild);
        else
        {
            parent->lchild = ptr;
            parent = NULL;
            ptr = NULL;
            return;
        }
    }
    else
    {
        if(parent->rchild) InsertNode(ptr,parent->rchild);
        else
        {
            parent->rchild = ptr;
            parent = NULL;
            ptr = NULL;
            return;
        }
    }
}

void BinarySearchTree :: Create()
{
    if(!isEmpty())
    {
        cout<<"Tree is already created!\n";
        return;
    }

    cout<<"NOTE: Enter -1 to finish entering the data\n";
    int val;
    while(1)
    {
        cout<<"Enter the data to be inserted : ";
        cin>>val;    
        if(val == -1) return;
        if(isFull())
        {
            cout<<"The tree is Full!\n";
            return;
        }
        Node* newNode = new Node();                  
        newNode->data = val;
        InsertNode(newNode,root);
        size++;
    }
}

void BinarySearchTree :: Insert()
{
    int val;
    cout<<"Enter the data to be inserted : ";
    cin>>val; 
    if(isFull())
    {
        cout<<"The tree is Full!\n";
        return;
    }
    Node* newNode = new Node();                  
    newNode->data = val;
    size++;
    if(isEmpty())
    {
        root = newNode;
        newNode = NULL;
        return;
    }
    InsertNode(newNode,root);
    return;
}

bool BinarySearchTree :: SearchNode(int val, Node* ptr)
{
    if(!ptr) return 0;
    if(val == ptr->data) return 1;
    else if(val < ptr->data) return SearchNode(val,ptr->lchild);
    else return SearchNode(val,ptr->rchild);
    return 0;
}

void BinarySearchTree :: Search()
{
    int val;
    cout<<"Enter value of element to be searched : ";
    cin>>val;

     if(isEmpty())
    {
        cout<<"The Tree is empty!\n";
        return;
    }

    if(SearchNode(val,root))    cout<<"Element found\n";
    else    cout<<"No such element found!\n";
    return;    
}

bool BinarySearchTree :: DeleteNode(int val, Node*& ptr)
{
    // Case 1 :: if the node to be deleted is not found, return false
    if(!ptr) return 0;
    // Case 2 :: if node to be deleted is found(ptr points to the node to be deleted and parent points to the parent of ptr)
    if(val == ptr->data)
    {        
        size--;
        // Case 2a :: if neither of leftChild nor rightChild is present
        if( isLeaf(ptr) )
        {
            delete ptr;
            ptr = NULL;
            return 1;
        }
        // if either of leftChild or rightChild is present
        else if(!ptr->rchild ^ !ptr->lchild)
        {      
            if(!ptr->lchild) // Case 2b :: if leftChild is NULL
            {
                Node* newNode = ptr->rchild;
                delete ptr;
                ptr = newNode;
                newNode = NULL;
                return 1;
            }
            else // Case 2c :: if rightChild is NULL
            {
                Node* newNode = ptr->lchild;
                delete ptr;
                ptr = newNode;
                newNode = NULL;
                return 1;             
            }
        }
        else    // Case 2d :: if both rightchild and leftChild are present, then we replace the element to be deleted with it's inOrderSuccessor
        {
            Node* succ = ptr->rchild;
            Node* succParent = ptr;
            while (succ->lchild)
            {
                succParent = succ;
                succ = succ->lchild;
            }
            ptr->data = succ->data;
            if(succParent == ptr) ptr->rchild = succ->rchild;
            else succParent->lchild = succ->rchild;
            delete succ;
            succ = NULL;
        }        
        return 1;
    }
    else if(val < ptr->data) return DeleteNode(val,ptr->lchild);
    else return DeleteNode(val,ptr->rchild);
    return 0;
}

void BinarySearchTree :: Delete()
{
    // here, first occurence of the data will be deleted
    if(isEmpty())
    {
        cout<<"The Tree is empty!\n";
        return;
    }
    int val;
    cout<<"Enter the data to be deleted : ";
    cin>>val;
    if(!SearchNode(val,root)) cout<<"Element not Found!\n";
    else    DeleteNode(val,root);
    return;
}

void BinarySearchTree :: PreOrder(Node* ptr)
{
    if(!ptr) return;
    cout<<ptr->data<<" ";
    PreOrder(ptr->lchild);
    PreOrder(ptr->rchild);
}

void BinarySearchTree :: InOrder(Node* ptr)
{
    if(!ptr) return;
    InOrder(ptr->lchild);
    cout<<ptr->data<<" ";
    InOrder(ptr->rchild);
}

void BinarySearchTree :: PostOrder(Node* ptr)
{
    if(!ptr) return;
    PostOrder(ptr->lchild);
    PostOrder(ptr->rchild);
    cout<<ptr->data<<" ";
}

void BinarySearchTree :: LevelOrder(Node* ptr)
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

void BinarySearchTree :: Display(void)
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
    cout<<"Details :: \n";
    cout<<"Size of Binary Tree : "<<Size()<<endl;
    cout<<"Height of Binary Tree : "<<HeightOfNode(root)<<endl; 
    cout<<"Total number of Internal Nodes : "<<internalNodes(root)<<endl;
    cout<<"Total number of External Nodes : "<<externalNodes(root)<<endl;
    seperator();   
}

void BinarySearchTree :: Destroy(Node* ptr)
{
    if(!ptr) return;
    Destroy(ptr->lchild);
    Destroy(ptr->rchild);
    delete ptr;
}

void BinarySearchTree :: DestroyTree()
{
    Destroy(root);
    root = NULL;
    size = 0;
    return;
}


int main(void)
{
    BinarySearchTree BST;
    int opt;
    cout << "***** BINARY SEARCH TREE DATA STRUCTURE MENU DRIVEN *****" << endl;
    cout << "0: Display Binary Search Tree" << endl;
    cout << "1: Create Binary Search Tree" << endl;
    cout << "2: Insert an element." << endl;
    cout << "3: Delete an element." << endl;
    cout << "4: Search" << endl;
    cout << "-1: Quit" << endl;
    do
    {
        cout << "\nEnter your choice : ";
        cin >> opt;
        switch (opt)
        {
        case 0:
            BST.Display();
            break;
        case 1:
            BST.Create();
            break;
        case 2:
            BST.Insert();
            break;
        case 3:
            BST.Delete();
            break;
        case 4:
            BST.Search();
            break;
        case -1:
            cout << "***** THANK YOU *****" << endl;
            break;
        default:
            cout << "Enter Valid Option...." << endl;
            break;
        }
    } while (opt != -1);
    BST.DestroyTree();
    return 0;
}