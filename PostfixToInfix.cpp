#include <bits/stdc++.h>
using namespace std;

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

void PostfixToInfix(string postfix)
{
    int l = postfix.length();
    string infix = "";
    stack<string> st;
    for (int i = 0; i < l; i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (isOperand(postfix[i]))
        {
            st.push(postfix[i]);
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string tmp = "";
            tmp = '(' + op1 + postfix[i] + op2 + ')';
            st.push(tmp);
        }
    }
    infix = st.top();
    cout << "Infix Expression : " << infix << endl;
}

int main()
{
    string s = "";
    while (1)
    {
        cout << "Enter the postfix expression : \n";
        cout << "NOTE :: Only single charactr operands are allowed.\n";
        cout << "NOTE :: Enter '0' to exit.\n";
        cin >> s;
        if (s[0] == '0')
        {
            cout << "You choose to Exit.\n";
            return 0;
        }
        PostfixToInfix(s);
    }
    return 0;
}

/*
Postfix Expression : a b - m n ^ o p + * + s r s ^ / t * - z +
Infix Expression : ((((a-b)+((m^n)*(o+p)))-((s/(r^s))*t))+z)
*/