#include <iostream>
using namespace std;

class Stack {
    enum {MAX = 10};
    int st[MAX];
    int top;
public:
    Stack() {
        top = 0;
    }
    void push(int var) {
        st[++top] = var;
    }
    int pop() {
        return st[top--];
    }
};

int main() {
    Stack s1;

    s1.push(11);
    s1.push(22);
    cout << "1: " << s1.pop() << '\n';
    cout << "2: " << s1.pop() << '\n';
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);
    cout << "3: " << s1.pop() << '\n';
    cout << "4: " << s1.pop() << '\n';
    cout << "5: " << s1.pop() << '\n';
    cout << "6: " << s1.pop() << '\n';
    return 0;
}