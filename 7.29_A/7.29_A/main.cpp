//
//  main.cpp
//  7.29_A
//
//  Created by 李茂琦 on 11/18/15.
//  Copyright © 2015 李茂琦. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string.h>
#include <string>
using namespace std;

char expression[250], post[250];
stack<char> op;
stack<double> num;

bool isNum (char ch)
{
    if ( ch >= '0' && ch <= '9' )
        return true;
    return false;
}

int opToInt (char op)
{
    if ( op == '+' ) return 1;
    if ( op == '-' ) return 2;
    if ( op == '*' ) return 3;
    if ( op == '/' ) return 4;
    return 0;
}

void splitExp(char* exp)
{
    int k = 0;
    memset(post, '\0', sizeof(post));
    for (int i = 0; i < strlen(exp); ++i) {
        if ( exp[i] == ' ' )
            continue;
        post[k++] = ' ';
        while ( isNum(exp[i]) )
            post[k++] = exp[i++];
        int curOp = opToInt(exp[i]);
        if ( curOp != 0 ) {
            if ( curOp < 3 ) {
                while ( !op.empty() ) {
                    post[k++] = op.top();
                    op.pop();
                }
            }
            else if ( curOp > 2) {
                while ( !op.empty() && opToInt(op.top()) > 2 ) {
                    post[k++] = op.top();
                    op.pop();
                }
            }
            op.push(exp[i]);
        }
    }
    while ( !op.empty() ) {
        post[k++] = op.top();
        op.pop();
    }
}

double calculate()
{
    while ( !num.empty() ) {
        num.pop();
    }
    for (int i = 0; i < strlen(post); ++i) {
        if ( post[i] == ' ' )
            continue;
        double curNum = 0;
        bool hasNum = false;
        while ( isNum(post[i]) ) {
            curNum *= 10;
            curNum += post[i++] - '0';
            hasNum = true;
        }
        if ( hasNum )
            num.push(curNum);
        if ( opToInt(post[i]) != 0) {
            double num1 = num.top();
            num.pop();
            double num2 = num.top();
            num.pop();
            switch ( post[i] ) {
                case '+':
                    num.push( num1 + num2 );
                    break;
                case '-':
                    num.push( num2 - num1 );
                    break;
                case '*':
                    num.push( num1 * num2 );
                    break;
                case '/':
                    num.push( num2 / num1 );
                default:
                    break;
            }
        }
    }
    return num.top();
}

int main(int argc, const char * argv[]) {
    
    while (gets(expression)) {
        if (strcmp(expression, "0") == 0)
            break;
        else {
            splitExp(expression);
            printf("%.2f\n", calculate());
        }
    }
    
    return 0;
}
