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

void postfixEvaluation(string postfix)
{
    // we assume that the given expression is valid.
    int l = postfix.length();
    float ans;
    stack<float> st;
    for (int i = 0; i <l; i++)
    {
        if (postfix[i] == ' ')
            continue;
        else if (isOperand(postfix[i]))
        {
            st.push(float(postfix[i]-'0'));
        }
        else
        {
            float op2 = st.top();
            st.pop();
            float op1 = st.top();
            st.pop();
            float tmp;
            switch (postfix[i])
            {
            case '+':
                tmp = op1 + op2;
                break;
            case '-':
                tmp = op1 - op2;
                break;
            case '*':
                tmp = op1 * op2;
                break;
            case '/':
                tmp = op1 / op2;
                break;
            case '%':
                tmp = (int)op1 % (int)op2;
                break;
            case '^':
                tmp = pow(op1, op2);
                break;
            }
            st.push(tmp);
        }
    }
    cout << "Result : " << st.top();
    return;
}

int main()
{
    string s;
    cout << "Enter the postfix expression : ";
    cout << "NOTE :: Only single digit operands are allowed.\n";
    cin >> s;
    postfixEvaluation(s);
    return 0;
}