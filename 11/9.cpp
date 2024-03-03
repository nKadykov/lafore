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
    LinkList(LinkList& li) {
        first = NULL;
        Link* current = li.first;
        while(current) {
            additem(current->data);
            current = current->next;
        }
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
    LinkList& operator=(LinkList& li) {
        if(this == &li) {
            return *this;
        }
        Link* current = first;
        while(current) {
            first = current->next;
            delete current;
            current = first;
        }
        current = li.first;
        while(current) {
            additem(current->data);
            current = current->next;
        }
        return *this;
    }
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
        cout << current->data << ' ';
        current = current->next;
    }
    cout << endl;
}

int main() {
    LinkList* list1 = new LinkList;

    list1->additem(25);
    list1->additem(36);
    list1->additem(49);
    list1->additem(64);
    list1->display();

    LinkList list2(*list1);
    LinkList list3;
    list3 = *list1;

    delete list1;
    list2.display();
    list3.display();

    return 0;
}