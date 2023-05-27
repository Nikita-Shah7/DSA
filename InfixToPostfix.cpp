// operators allowed : ( ) ^ % / * + -
// operands allowed : 0-9 , a-z , A-Z
// parenthesis ( ) are not a part of postfix and prefix


#include <iostream>
#include <string>
#include <stack>
#include <cctype> // isalpha(char*) , isalnum(char*)
using namespace std;

bool associativity(char op )
{
    if (op == '%' || op == '/' || op == '*' || op == '+' || op == '-')
        return 0; // 0 for L to R
    else if (op == '^')
        return 1; // 1 for R to L
    return -1;
}

int precedence(char op )
{
    if(op == '(')
        return 10;
    else if(op == '^')
        return 3;
    else if (op == '%' || op == '/' || op == '*')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return -1;
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

void InfixToPostfix(string infix)
{
    if( isOperator(infix[0]) )
    {
        cout<<"Invalid Infix Expression!\n";
        return ;
    }

    int l = infix.length();
    string postfix = "";
    stack<char> st;
    for (int i = 0; i < l; i++)
    {
        if(isOperator(infix[i]))
        {
            postfix += " ";
        }
        if (isOperand(infix[i]))
        {
            postfix += infix[i];            
        }
        else if(infix[i] == ' ')
            continue;        
        else if (infix[i] == '(')
            st.push(infix[i]);
        else if (infix[i] == ')')
        {
            if(st.empty())
            {
                cout<<"Invalid Infix Expression!\n";
                return ;
            }
            else if (!st.empty() && st.top() != '(')
            {
                postfix += " ";
                postfix += st.top();
                st.pop();
                i--;
            }
            else
                st.pop();
        }
        else if (st.empty())
            st.push(infix[i]);
        else if(st.top() == '(')
            st.push(infix[i]);
        else if (precedence(infix[i]) > precedence(st.top()))
            st.push(infix[i]);
        else if (precedence(infix[i]) < precedence(st.top()))
        {
            postfix += st.top();
            st.pop();
            i--;
        }
        else if( precedence(infix[i]) == precedence(st.top()) )
        {
            if (associativity(infix[i]))
                st.push(infix[i]);
            else
            {
                postfix += st.top();
                st.pop();
                i--;
            }
        }
    }

    while (!st.empty() && st.top() != '(')
    {
        postfix += " ";
        postfix += st.top();
        st.pop();
    }

    if(!st.empty())
    {
        cout<<"Invalid Infix Expression!\n";
        return ;
    }

    cout << "Postfix expression : " << postfix << endl;
}


int main()
{
    string s = "";
    while (1)
    {
        cout << "Enter the infix expression : \n";
        cout<<"NOTE :: Enter '0' to exit.\n";
        cin >> s;
        // s = "(1+3)*4";
        // s = "(1+(3*5))/(7-2)" ;
        // s = "k+l-m*n+(o^p)*w/u/v*t+q" ;
        // s = "aa-b+(m^n)*(o+p)-sq/r^s*t+zqw" ;   postfix :: " aa b - m n ^ o p + * + sq r s ^ / t * - zqw + "
        if(s[0] =='0') 
        {
            cout<<"You choose to Exit.\n";
            return 0;
        }
        InfixToPostfix(s);
    }
    return 0;
}