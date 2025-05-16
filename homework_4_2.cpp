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

void printArrayForClassObjects(std::string* arrayForClassObjects, int size) {

    std::ofstream fileOut("out.txt", std::ios_base::trunc);
    fileOut << size << std::endl;

    for (int i =  0; i < size; i++) {
        fileOut << arrayForClassObjects[i] << std::endl;
    }
    fileOut.close();
};

std::string* createTextArr(const int size)
{
    std::string* TextArr = new std::string[size]{};
    return TextArr;
}

void sort(std::string* arrayForClassObjects, int size) {
    bool swapped = 0;
    do {
        swapped = 0;
        std::string tmp;

        for (int i = size - 1; i > 0; --i) {
            if (arrayForClassObjects[i - 1] > arrayForClassObjects[i])  {
                tmp = arrayForClassObjects[i];
                arrayForClassObjects[i] = arrayForClassObjects[i - 1];
                arrayForClassObjects[i - 1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped);
}
int main()
{
    setlocale(0,"");
    
    std::ifstream fileIn("in.txt");
    
    int size = 0;
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    fileIn >> size;

    std::string* arrayForClassObjects = createTextArr(size);

    for (int i = 0; i < size; i++)
    {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        Adress adress(NameCity, NameStreet, NumberHouse, NumberApartment);
        arrayForClassObjects[i] = adress.get_output_address();
    };
    fileIn.close();

    sort(arrayForClassObjects, size);
    printArrayForClassObjects(arrayForClassObjects, size);
    
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
