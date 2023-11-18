#include <iostream>
using namespace std;

struct link {
    int data;
    link* next;
};

class linklist {
    link* first;
public:
    linklist() {
        first = NULL;
    }
    void additem(int d);
    void display();
};

void linklist::additem(int d) {
    link* newlink = new link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;
}

void linklist::display() {
    link* current = first;
    while(current) {
        cout << current->data << '\n';
        current = current->next;
    }
}

int main() {
    linklist li;

    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display();

    return 0;
}