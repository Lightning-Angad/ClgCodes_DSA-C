#include<stdio.h>
#include<ctype.h>     //for isdigit()
#define MAX 100

//Stack for operators (char) and operands (int)
char opStack[MAX];    //stack operator
int topOp=-1;

int valStack[MAX];    //value stack
int topVal=-1;

//Push and pop for operator stack
void pushOp(char c) { 
    opStack[++topOp]=c;
}
char popOp(){
    return opStack[topOp--];
}

//Push and pop for value stack
void pushVal(int v) { 
    valStack[++topVal]=v;
}
int popVal(){
    return valStack[topVal--];
}

//Operator precedence
int precedence(char op) {
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

//Convert infix to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isdigit(ch)) {
            postfix[k++] = ch;
        } 
        else if (ch == '(') {
            pushOp(ch); 
        } 
        else if (ch == ')') {
            while (opStack[topOp] != '(') {
                postfix[k++] = popOp(); 
            }
            popOp();  // Pop the '(' from the stack
        } 
        else {  // Operator case
            while (topOp != -1 && precedence(opStack[topOp]) >= precedence(ch)) {
                postfix[k++] = popOp();
            }
            pushOp(ch);
        }
    }
    while (topOp != -1) {
        postfix[k++] = popOp();
    }
    postfix[k] = '\0';

}

//Evaluate postfix expression
int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            pushVal(ch - '0');
        } else {
            int b = popVal();
            int a = popVal();
            switch (ch) {
                case '+': pushVal(a + b); break;
                case '-': pushVal(a - b); break;
                case '*': pushVal(a * b); break;
                case '/': pushVal(a / b); break;
            }
        }
    }
    return popVal();
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter an infix expression (no spaces, single-digit numbvers): ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}