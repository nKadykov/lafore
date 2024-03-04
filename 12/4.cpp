#include <iostream>
#include <fstream>

int main() {
    std::string name, surName, lastName; // имя, фамилия, отчество
    unsigned long number; // номер сотрудника
    std::ofstream out("4.txt"); // создание потокового объекта для вывода в файл
    char ch = 'y'; // символ для ответа пользователя

    do { // цикл получения данных от пользователя и вывода в файл
        std::cout << "Enter name, surname, last name and number: "; // запрос данных
        std::cin >> name >> surName >> lastName >> number; // получение данных от пользователя
        out << name << ' ' << surName << ' ' << lastName << ' ' << number; // запись данных в файл
        std::cout << "Continue? (y/n): "; // запрос об окончании ввода
        std::cin >> ch;
    }
    while(ch == 'y'); // выход если ch не 'y'
    out.close(); // закрытие выходного потока

    std::ifstream in("4.txt"); // открытие входного потока для чтения из файла
    while(in >> name >> surName >> lastName >> number) { // цикл пока не конец файла
        std::cout << "Name: " << name << "\nSurname: " << surName << "\nLast name: " << lastName << "\nNumber: " << number << std::endl; // вывод данных в стандартный поток
    }

    return 0;
}