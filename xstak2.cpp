#include <iostream>

const int MAX = 3;

class Stack {
    int st[MAX];
    int top;
public:
    class Full {};
    class Empty {};
    Stack() {
        top = -1;
    }
    void push(int var) {
        if(top >= MAX - 1) {
            throw Full();
        }
        st[++top] = var;
    }
    int pop() {
        if(top < 0) {
            throw Empty();
        }
        return st[top--];
    }
};

int main() {
    Stack s1;

    try {
        s1.push(11);
        s1.push(22);
        s1.push(33);
        // s1.push(44);

        std::cout << "1: " << s1.pop() << std::endl;
        std::cout << "2: " << s1.pop() << std::endl;
        std::cout << "3: " << s1.pop() << std::endl;
        std::cout << "4: " << s1.pop() << std::endl;
    }
    catch(Stack::Full) {
        std::cout << "Error: full" << std::endl;
    }
    catch(Stack::Empty) {
        std::cout << "Error: empty" << std::endl;
    }

    return 0;
}