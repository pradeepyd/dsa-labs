#include <iostream>
#include <math.h>
#include <stack>
#include <sstream>
#include <cctype> 
using namespace std;

// Function to get precedence of operators
int precedence(char op) 
{
    if (op == '+' || op == '-') 
    return 1;
    if (op == '*' || op == '/')
    return 2;
    if (op == '^')
    return 3;
    return 0;
}


string infixToPostfix(string infix) {
    stack<char> opStack; // Stack for operators
    string postfix = ""; // Resultant postfix string

    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];

        if (isspace(ch)) continue; // Ignore whitespace

        // If the character is a digit, add it to postfix
        if (isdigit(ch)) {
            while (i < infix.length() && isdigit(infix[i])) {
                postfix += infix[i++];
            }
            postfix += " "; // Add space to separate operands
            --i; // Adjust the position
        }
        // If the character is '(', push to stack
        else if (ch == '(') {
            opStack.push(ch);
        }
        // If the character is ')', pop from stack until '(' is found
        else if (ch == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.pop(); // Remove '(' from stack
        }
        // If the character is an operator
        else {
            while (!opStack.empty() && precedence(opStack.top()) >= precedence(ch)) {
                postfix += opStack.top();
                postfix += " ";
                opStack.pop();
            }
            opStack.push(ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!opStack.empty()) {
        postfix += opStack.top();
        postfix += " ";
        opStack.pop();
    }

    return postfix;
}

// Function to evaluate a postfix expression
int postfix(string s) {
    stack<int> st;
    stringstream ss(s);
    string ch;

    while (ss >> ch) { // Read each token
        if (isdigit(ch[0])) {
            st.push(stoi(ch)); // Push operand onto stack
        } else { // Handle operators
            if (st.size() < 2) {
                cout << "Insufficient operands for operator '" << ch << "'." << endl;
                return -1;
            }
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            if (ch == "+") {
                st.push(op2 + op1);
            } else if (ch == "-") {
                st.push(op2 - op1);
            } else if (ch == "/") {
                if (op1 == 0) {
                    cout << "Error: Division by zero." << endl;
                    return -1;
                }
                st.push(op2 / op1);
            } else if (ch == "*") {
                st.push(op2 * op1);
            } else if (ch == "^") {
                st.push(pow(op2, op1));
            } else {
                cout << "Invalid operator: " << ch << endl;
                return -1;
            }
        }
    }

    if (st.size() != 1) {
        cout << "Invalid postfix expression." << endl;
        return -1;
    }

    return st.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    // Convert infix to postfix
    string postfixExpr = infixToPostfix(infix);
    cout << "Postfix expression: " << postfixExpr << endl;

    // Evaluate postfix expression
    int result = postfix(postfixExpr);
    if (result != -1) {
        cout << "The result is: " << result << endl;
    }
    return 0;
}
