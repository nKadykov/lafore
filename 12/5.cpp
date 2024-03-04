#include <iostream>
#include <fstream>

class Time { // описание класса Time
    unsigned int hour; // поле времени
    unsigned int minute; // поле минут
    unsigned int second; // поле секунд
public:
    Time() : hour(0), minute(0), second(0) {} // конструктор по умолчанию
    Time(unsigned int h, unsigned int m, unsigned int s) : hour(h), minute(m), second(s) {} // 
    void get_time(); // метод для ввода данных
    void put_time(); // метод для вывода данных
};

int main() {
    Time t; // инициализация объекта типа Time
    char ch = 'y'; // символ для запроса об окончании ввода
    do { // получение данных от пользователя и вывод на экран
        t.get_time();
        t.put_time();
        std::cout << "Continue? (y/n): ";
        std::cin >> ch;
    }
    while(ch == 'y'); // если ch не 'y', то выход

    return 0;
}

void Time::get_time() { // определение метода для ввода времени
    while(true) { // бесконечный цикл для получения часов
        std::cout << "Enter hour: ";
        std::cin >> hour;
        if(std::cin.good()) { // если введённое значение является числом
            if(hour < 0 || hour > 23) { // если значение не входит в диапазон
                std::cout << "Hour is between 0 and 23!" << std::endl;
            }
            else { // если значение входит в диапазон
                break; // выход из цикла
            }
        }
        else { 
            std::cin.clear(); // очистка битов ошибок
            std::cout << "Incorrect hour" << std::endl;
        }
    }
    while(true) { // бесконечный цикл для получения минут
        std::cout << "Enter minute: ";
        std::cin >> minute; // ввод минут от пользователя
        if(std::cin.good()) { // если введённое значение является числом
            if(minute < 0 || minute > 59) { // если значение не входит в диапазон
                std::cout << "Minute is between 1 and 59" << std::endl;
            }
            else { // если значение входит в диапазон
                break;
            }
        }
        else { // если введённое значение не является числом
            std::cin.clear(); // очистка битов ошибок
            std::cout << "Incorrect minute" << std::endl;
        }
    }
    while(true) { // бесконечный цикл для получения секунд
        std::cout << "Enter second: ";
        std::cin >> second; // ввод секунд от пользователя
        if(std::cin.good()) { // если введённое значение является числом
            if(second < 0 || second > 59) { // если значение не входит в диапазон
                std::cout << "Second is between 0 and 59" << std::endl; 
            }
            else { // если значение входит в диапазон
                break;
            }
        }
        else { // если значение не является числом
            std::cin.clear(); // очистка битов ошибок
            std::cout << "Incorrect second" << std::endl;
        }
    }
}
void Time::put_time() { // определение функции для вывода времени
    std::cout << "Time: ";
    char ch = ':'; // символ ':'
    if(hour < 10) { // если значение меньше десяти, то перед числом выводим 0
        std::cout << '0' << hour << ':';
    }
    else { // если значение не меньше десяти
        std::cout << hour << ':';
    }
    if(minute < 10) {
        std::cout << '0' << minute << ':';
    }
    else {
        std::cout << minute << ':';
    }
    if(second < 10) {
        std::cout << '0' << second << std::endl;
    }
    else {
        std::cout << second << std::endl;
    }
}