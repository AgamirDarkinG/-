// homework_5_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Figure {
	int sides_count = 0;
	std::string nameFigure;

public:
	Figure() : Figure(0, "Фигура") {};
	Figure(int sidescount, std::string namefigure)
	{
		sides_count = sidescount;
		nameFigure = namefigure;
	};

	int get_sides_count() { return sides_count; }
	std::string get_name() { return nameFigure; }
};

class Triangle : public Figure {
public:

	Triangle() : Figure(3, "Треугольник") {};
};

class Quadrilateral : public Figure {
public:

	Quadrilateral() : Figure(4, "Четырехугольник") {};
};

void print(Figure& xFig) {
	std::cout << xFig.get_name() << ": " << xFig.get_sides_count() << std::endl;
}

int main()
{
	setlocale(0, ""); 

	std::cout << std::endl << "Количество сторон: " << std::endl;

	Figure Figure1;
	print(Figure1);

	Triangle Triangle1;
	print(Triangle1);

	Quadrilateral Quadrilateral1;
	print(Quadrilateral1);
};
