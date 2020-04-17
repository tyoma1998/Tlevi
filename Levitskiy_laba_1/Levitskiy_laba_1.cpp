#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;
//предупреждаю!!! пожалуйста не читайте мои комменты ибо я могу чего-то не заметить и не удалить

struct Point {
	int x;
	int y;
};

class Figure {
protected:
	Point* ver;
public:
	Figure(struct Point* korono_virys) {
		ver = korono_virys;
	};
	virtual float Perim() = 0;
	virtual float Plosh() = 0;
};

class triangle : public Figure {
public:
	triangle(struct Point ver[2]) : Figure(ver) {};
	float Perim() {
		return sqrt(powf((ver[1].x - ver[0].x), 2) + (powf((ver[1].y - ver[0].y), 2)) + sqrt((powf((ver[2].x - ver[1].x), 2)) + (powf((ver[2].y - ver[1].y), 2))) + sqrt((powf((ver[2].x - ver[0].x), 2)) + (powf((ver[2].y - ver[0].y), 2))));

	}
	float Plosh() { //говорю честно посмотрел формулу по инету, чтобы считал по координатм всё, ибо высчитывать то одну сторону, потом высоту, ну это не дело
		return ((ver[0].y * ver[2].y) / 2) * (ver[2].x - ver[0].x) + ((ver[2].y * ver[1].y) / 2) * (ver[1].x - ver[2].x) - ((ver[0].y * ver[1].y) / 2) * (ver[1].x - ver[0].x);
	}
};


class Square : public Figure {
public:
	Square(struct Point ver[2]) : Figure(ver) {};
	float Perim() {
		return (sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2)))) * 4;
	}
	float Plosh() {
		return (sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2)))) * (sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2))));
	}
};

class rround : public Figure {
public:
	rround(struct Point ver[2]) : Figure(ver) {};
	float Perim() {
		return sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2))) * 3.14 * 2;
	}
	float Plosh() {
		return sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2))) * sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2))) * 3.14;
	}
};

class rectangle : public Figure {
public:
	rectangle(struct Point ver[2]) : Figure(ver) {};
	float Perim() {
		return (sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2))) + sqrt((powf((ver[2].x - ver[1].x), 2)) + (powf((ver[2].y - ver[1].y), 2)))) * 2;
	}
	float Plosh() {
		return sqrt((powf((ver[1].x - ver[0].x), 2)) + (powf((ver[1].y - ver[0].y), 2)) * sqrt(powf((ver[2].x - ver[1].x), 2)) + (powf((ver[2].y - ver[1].y), 2)));
	}
};



int main()
{
	setlocale(LC_ALL, "");
	int i;
	int m[100];
	Figure* figurs[100];// у нас будет 100 фигур
	for (i = 0; i < 100; i++) {
		m[i] = rand() % 100;
	}

	for (i = 0; i < 100; i++) {
		switch (i % 4) {
		case 0: {// будет у нас треугольничек, и задаём ему вершины
			Point* ver = new Point[2];
			ver[0].x = rand() % 100;
			ver[0].y = rand() % 100;
			ver[1].x = rand() % 100;
			ver[1].y = rand() % 100;
			ver[2].x = rand() % 100;
			ver[2].y = rand() % 100;
			figurs[i] = new triangle(ver);
			break;
		}
		case 1: {//тут у нас квадратик, а квадрату хватит и одной стороны чтобы посчитать его площадь и периметр
			Point* ver = new Point[2];
			ver[0].x = rand() % 100;
			ver[0].y = rand() % 100;
			ver[1].x = rand() % 100;
			ver[1].y = rand() % 100;
			figurs[i] = new Square(ver);
			break;
		}
		case 2: {//тут у нас кружок, та же история что и с квадратом, нам хватит одного радиуса
			Point* ver = new Point[2];
			ver[0].x = rand() % 100;
			ver[0].y = rand() % 100;
			ver[1].x = rand() % 100;
			ver[1].y = rand() % 100;
			figurs[i] = new rround(ver);
			break;
		}
		case 3: {//тут у нас будет прямоугольник
			Point* ver = new Point[2];
			ver[0].x = rand() % 100;
			ver[0].y = rand() % 100;
			ver[1].x = rand() % 100;
			ver[1].y = rand() % 100;
			ver[2].x = rand() % 100;
			ver[2].y = rand() % 100;
			figurs[i] = new rectangle(ver);
			break;
		}
		}
	}

	for (int i = 0; i < 100; i++) {
		switch (i % 4) {
		case 0: {
			cout << "Треугольник:" << endl;
			break;
		}
		case 1: {
			cout << "Квадрат:" << endl;
			break;
		}
		case 2: {
			cout << "Круг:" << endl;
			break;
		}
		case 3: {
			cout << "Прямоугольник:" << endl;
			break;
		}
		}
		cout << "Периметр = " << figurs[i]->Perim() << endl;
		cout << "Площадь = " << figurs[i]->Plosh() << endl << endl;
	}





}