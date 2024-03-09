#include <iostream>

const int MAX = 3;

template<class Type>
class Queue {
    Type q[MAX];
    int head;
    int tail;
public:
    Queue() {
        head = -1;
        tail = -1;
    }
    void put(Type var) {
        q[++tail] = var;
        if(tail >= MAX - 1) {
            tail = -1;
        }
    }
    Type get() {
        Type temp = q[++head];
        if(head >= MAX - 1) {
            head = -1;
        }
        return temp;
    }
};

int main() {
    Queue<float> q1;
    q1.put(1111.1F);
    q1.put(2222.2F);
    q1.put(3333.3F);
    std::cout << "1: " << q1.get() << std::endl;
    std::cout << "2: " << q1.get() << std::endl;
    q1.put(4444.4F);
    q1.put(5555.5F);
    std::cout << "3: " << q1.get() << std::endl;
    q1.put(6666.6F);
    std::cout << "4: " << q1.get() << std::endl;
    std::cout << "5: " << q1.get() << std::endl;
    std::cout << "6: " << q1.get() << std::endl;

    Queue<long> q2;
    q2.put(123123123L);
    q2.put(234234234L);
    q2.put(345345345L);
    std::cout << "1: " << q2.get() << std::endl;
    std::cout << "2: " << q2.get() << std::endl;
    std::cout << "3: " << q2.get() << std::endl;

    return 0;
}