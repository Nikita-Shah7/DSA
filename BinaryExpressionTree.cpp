// here, we construct BinaryExpressionTree from postfix expression

#include <bits/stdc++.h>
using namespace std;

class Node
{
    char ch;
    Node *left;
    Node *right;

public:
    Node(char);
    friend class BinaryExpressionTree;
};

Node ::Node(char c)
{
    ch = c;
    left = NULL;
    right = NULL;
}

class BinaryExpressionTree
{
    Node* root;
    string postfix;
    void PreOrder(Node*);
    void InOrder(Node*);
    void PostOrder(Node*);
    public:
        BinaryExpressionTree(string);
        void Create();
        void Display();
};

BinaryExpressionTree :: BinaryExpressionTree(string s)
{
    root = NULL;
    postfix = s;
}

void BinaryExpressionTree :: PreOrder(Node* ptr)
{
    if(!ptr) return;
    cout<<ptr->ch<<" ";
    PreOrder(ptr->left);
    PreOrder(ptr->right);
}

void BinaryExpressionTree :: InOrder(Node* ptr)
{
    if(!ptr) return;
    InOrder(ptr->left);
    cout<<ptr->ch<<" ";
    InOrder(ptr->right);
}

void BinaryExpressionTree :: PostOrder(Node* ptr)
{
    if(!ptr) return;
    PostOrder(ptr->left);
    PostOrder(ptr->right);
    cout<<ptr->ch<<" ";
}

void BinaryExpressionTree :: Display(void)
{
    cout<<"Prefix Expression :: ";
    PreOrder(root);
    cout<<endl;
    cout<<"Infix Expression :: ";
    InOrder(root);
    cout<<endl;
    cout<<"Postfix Expression :: ";
    PostOrder(root);
    cout<<endl;
}

bool isOperand(char ch)
{
    return isalnum(ch);
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        return 1;
    else
        return 0;
}

void BinaryExpressionTree :: Create()
{
    int l = postfix.length();
    stack<Node *> st;
    for (int i = 0; i < l; i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (isOperand(postfix[i]))
        {
            Node *newNode = new Node(postfix[i]);
            st.push(newNode);
        }
        else
        {
            Node* right = st.top();
            st.pop();
            Node* left = st.top();
            st.pop();
            Node *newNode = new Node(postfix[i]);
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    root = st.top();
    st.pop();
}

int main()
{
    string s = "";
    while (1)
    {
        cout << "Enter the postfix expression : \n";
        cout << "NOTE :: Enter '0' to exit.\n";
        cin >> s;
        // s="ab-";
        // s = "a b - m n ^ o p + * + s r s ^ / t * - z +";
        // s = "(1+3)*4";
        // s = "(1+(3*5))/(7-2)" ;
        // s = "k+l-m*n+(o^p)*w/u/v*t+q" ;
        // s = "aa-b+(m^n)*(o+p)-sq/r^s*t+zqw" ;
        if(s[0] =='0') 
        {
            cout<<"You choose to Exit.\n";
            return 0;
        }
        BinaryExpressionTree tree(s);
        tree.Create();
        tree.Display();
    }
    return 0;
}

/*
Enter the postfix expression : 
NOTE :: Enter '0' to exit.
a b - m n ^ o p + * + s r s ^ / t * - z +
Prefix Expression :: + - + - a b * ^ m n + o p * / s ^ r s t z 
Infix Expression :: a - b + m ^ n * o + p - s / r ^ s * t + z 
Postfix Expression :: a b - m n ^ o p + * + s r s ^ / t * - z + 
*/