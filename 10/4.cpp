#include <iostream>
using namespace std;

struct Link {
    int data;
    Link* next;
};

class LinkList {
    Link* first;
public:
    LinkList() {
        first = NULL;
    }
    ~LinkList() {
        Link* current = first;
        while(current) {
            Link* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void additem(int d);
    void display();
};

void LinkList::additem(int d) {
    Link* newLink = new Link;
    newLink->data = d;
    newLink->next = first;
    first = newLink;
}

void LinkList::display() {
    Link* current = first;
    while(current) {
        cout << current->data << '\n';
        current = current->next;
    }
}

int main() {
    LinkList li;

    li.additem(25);
    li.additem(36);
    li.additem(49);
    li.additem(64);

    li.display();

    return 0;
}