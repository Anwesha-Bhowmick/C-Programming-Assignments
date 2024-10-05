#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <string>

using namespace std;

class Expr
{
    // ...
public:
    const char *expr;
    Expr(const char *expr)
    {
        this->expr = expr;
    }
    // Expr(const char *expr);
    int eval();   // returns the value of the expression
    void print(); // prints the representation of the expression on cout
};

// to check the precedence of operators
int precedence(char opr)
{
    if (opr == '+' || opr == '-')
        return 1;
    if (opr == '*' || opr == '/')
        return 2;
    return 0;
}

// to convert infix to postfix
string infixToPostfix(const char *infix)
{
    stack<char> st1;
    string p = "";
    for (int i = 0; i < strlen(infix); i++)
    {
        char c = infix[i];

        // if the scanned character is a digit, add it to output string.
        if (isdigit(c)) // checks whether c is a decimal digit
        {
            p += c;
        }

        // if the scanned character is '(', push it into the stack
        else if (c == '(')
            st1.push('(');

        // if the scanned character is ')', pop and add to output string from the stack until '(' is encountered
        else if (c == ')')
        {
            while (st1.top() != '(')
            {
                p += st1.top();
                st1.pop();
            }
            st1.pop();
        }

        // if the scanned character is an operator
        else
        {
            while (!st1.empty() && precedence(c) <= precedence(st1.top()))
            {
                p += st1.top();
                st1.pop();
            }
            st1.push(c);
        }
    }

    // pop all the remaining elements from the stack
    while (!st1.empty())
    {
        p += st1.top();
        st1.pop();
    }
    return p;
}

//to perform to respective mathematical operation
int Operation(int operand1, int operand2, char operation) 
{
    switch (operation)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
    }
}

int Expr::eval() // basically postfix expression evaluation function
{
    const char *infix = expr;
    string str = infixToPostfix(infix);
    const char *postfix = &str[0];
    // cout << "postfix  " << postfix <<  endl;;
    stack<int> st2;

    for (int i = 0; i < strlen(postfix); i++)
    {
        char c = postfix[i];

        if (isdigit(c))
        {
            // convert char digit to int and push onto the stack
            st2.push(c - '0');
        }
        else
        {
            // pop the top two elements for the operation
            int operand2 = st2.top();
            st2.pop();
            int operand1 = st2.top();
            st2.pop();

            // operate and push the result back onto the stack
            int result = Operation(operand1, operand2, c);
            st2.push(result);
        }
    }
    // the final result should be the only item left in the stack
    return st2.top();
}

void Expr::print()
{
    cout << expr << endl;
}

int main()
{
    Expr x("8/4+3*4-3");
    cout << "x = " << x.eval() << "\n";
    x.print();
    return 0;
}
