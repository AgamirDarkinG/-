// homework_5_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Figure {
protected:
	std::string name_Figure;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;

public:
	std::string getNameFigure() { return name_Figure; }

	int geta() { return a; }
	int getb() { return b; }
	int getc() { return c; }
	int getd() { return d; }

	int getA() { return A; }
	int getB() { return B; }
	int getC() { return C; }
	int getD() { return D; }
};


class Triangle : public Figure
{
public:
	Triangle(int a_, int b_, int c_, int A_, int B_, int C_)
	{
		name_Figure = "Треугольник";
		a = a_;
		b = b_;
		c = c_;
		A = A_;
		B = B_;
		C = C_;
	}
};

class rightTriangle : public Triangle
{
public:
	rightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90)
	{
		Triangle::name_Figure = "Прямоугольный треугольник";
	};
};

class isoscelesTriangle : public Triangle
{
public:
	isoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
	{
		Triangle::name_Figure = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
public:
	equilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60)
	{
		Triangle::name_Figure = "Равносторонний треугольник";
	};
};

class Quadrilateral : public Figure
{

public:
	Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_)
	{
		name_Figure = "Четырехугольник";

		a = a_;
		b = b_;
		c = c_;
		d = d_;

		A = A_;
		B = B_;
		C = C_;
		D = D_;
	}
};

class Rectangle : public Quadrilateral
{
public: 
	Rectangle(int a, int b)	: Quadrilateral(a, b, a, b, 90, 90, 90, 90)
	{
		Quadrilateral::name_Figure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
public:
	Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90)
	{
		Quadrilateral::name_Figure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
public:
	Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B)
	{
		Quadrilateral::name_Figure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
public:
	Rhomb(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B)
	{
		Quadrilateral::name_Figure = "Ромб";
	}
};

void printTriangle(Figure& figure) {

	std::cout << std::endl;
	std::cout << figure.getNameFigure() << ":" << std::endl;

	std::cout << "Стороны: ";
	std::cout << "a=" << figure.geta() << " b=" << figure.getb() << " с=" << figure.getc() << std::endl;
	
	std::cout << "Углы: ";
	std::cout << "А=" << figure.getA() << " В=" << figure.getB() << " С=" << figure.getC() << std::endl;
}
void printQuadrilateral(Figure& figure) {

	std::cout << std::endl;
	std::cout << figure.getNameFigure() << ":" << std::endl;

	std::cout << "Стороны: ";
	std::cout << "a=" << figure.geta() << " b=" << figure.getb() << " с=" << figure.getc() << " d=" << figure.getd() << std::endl;
	
	std::cout << "Углы: ";
	std::cout << "А=" << figure.getA() << " В=" << figure.getB() << " С=" << figure.getC() << " D=" << figure.getD() << std::endl; }
	
int main() {
	
	setlocale(0, "");

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	printTriangle(Triangle1);

	rightTriangle rightTriangle1(10, 20, 30, 50, 60);
	printTriangle(rightTriangle1);

	isoscelesTriangle isoscelesTriangle1(10, 20, 50, 60);
	printTriangle(isoscelesTriangle1);

	equilateralTriangle equilateralTriangle1(30);
	printTriangle(equilateralTriangle1);

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	printQuadrilateral(Quadrilateral1);

	Rectangle Rectangle1(10, 20);
	printQuadrilateral(Rectangle1);

	Square Square1(20);
	printQuadrilateral(Square1);

	Parallelogram Parallelogram1(20, 30, 30, 40);
	printQuadrilateral(Parallelogram1);

	Rhomb Rhomb1(30, 30, 40);
	printQuadrilateral(Rhomb1);
}