#include <iostream>

const int MAX = 3;

template<class Type>
class Queue {
    Type q[MAX];
    int head;
    int tail;
    int count;
public:
    class Full {};
    class Empty {};
    Queue() {
        head = -1;
        tail = -1;
    }
    void put(Type var) {
        if(count >= MAX) {
            throw Full();
        }
        q[++tail] = var;
        ++count;
        if(tail >= MAX - 1) {
            tail = -1;
        }
    }
    Type get() {
        if(count <= 0) {
            throw Empty();
        }
        Type temp = q[++head];
        --count;
        if(head >= MAX - 1) {
            head = -1;
        }
        return temp;
    }
};

int main() {
    Queue<float> q1;
    float data;
    char ch = 'y';
    do {
        try {
            std::cout << "Enter p for input and g for output: ";
            std::cin >> ch;
            if(ch == 'p') {
                std::cout << "Enter number: ";
                std::cin >> data;
                q1.put(data);
            }
            if(ch == 'g') {
                std::cout << "Data = " << q1.get() << std::endl;
            }
        }
        catch(Queue<float>::Full) {
            std::cout << "Full" << std::endl;
        }
        catch(Queue<float>::Empty) {
            std::cout << "Empty" << std::endl;
        }
    }
    while(ch != 'n');

    return 0;
}