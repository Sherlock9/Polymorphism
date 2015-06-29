#ifndef SHAPE_H
#define SHAPE_H
#include <string>

using namespace std;

class Shape{
	public:
	virtual float area()=0;	
	virtual float circum()=0;
	virtual void detail()=0;
	Shape();
	void Print();
	
	string jenis_shape;
};

#endif
