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

void prefixEvaluation(string prefix)
{
    // we assume that the given expression is valid.
    int l = prefix.length();
    float ans;
    stack<float> st;
    for (int i = l - 1; i >= 0; i--)
    {
        if (prefix[i] == ' ')
            continue;
        else if (isOperand(prefix[i]))
        {
            st.push(float(prefix[i]-'0'));
        }
        else
        {
            float op1 = st.top();
            st.pop();
            float op2 = st.top();
            st.pop();
            float tmp;
            switch (prefix[i])
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
    cout << "Enter the prefix expression : ";
    cout << "NOTE :: Only single digit operands are allowed.\n";
    cin >> s;
    prefixEvaluation(s);
    return 0;
}