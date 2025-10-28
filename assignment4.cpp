#include <bits/stdc++.h>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

// Check if character is operator
bool isOperator(char c) {
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}

// Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix;

    for(char c : infix) {
        if(isalnum(c)) {
            postfix += c;  // operand
        }
        else if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else { // operator
            while(!st.empty() && precedence(st.top()) >= precedence(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

// Infix to Prefix
string infixToPrefix(string infix) {
    // Reverse infix and swap ( with )
    reverse(infix.begin(), infix.end());
    for(char &c : infix) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }

    string postfix = infixToPostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

// Evaluate Postfix
int evaluatePostfix(string exp) {
    stack<int> st;

    for(char c : exp) {
        if(isdigit(c)) {
            st.push(c - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top();
}

// Evaluate Prefix
int evaluatePrefix(string exp) {
    stack<int> st;
    for(int i = exp.size()-1; i >= 0; i--) { 
        char c = exp[i];
        if(isdigit(c)) {
            st.push(c - '0');
        } else {
            int val1 = st.top(); st.pop();
            int val2 = st.top(); st.pop();
            switch(c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }
    return st.top();
}

int main() {
    string infix;
    cout << "Enter infix expression (single-digit operands, no spaces): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    string prefix = infixToPrefix(infix);

    cout << "\nInfix   : " << infix;
    cout << "\nPostfix : " << postfix;
    cout << "\nPrefix  : " << prefix;

    cout << "\n\nEvaluated Postfix = " << evaluatePostfix(postfix);
    cout << "\nEvaluated Prefix  = " << evaluatePrefix(prefix);

    return 0;
}
