#ifndef RECT_H
#define RECT_H
#include"shape.h"

class Rect:public Shape{
	public:
	float area();
	float circum();
	int panjang,lebar;
	Rect();
	Rect(int panjang2, int lebar2);
	void detail();
};

#endif
