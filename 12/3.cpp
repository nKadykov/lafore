#include <iostream>
#include <fstream> // файловые объекты и функции
#include <process.h> // функция exit()

int main(int argc, char* argv[]) {
    if(argc != 2) {
        std::cout << "Format: 3.exe name\n";
        exit(-1);
    }
    std::ifstream in; // создание объекта для входного файла
    in.open(argv[1]); // открытие входного файла
    if(!in) {
        std::cerr << "File " << argv[1] << " doesn't open\n";
        exit(-1);
    }
    in.seekg(0, std::ios::end); // переход на конец файла
    std::cout << "Size: " << in.tellg() << std::endl; // вывод позиции указателя от начала файла (в байтах)

    return 0;
}