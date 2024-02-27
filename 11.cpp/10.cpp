#include <iostream>
#include <cstring>
using namespace std;

const int LEN = 80;
const int MAX = 40;

class Token {
public:
    virtual float getNumber() const = 0;
    virtual char getOperator() const = 0;
};

class Operator : public Token {
    char oper;
public:
    Operator(char op): oper(op) {}
    char getOperator() const {
        return oper;
    }
    float getNumber() const {
        return 0;
    }
};

class Number : public Token {
    float num;
public:
    Number(float n): num(n) {}
    float getNumber() const {
        return num;
    }
    char getOperator() const {
        return '0';
    }
};

class Stack {
    Token* arr[MAX];
    int top;
public:
    Stack() {
        top = 0;
    }
    void push(Token*var) {
        arr[++top] = var;
    }
    Token* pop() {
        return arr[top--];
    }
    int gettop() const {
        return top;
    }
    bool isNumber() const {
        Number* pNum;
        if(pNum == dynamic_cast<Number*>(arr[top])) {
            return true;
        }
        else {
            return false;
        }
    }
};

class Express {
    Stack s;
    char* str;
    int len;
public:
    Express(char* ptr) {
        str = ptr;
        len = strlen(str);
    }
    void parse();
    float solve();
};

void Express::parse() {
    char ch;
    Token* lastval;
    Token* lastop;
    float result;
    Number* num;
    Operator* op;
    char* current = str;
    while(current[0]) {
        ch = current[0];
        if(ch >= '0' && ch <= '9') {
            result = strtof(current, &current);
            num = new Number(result);
            s.push(num);
        }
        else if(ch == '+' || ch == '-' || ch == '/' || ch == '*') {
            if(s.gettop() == 1) {
                op = new Operator(ch);
                s.push(op);
            }
            else {
                lastval = s.pop();
                lastop = s.pop();
                if((ch == '*' || ch == '/') && (lastop->getOperator() == '+' || lastop->getOperator() == '-')) {
                    s.push(lastop);
                    s.push(lastval);
                }
                else {
                    switch (lastop->getOperator()) {
                        case '+':
                            result = s.pop()->getNumber() + lastval->getNumber();
                            num = new Number(result);
                            s.push(num);
                            break;
                        case '-':
                            result = s.pop()->getNumber() - lastval->getNumber();
                            num = new Number(result);
                            break;
                        case '*':
                            result = s.pop()->getNumber() * lastval->getNumber();
                            num = new Number(result);
                            s.push(num);
                            break;
                        case '/':
                            result = s.pop()->getNumber() / lastval->getNumber();
                            num = new Number(result);
                            s.push(num);
                            break;
                        default:
                            cout << "Unknown operation\n";
                            exit(1);
                    }
                }
                Operator* op = new Operator(ch);
                s.push(op);
            }
            current++;
        }
        else {
            cout << "Incorrect symbol\n";
            exit(1);
        }
    }
}

float Express::solve() {
    Token* lastval;
    float result;
    Number* num;
    while(s.gettop() > 1) {
        lastval = s.pop();
        switch(s.pop()->getOperator()) {
            case '+':
                result = s.pop()->getNumber() + lastval->getNumber();
                num = new Number(result);
                s.push(num);
                break;
            case '-':
                result = s.pop()->getNumber() - lastval->getNumber();
                num = new Number(result);
                s.push(num);
                break;
            case '*':
                result = s.pop()->getNumber() * lastval->getNumber();
                num = new Number(result);
                s.push(num);
                break;
            case '/':
                result = s.pop()->getNumber() / lastval->getNumber();
                num = new Number(result);
                s.push(num);
                break;
            default:
                cout << "Unknown operation\n";
                exit(1);
        }
    }
    return s.pop()->getNumber();
}

int main() {
    char result;
    char str[LEN];

    do {
        cout << "Enter expression: ";
        ws(cin);
        cin.get(str, LEN);
        Express* e = new Express(str);
        e->parse();

        cout << "Result: " << e->solve() << endl;
        delete e;

        cout << "Continue? (y/n): ";
        cin >> result;
    }
    while(result != 'n');

    return 0;
}