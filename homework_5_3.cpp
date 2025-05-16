// homework_5_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

class Figure {
protected:
	std::string name_Figure = "Фигура";
	bool check = false;
	int sides = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int A = 0;
	int B = 0;
	int C = 0;
	int D = 0;

	virtual bool metod_Check() {
		if (sides == 0)	{
			return true;
		}
		else {
			return false;
		}
	};

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

	virtual void printFigure() {
		std::cout << std::endl;
		std::cout << name_Figure << ":" << std::endl;
		if (metod_Check()) {
			std::cout << "Правильная" << std::endl;
		}
		else { std::cout << "Неправильная" << std::endl; }

		std::cout << "Количество сторон: " << sides << std::endl;
	}
};


class Triangle : public Figure
{
protected:
	bool metod_Check() override 
	{
		if ((A + B + C) == 180)	{
			return true;
		} 
		else {
			return false;
		}
	};

public:
	Triangle(int a_, int b_, int c_, int A_, int B_, int C_)
	{
		name_Figure = "Треугольник";
		sides = 3;
		a = a_;
		b = b_;
		c = c_;
		A = A_;
		B = B_;
		C = C_;
		check = metod_Check();
	}
	void printFigure() override	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << geta() << ", b = " << getb() << ", с = " << getc() << std::endl;

		std::cout << "Углы:";
		std::cout << " А = " << getA() << ", В = " << getB() << ", С = " << getC() << std::endl;
	}
};

class rightTriangle : public Triangle
{
protected:
	bool metod_Check() override	{
		if (Triangle::metod_Check() && (C == 90)) {
			return true;
		}
		else {
			return false;
		};
	};

public:
	rightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
	{
		Triangle::name_Figure = "Прямоугольный треугольник";
	};
};

class isoscelesTriangle : public Triangle
{
protected:
	bool metod_Check() override
	{
		if (Triangle::metod_Check() && (a == c && A == C)) {
			return true;
		}
		else {
			return false;
		};
	};

public:
	isoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
	{
		Triangle::name_Figure = "Равнобедренный треугольник";
	};
};

class equilateralTriangle : public Triangle
{
private:
	bool CheckEquilateralTriangle()
	{
		if ((a == b && b == c) && ((A == 60) && (B = 60) && (C = 60))) {
			return true;
		}
		else {
			return false;
		};
	}

public:
	equilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C)
	{
		Triangle::name_Figure = "Равносторонний треугольник";
	};

protected:
	bool metod_Check() override	{
		if (Triangle::metod_Check() && (CheckEquilateralTriangle())) {
			return true;
		}
		else {
			return false;
		};
	};
};

class Quadrilateral : public Figure
{
protected:
	virtual bool metod_Check()
	{
		if ((A + B + C + D) == 360)	{
			return true;
		}
		else {
			return false;
		}
	};
	bool metodCheckSideLengthACiBD()
	{
		if (a == c && b == d) {
			return true;
		}
		else {
			return false;
		}
	};
	bool metodCheckSideLengthACBD()
	{
		if (a == b && b == c && c == d)	{
			return true;
		}
		else {
			return false;
		}
	};	
	bool metodCheckAngleabcd90()
	{
		if (A == 90 && B == 90 && C == 90 && D == 90) {
			return true;
		}
		else {
			return false;
		}
	};
	bool metodCheckAngleACiBD()
	{
		if (A == C && B == D) {
			return true;
		}
		else {
			return false;
		}
	};
public:
	Quadrilateral(int a_, int b_, int c_, int d_, int A_, int B_, int C_, int D_)
	{
		name_Figure = "Четырехугольник";
		sides = 4;
		a = a_;
		b = b_;
		c = c_;
		d = d_;

		A = A_;
		B = B_;
		C = C_;
		D = D_;
	}
	void printFigure() override	{
		Figure::printFigure();

		std::cout << "Стороны:";
		std::cout << " a = " << geta() << ", b = " << getb() << ", с = " << getc() << ", d = " << getd() << std::endl;
		std::cout << "Углы:";
		std::cout << " А = " << getA() << ", В = " << getB() << ", С = " << getC() << ", D = " << getD() << std::endl;
	}

};

class Rectangle : public Quadrilateral
{
protected:
	bool metod_Check() override
	{
		if (Quadrilateral::metod_Check() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleabcd90()) {
			return true;
		}
		else {
			return false;
		}
	};

public:
	Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D)
	{
		Quadrilateral::name_Figure = "Прямоугольник";
	}
};

class Square : public Quadrilateral
{
protected:
	bool metod_Check() override
	{
		if (Quadrilateral::metod_Check() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleabcd90())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

public:
	Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D)
	{
		Quadrilateral::name_Figure = "Квадрат";
	}
};

class Parallelogram : public Quadrilateral
{
protected:
	bool metod_Check() override
	{
		if (Quadrilateral::metod_Check() && Quadrilateral::metodCheckSideLengthACiBD() && Quadrilateral::metodCheckAngleACiBD()) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D)
	{
		Quadrilateral::name_Figure = "Параллелограмм";
	}
};

class Rhomb : public Quadrilateral
{
protected:
	bool metod_Check() override
	{
		if (Quadrilateral::metod_Check() && Quadrilateral::metodCheckSideLengthACBD() && Quadrilateral::metodCheckAngleACiBD()) {
			return true;
		}
		else {
			return false;
		}
	}
public:
	Rhomb(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrilateral(a, b, c, d, A, B, C, D)
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
	std::cout << "А=" << figure.getA() << " В=" << figure.getB() << " С=" << figure.getC() << " D=" << figure.getD() << std::endl;
}

int main() {

	setlocale(0, "");

	Figure Figure1;
	Figure1.printFigure();

	Triangle Triangle1(10, 20, 30, 50, 60, 70);
	Triangle1.printFigure();

	rightTriangle rightTriangle1(10, 20, 30, 50, 60, 90);
	rightTriangle1.printFigure();

	rightTriangle rightTriangle2(10, 20, 30, 50, 40, 90);
	rightTriangle2.printFigure();

	isoscelesTriangle isoscelesTriangle1(10, 20, 10, 50, 60, 50);
	isoscelesTriangle1.printFigure();

	equilateralTriangle equilateralTriangle1(30, 30, 30, 60, 60, 60);
	equilateralTriangle1.printFigure();

	Quadrilateral Quadrilateral1(10, 20, 30, 40, 50, 60, 70, 80);
	Quadrilateral1.printFigure();

	Rectangle Rectangle1(10, 20, 10, 20, 90, 90, 90, 90);
	Rectangle1.printFigure();

	Square Square1(20, 20, 20, 20, 90, 90, 90, 90);
	Square1.printFigure();

	Parallelogram Parallelogram1(20, 30, 20, 30, 30, 40, 30, 40);
	Parallelogram1.printFigure();

	Rhomb Rhomb1(30, 30, 30, 30, 30, 40, 30, 40);
	Rhomb1.printFigure();
}