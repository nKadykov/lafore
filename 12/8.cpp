#include <iostream>
#include <fstream>

struct Link {
    int data; // данные
    Link* next; // указатель на следующий элемент списка
};

class Linklist {
    Link* first; // указатель на первый элемент списка
public:
    Linklist() { // конструктор без аргументов
        first = NULL;
    }
    void additem(int d); // добавление элемента в список
    void display(); // вывод на экран элементов списка
    void writedata(); // запись данных списка в файл
    void readdata(); // чтение данных из файла и запись в список
};

int main() {
    char ch; // символ для выбора пользователя
    Linklist li; // создание связного списка

    while(true) {
        int data;
        std::cout << "'a' - add element in list\n'd' - display data in list\n'w' - write data to file\n'r' - read data in file and add to list\n'n' - end\nEnter: ";
        std::cin >> ch;
        switch(ch) {
            case 'a': // добавление элемента в список
                std::cout << "Enter integer for link: ";
                std::cin >> data;
                li.additem(data);
                break;
            case 'd': // вывод на экран данных списка
                li.display();
                break;
            case 'w': // запись в файл списка
                li.writedata();
                break;
            case 'r': // чтение из файла в список
                li.readdata();
                break;
            case 'n': // выход из программы
                exit(0);
            default:
                std::cout << "Unknown command\n";
        }
    }

    return 0;
}

void Linklist::additem(int d) { // добавление элемента в список
    Link* newlink = new Link;
    newlink->data = d;
    newlink->next = first;
    first = newlink;
}

void Linklist::display() { // вывод на экран данных списка
    Link* current = first;
    while(current) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}

void Linklist::writedata() { // запись в файл данных списка
    std::ofstream out("8.txt", std::ios::trunc | std::ios::binary);
    if(!out) {
        std::cout << "Can't open file\n";
        exit(-1);
    }
    Link* current = first;
    while(current) {
        out.write(reinterpret_cast<char*>(&current), sizeof(current));
        current = current->next;
    }
}

void Linklist::readdata() { // чтение данных из файла в список
    std::ifstream in("8.txt", std::ios::binary);
    if(!in) {
        std::cout << "Can't open file\n";
        exit(-1);
    }
    in.seekg(0);
    Link* current = first;
    while(!in.eof()) {
        in.read(reinterpret_cast<char*>(&current), sizeof(current));
        additem(current->data);
    }
}