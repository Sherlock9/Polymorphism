#include <iostream>
#include "circle.h"

float Circle::area(){	
	return PI*jari*jari;
}

float Circle::circum(){	
	return PI*2*jari;
}

void Circle::detail(){
	cout<< jenis_shape<< endl;
	cout<< "Jari-jari	: "<< jari<< endl;
	cout<< "Luas		: "<< area()<< endl;
	cout<< "Keliling	: "<< circum()<< endl<< endl;
}

Circle::Circle(){
	jari=0;
	jenis_shape = "Lingkaran";
}

Circle::Circle(int jari2){
	jari = jari2;
	jenis_shape = "Lingkaran";
}
