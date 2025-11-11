/*Write a function to convert an infix
expression to its corresponding postfix expression.

Write another function to evaluate the postfix
expression.
Write a driver program which will accept an infix expression from the user, print the corresponding postfix 
expression and also evaluate and print the output of the postfix expression.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

/* Stack for characters (used in infix to postfix conversion) */
char stack[SIZE];
int top = -1;

void push(char c) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    else
        return stack[top--];
}

char peek() {
    if (top == -1)
        return '\0';
    else
        return stack[top];
}

/* Function to check precedence of operators */
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

/* Function to check if character is operator */
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

/* Function to convert infix to postfix */
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char c;
    for (i = 0; i < strlen(infix); i++) {
        c = infix[i];

        if (isdigit(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (peek() != '(' && top != -1)
                postfix[j++] = pop();
            pop();  /* Remove '(' */
        }
        else if (isOperator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c))
                postfix[j++] = pop();
            push(c);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

/* ----------------- Evaluation of Postfix ----------------- */

int intStack[SIZE];
int intTop = -1;

void intPush(int n) {
    if (intTop == SIZE - 1)
        printf("Stack Overflow\n");
    else
        intStack[++intTop] = n;
}

int intPop() {
    if (intTop == -1) {
        printf("Stack Underflow\n");
        return 0;
    } else
        return intStack[intTop--];
}

/* Evaluate postfix expression */
int evaluatePostfix(char postfix[]) {
    int i, a, b, result;
    char c;

    for (i = 0; i < strlen(postfix); i++) {
        c = postfix[i];

        if (isdigit(c)) {
            intPush(c - '0');
        }
        else if (isOperator(c)) {
            b = intPop();
            a = intPop();

            switch (c) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            case '^': result = (int)pow(a, b); break;
            }
            intPush(result);
        }
    }
    return intPop();
}

/* ----------------- DRIVER PROGRAM ----------------- */
int main() {
    char infix[SIZE], postfix[SIZE];
    int result;

    printf("Enter a valid infix expression (single-digit operands): ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("\nPostfix Expression: %s\n", postfix);

    result = evaluatePostfix(postfix);
    printf("Evaluation Result: %d\n", result);

    return 0;
}



/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100

char opStack[SIZE]; int top = -1;
int valStack[SIZE]; int vtop = -1;

void push(char c){ opStack[++top]=c; }
char pop(){ return opStack[top--]; }
char peek(){ return opStack[top]; }
void vpush(int x){ valStack[++vtop]=x; }
int vpop(){ return valStack[vtop--]; }

int prec(char c){ if(c=='^')return 3; if(c=='*'||c=='/')return 2; if(c=='+'||c=='-')return 1; return 0; }

void infixToPostfix(char in[], char post[]){
    int i,j=0; char c;
    for(i=0; i<strlen(in); i++){
        c=in[i];
        if(isdigit(c)) post[j++]=c;
        else if(c=='(') push(c);
        else if(c==')'){ while(peek()!='(') post[j++]=pop(); pop(); }
        else{ while(top!=-1 && prec(peek())>=prec(c)) post[j++]=pop(); push(c); }
    }
    while(top!=-1) post[j++]=pop();
    post[j]='\0';
}

int evalPostfix(char post[]){
    int i,a,b; char c;
    for(i=0;i<strlen(post);i++){
        c=post[i];
        if(isdigit(c)) vpush(c-'0');
        else{
            b=vpop(); a=vpop();
            switch(c){
                case '+':vpush(a+b);break;
                case '-':vpush(a-b);break;
                case '*':vpush(a*b);break;
                case '/':vpush(a/b);break;
                case '^':vpush(pow(a,b));break;
            }
        }
    }
    return vpop();
}

int main(){
    char in[SIZE], post[SIZE];
    printf("Enter infix: "); scanf("%s",in);
    infixToPostfix(in,post);
    printf("Postfix: %s\n",post);
    printf("Result: %d\n",evalPostfix(post));
    return 0;
}
*/