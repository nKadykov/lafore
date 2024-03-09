#include <iostream>

template<class Type>
struct Link {
    Type data;
    Link* next;
};

template<class Type>
class Linklist {
    Link<Type>* first;
public:
    Linklist() {
        first = NULL;
    }
    void additem(Type d);
    void display();
};

template<class Type>
void Linklist<Type>::additem(Type d) {
    Link<Type>* newlink = new Link<Type>;

    newlink->data = d;
    newlink->next = first;
    first = newlink;
}

template<class Type>
void Linklist<Type>::display() {
    Link<Type>* current = first;
    while(current != NULL) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

int main() {
    Linklist<double> ld;
    ld.additem(151.5);
    ld.additem(262.6);
    ld.additem(373.7);
    ld.display();

    Linklist<char> lch;
    lch.additem('a');
    lch.additem('b');
    lch.additem('c');
    lch.display();
    return 0;
}