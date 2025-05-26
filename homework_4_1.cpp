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
    Adress() {}
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


int main()
{
    setlocale(0, "");

    int size = 0;
    std::string NameCity = {};
    std::string NameStreet = {};
    int NumberHouse = 0;
    int NumberApartment = 0;

    std::ifstream fileIn("in.txt");

    if (!fileIn) {
        std::cout << "Fail open file in.txt." << std::endl;
    }
    else {
        std::cout << "File in.txt is opened" << std::endl;
    }


    fileIn >> size;
    Adress* arrayForClassObjects = new Adress[size];
    for (int i = 0; i < size; i++) {
        fileIn >> NameCity >> NameStreet >> NumberHouse >> NumberApartment;
        arrayForClassObjects[i] = Adress(NameCity, NameStreet, NumberHouse, NumberApartment);
    };
    fileIn.close();


    std::ofstream fileOut("out.txt");
    fileOut << size << std::endl;
    for (int i = size - 1; i >= 0; --i) {
        fileOut << arrayForClassObjects[i].get_output_address() << std::endl;
    }
    fileOut.close();
    delete[] arrayForClassObjects;


    std::cout << "Результат работы программы в файле out.txt" << std::endl;
}
