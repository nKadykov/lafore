#include <iostream>

const int MAX = 100;

template <class Type>
class Stack {
    Type st[MAX];
    int top;
public:
    Stack();
    void push(Type var);
    Type pop();
};

template<class Type>
Stack<Type>::Stack() {
    top = -1;
}

template<class Type>
void Stack<Type>::push(Type var) {
    st[++top] = var;
}

template<class Type>
Type Stack<Type>::pop() {
    return st[top--];
}

int main() {
    Stack<float> s1;
    
    s1.push(1111.1F);
    s1.push(2222.2F);
    s1.push(3333.3F);
    std::cout << "1: " << s1.pop() << std::endl;
    std::cout << "2: " << s1.pop() << std::endl;
    std::cout << "3: " << s1.pop() << std::endl;
    
    Stack<long> s2;

    s2.push(123123123L);
    s2.push(234234234L);
    s2.push(345345345L);
    std::cout << "1: " << s2.pop() << std::endl;
    std::cout << "2: " << s2.pop() << std::endl;
    std::cout << "3: " << s2.pop() << std::endl;

    return 0;
}