#ifndef SQUARE_H
#define SQUARE_H
#include"shape.h"

class Square:public Shape{
	public:
	float area();
	float circum();
	int sisi;
	Square();
	Square(int sisi2);
	void detail();
};

#endif
