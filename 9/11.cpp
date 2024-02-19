#include <iostream>
using namespace std;

struct Pair {
    int x;
    int y;
    void push();
};

class Stack {
protected:
    enum {MAX = 10};
    int st[MAX];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(int var) {
        st[++top] = var;
    }
    int pop() {
        return st[top--];
    }
};

class Stack2: public Stack {
public:
    void push(int var) {
        if(top >= MAX - 1) {
            cout << "Error" << endl;;
            exit(1);
        }
        Stack::push(var);
    }
    int pop() {
        if(top < 0) {
            cout << "Error" << endl;
            exit(1);
        }
        else
            return Stack::pop();
    }
};

class pairStack : public Stack2 {
public:
    void push(Pair p) {
        Stack2::push(p.x);
        Stack2::push(p.y);
    }
    Pair pop() {
        Pair temp;
        temp.x = Stack2::pop();
        temp.y = Stack2::pop();
        return temp;
    }
};

int main() {
    Pair p1 = {1, 2}, p2 = {2, 3};
    pairStack s1;
    s1.push(p1);
    s1.push(p2);

    Pair p;
    p = s1.pop();
    cout << p.x << ", " << p.y << endl;
    p = s1.pop();
    cout << p.x << ", " << p.y << endl;

    return 0;
}