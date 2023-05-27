// operators allowed : ( ) ^ % / * + -
// operands allowed : 0-9 , a-z , A-Z
// parenthesis ( ) are not a part of postfix and prefix

#include <iostream>
#include <string>
#include <stack>
#include <cctype> // isalpha(char*) , isalnum(char*)
#include<algorithm> // reverse a string
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

void InfixToPrefix(string infix)
{
    if( isOperator(infix[0]) )
    {
        cout<<"Invalid Infix Expression!\n";
        return ;
    }

    reverse(infix.begin(),infix.end());
    int l = infix.length();
    string prefix = "";
    stack<char> st;
    for (int i = 0; i < l; i++)
    {
        if(isOperator(infix[i]))
        {
            prefix += " ";
        }
        if (isOperand(infix[i]))
        {
            prefix += infix[i];
        }
        else if (st.empty())
            st.push(infix[i]);
        else if (infix[i] == ')')
            st.push(infix[i]);
        else if (infix[i] == '(')
        {
            if(st.empty())
            {
                cout<<"Invalid Infix Expression!\n";
                return ;
            }
            else if (!st.empty() && st.top() != ')')
            {
                prefix += " ";
                prefix += st.top();
                st.pop();
                i--;
            }
            else
                st.pop();
        }
        else if(st.top() == ')')
            st.push(infix[i]);
        else if (precedence(infix[i]) >= precedence(st.top()))
            st.push(infix[i]);
        else // if (precedence(infix[i]) < precedence(st.top()))
        {
            prefix += st.top();
            st.pop();
            i--;
        }
    }

    while (!st.empty() && st.top() != '(')
    {
        prefix += " ";
        prefix += st.top();
        st.pop();
    }

    if(!st.empty())
    {
        cout<<"Invalid Infix Expression!\n";
        return ;
    }

    reverse(prefix.begin(),prefix.end());
    cout << "prefix expression : " << prefix << endl;
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
        // s = "k+l-m*n+(o^p)*w/u/v*t+q" ;     prefix :: " + + - + k l * m n * / / * ^ o p w u v t q "
        // s = "a-b+(m^n)*(o+p)-q/r^s*t+z" ;
        if(s[0] =='0') 
        {
            cout<<"You choose to Exit.\n";
            return 0;
        }
        InfixToPrefix(s);
    }
    return 0;
}