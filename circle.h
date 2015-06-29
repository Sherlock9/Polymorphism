#ifndef CIRCLE_H
#define CIRCLE_H
#include"shape.h"

const float PI = 3.1415926;

class Circle:public Shape{
	public:
	float area();
	float circum();
	int jari;
	Circle();
	Circle(int jari2);
	void detail();
};

#endif
