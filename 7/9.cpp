#include <iostream>

class Queue {
    enum {MAX = 10};
    int q[MAX];
    int head;
    int tail;
public:
    Queue() {
        head = 0;
        tail = 0;
    }
    void put(int var) {
        q[head++] = var;
        if(head == MAX) {
            head = 0;
        }
    }
    int get() {
        int t = q[tail++];
        if(tail == MAX) {
            tail = 0;
        }
        return t;
    }
};

int main() {
    Queue q;

    q.put(10);
    q.put(20);
    std::cout << "1: " << q.get() << std::endl;
    std::cout << "2: " << q.get() << std::endl;

    q.put(30);
    q.put(40);
    q.put(50);
    q.put(60);
    q.put(70);
    q.put(80);
    q.put(90);
    q.put(100);
    q.put(1);

    std::cout << "3: " << q.get() << std::endl;
    std::cout << "4: " << q.get() << std::endl;
    std::cout << "5: " << q.get() << std::endl;
    std::cout << "6: " << q.get() << std::endl;
    std::cout << "7: " << q.get() << std::endl;
    std::cout << "8: " << q.get() << std::endl;
    std::cout << "9: " << q.get() << std::endl;
    std::cout << "10: " << q.get() << std::endl;
    std::cout << "1: " << q.get() << std::endl;

    return 0;
}