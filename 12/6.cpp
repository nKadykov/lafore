#include <iostream>
#include <fstream>

class Name { // класс работника
    unsigned long number; // номер
    std::string name; // имя
    std::string surName; // фамилия
    std::string lastName; // отчество
public:
    Name() {} // конструктор по умолчанию
    void getData(); // метод для получения данных от пользователя
    void putData() const; // метод для вывода данных на экран
    void fileout(); // метод для вывод данных в файл
    void filein(int n); // метод для ввода данных из файла по номеру работника
    static int count(); // функция, возвращающая число записей в файле
};

int main() {
    Name n; // инициализация объекта работника
    char ch; // символ ответа пользователя
    do {
        n.getData(); // получение данных от пользователя
        n.fileout(); // вывод данных в файл
        std::cout << "Continue? (y/n): ";
        std::cin >> ch; 
    }
    while(ch == 'y'); // выход, если ch не 'y'
    int number = Name::count(); // получение количества записей в файле
    for(int i = 1; i <= number; i++) {
        std::cout << "Out " << i << '\n';
        n.filein(i); // чтение работника по номеру из файла
        n.putData(); // вывод данных на экран
    }
    return 0;
}

void Name::getData() { // определение метода для ввода данных от пользователя
    std::cout << "Enter: number name surname last name: ";
    std::cin >> number >> name >> surName >> lastName;
}

void Name::putData() const { // определение метода для вывода данных на экран
    std::cout << "Employee " << number << " \nName: " << name << "\nSurname: " << surName << "\nLast name: " << lastName << std::endl; 
}

void Name::fileout() { // определение метода для файлового вывода данных
    std::ofstream out;
    out.open("6.txt", std::ios::app);
    if(!out) {
        std::cout << "Can't open file\n";
        exit(-1);
    }
    out << number << ' ' << name << ' ' << surName << ' ' << lastName << ' ';
}

void Name::filein(int n) { // определение метода для ввода данных из файла
    std::ifstream in; // инициализация входного потока
    in.open("6.txt"); // открытие файла для чтения
    if(!in) { // проверка ошибок при открытии файла
        std::cout << "Can't open file\n";
        exit(-1);
    }
    int count = 1;
    while(in >> number >> name >> surName >> lastName && count != n) { // поиск записи с нужным номером
        count++;
    }
}

int Name::count() { // получение числа записей в файле
    std::ifstream in; // инициализация входного потока
    in.open("6.txt"); // открытие файла для записи
    if(!in) { // проверка ошибок при открытии файла
        std::cout << "Can't open file\n";
        exit(-1);
    }
    std::string name, surName, lastName; // так как функция статическая, она не имеет доступ к полям класса, поэтому создаём локальные переменные для чтения данных
    unsigned long number;
    int count = 0;
    while(in >> number >> name >> surName >> lastName) { // поиск количества записей
        count++;
    }
    return count;
}