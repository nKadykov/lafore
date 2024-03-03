#include <iostream>
#include <cstring>
using namespace std;
const int LEN = 80;
const int MAX = 100;

class Token {
public:
    virtual float getNumber() const = 0;
    virtual char getOperator() const = 0;
};

class Operator : public Token {
    char oper;
public:
    Operator(char op) : oper(op) {}
    char getOperator() const {
        return oper;
    }
    float getNumber() const {
        return 0.0f;
    }
};

class Number : public Token {
    float num;
public:
    Number(float n) : num(n) {}
    float getNumber() const {
        return num;
    }
    char getOperator() const {
        return '0';
    }
};

class Stack {
    Token* st[MAX];
    int top;
public:
    Stack() {
        top = 0;
    }
    void push(Token* var) {
        st[++top] = var;
    }
    Token* pop() {
        return st[top--];
    }
    int gettop() const {
        return top;
    }
    bool isNumber() const {
        Number* pNum;
        if(pNum = dynamic_cast<Number*>(st[top])) {
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {
    Stack s;
    Number n1(1.1), n2(2.2), n3(3.3), n4(4.4), n5(5.5);
    Operator o1('+'), o2('-'), o3('*'), o4('/');

    s.push(&n1);
    s.push(&o1);
    s.push(&n2);
    s.push(&o2);
    s.push(&n3);
    s.push(&o3);
    s.push(&n4);
    s.push(&o4);
    s.push(&n5);

    while(s.gettop() > 0) {
        if(s.isNumber()) {
            cout << s.pop()->getNumber();
        }
        else {
            cout << s.pop()->getOperator();
        }
        if(s.gettop() > 0) {
            cout << ' ';
        }
    }

    return 0;
}