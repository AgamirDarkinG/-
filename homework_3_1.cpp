﻿// lesson_2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Calculator {

    double num1;
    double num2;

public:
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return(1);
        }
        else {
            std::cout << "Неверный ввод!" << std::endl;
            return(0);
        }
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return(1);
        }
        else {
            std::cout << "Неверный ввод!" << std::endl;
            return(0);
        }
    }

    double add() {
        return(num1 + num2);
    }
    double subtract_1_2() {
        return(num1 - num2);
    }
    double subtract_2_1() {
        return(num2 - num1);
    }
    double multiply() {
        return(num1 * num2);
    }
    double divide_1_2() {
        return(num1 / num2);
    }
    double divide_2_1() {
        return(num2 / num1);
    }
};

int main(int argc, char** argv)
{
    int num_1, num_2;
    Calculator a;
               
    while (1 == 1) {
        
        std::cout << "Введите num1: ";
        std::cin >> num_1;
        while (a.set_num1(num_1) == 0) {
            std::cout << "Введите num1: ";
            std::cin >> num_1;
        }

        std::cout << "Введите num2: ";
        std::cin >> num_2;
        while (a.set_num2(num_2) == 0) {
            std::cout << "Введите num2: ";
            std::cin >> num_2;
        }

        std::cout << "num1 + num2 = " << a.add() << std::endl;
        std::cout << "num1 - num2 = " << a.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << a.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << a.multiply() << std::endl;
        std::cout << "num1 / num2 = " << a.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << a.divide_2_1() << std::endl;
    }
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