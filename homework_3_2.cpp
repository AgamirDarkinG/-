//

#include <iostream>

class Counter {
    int i;
public:    
    Counter(int i) {
        this->i = i;
    }
    Counter() {
        this->i = 1;
    }

    
    void plus() {
        i++;
    }
    void minus() {
        i--;
    }   
    void result() {
        std::cout << i << "\n";
    }
};

int main(int argc, char** argv)
{
   
    std::string a;
    int b;
    char m = '1';
       
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> a;
    if (a == "да" || a == "ДА" || a == "yes") || a == "y") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> b;
        Counter i(b);
    };
    else { 
        Counter i; 
    }
            
    while (m != 'x') {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> m;
        switch (m) {
        case '+':
            i.plus();
            break;
        case '-':
            i.minus();
            break;
        case '=':
            i.result();
            break;
        case 'x':
            std::cout << "До свидания!" << std::endl;
            break;
        case 'х':
            std::cout << "До свидания!" << std::endl;
            break;
        default:
            std::cout << "Неправильная команда!" << "\n";
            break;
        }
    }
    return 0;      
}