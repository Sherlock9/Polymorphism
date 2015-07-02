#include <iostream>
#include "rect.h"

float Rect::area(){	
	return panjang*lebar;
}

float Rect::circum(){	
	return (panjang+lebar)*2;
}

void Rect::detail(){
	cout<< jenis_shape<< endl;
	cout<< "Panjang		: "<< panjang<< endl;
	cout<< "Lebar		: "<< lebar<< endl;
	cout<< "Luas		: "<< area()<< endl;
	cout<< "Keliling	: "<< circum()<< endl<< endl;
}

Rect::Rect(){
	panjang=0;
	lebar=0;
	jenis_shape = "Persegi Panjang";
}

Rect::Rect(int panjang2, int lebar2){
	panjang = panjang2;
	lebar = lebar2;
	jenis_shape = "Persegi Panjang";
}
