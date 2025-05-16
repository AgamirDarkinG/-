// homework_4_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstring>﻿
#include <fstream>
#include <string>

class Adress {

    std::string NameCity_;
    std::string NameStreet_;
    int NumberHouse_ = 0;
    int NumberApartment_ = 0;
    std::string FullAdress_;

public:
    
    Adress(std::string NameCity, std::string NameStreet, int NumberHouse, int NumberApartment) {
        NameCity_ = NameCity;
        NameStreet_ = NameStreet;
        NumberHouse_ = NumberHouse;
        NumberApartment_ = NumberApartment;
    }    
    std::string get_output_address() {
        FullAdress_ = NameCity_ + ", " + NameStreet_ + ", " + std::to_string(NumberHouse_) + ", " + std::to_string(NumberApartment_);
        return FullAdress_;
    };
};

void printArrayForClassObjects(std::string* arrayForClassObjects, const int n) {

    std::ofstream fileOut("out.txt", std::ios_base::trunc);
    fileOut << n << std::endl;

    for (int i = n - 1; i >= 0; i--) {
        fileOut << arrayForClassObjects[i] << std::endl;
    }
    fileOut.close();
};

std::string* createTextArr(const int n) {
    std::string* TextArr = new std::string[n]{};
    return TextArr;
}

int main()
{
    setlocale(0,"");
    
    std::ifstream fileIn("in.txt");
    
    int n = 0;
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    fileIn >> n; 

    std::string* arrayForClassObjects = createTextArr(n);

    for (int i = 0; i < n; i++) {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        Adress adress(NameCity, NameStreet, NumberHouse, NumberApartment);
        arrayForClassObjects[i] = adress.get_output_address();
    };
    fileIn.close();

    printArrayForClassObjects(arrayForClassObjects, n);
    
    std::cout << "Результат работы программы в файле out.txt" << std::endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
