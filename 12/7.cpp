#include <iostream>
#include <fstream>

class Name { // класс работника
    unsigned long number; // номер
    std::string name; // имя
    std::string surName; // фамилия
    std::string lastName; // отчество
    static std::fstream file; // статическое поле класса для потока
public:
    void getData(); // метод для получения данных от пользователя
    void putData() const; // метод для вывода данных на экран
    static void fileopen(); // статический метод для открытия файла
    static void reset(); // статический метод для установки указателя в начало файла
    void fileout(); // метод для вывод данных в файл
    void filein(int n); // метод для ввода данных из файла по номеру работника
    static int count(); // функция, возвращающая число записей в файле
};

std::fstream Name::file; // определение статической переменной класса вне тела класса

int main() {
    Name n; // инициализация объекта работника
    char ch; // символ ответа пользователя
    Name::fileopen(); // открытие файла для чтения/записи
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

void Name::fileopen() { // определение метода для открытия файла
    file.open("7.txt", std::ios::app | std::ios::out | std::ios::in); // открытие файла для записи данный в конец файла и чтения из него
    if(!file) { // проверка на ошибку при открытии файла
        std::cout << "Can't open file\n";
        exit(-1);
    }
}

void Name::reset() { // метод для установки указателя в начало файла
    file.seekg(0);
}

void Name::fileout() { // определение метода для файлового вывода данных
    file << number << ' ' << name << ' ' << surName << ' ' << lastName << ' ';
}

void Name::filein(int n) { // определение метода для ввода данных из файла
    file.seekg(0);
    int count = 1;
    while(file >> number >> name >> surName >> lastName && count != n) { // поиск записи с нужным номером
        count++;
    }
}

int Name::count() { // получение числа записей в файле
    std::string name, surName, lastName; // так как функция статическая, она не имеет доступ к полям класса, поэтому создаём локальные переменные для чтения данных
    unsigned long number;
    file.seekg(0); // установка указателя в начало файла
    int count = 0;
    while(file >> number >> name >> surName >> lastName) { // поиск количества записей
        count++;
    }
    file.clear(); // очистка битов ошибок, которые устанавливатся в цикле выше
    return count;
}