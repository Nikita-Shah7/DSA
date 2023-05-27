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

void PrefixToInfix(string prefix)
{
    int l = prefix.length();
    string infix = "";
    stack<string> st;
    for (int i = l-1; i >=0 ; i--)
    {
        if (prefix[i] == ' ')
            continue;
        else if (isOperand(prefix[i]))
        {
            string operand(1, prefix[i]); // Convert char to string
            st.push(operand);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            string tmp = "";
            tmp = '(' + op1 + prefix[i] + op2 + ')';
            st.push(tmp);
        }
    }
    infix = st.top();
    cout << "Infix Expression : " << infix;
}

int main()
{
    string s = "";
    while (1)
    {
        cout << "Enter the prefix expression : \n";
        cout << "NOTE :: Only single charactr operands are allowed.\n";
        cout << "NOTE :: Enter '0' to exit.\n";
        cin >> s;
        // s = "*+ab/ef";
        if (s[0] == '0')
        {
            cout << "You choose to Exit.\n";
            return 0;
        }
        PrefixToInfix(s);
        return 0;
    }
}

/*
Prefix Expression : + + - + k l * m n * / / * ^ o p w u v t q
Infix Expression : ((((k+l)-(m*n))+(((((o^p)*w)/u)/v)*t))+q)
*/