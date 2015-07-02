#include <iostream>
#include "square.h"

float Square::area(){	
	return sisi*sisi;
}

float Square::circum(){	
	return sisi*4;
}

void Square::detail(){
	cout<< jenis_shape<< endl;
	cout<< "Sisi		: "<< sisi<< endl;
	cout<< "Luas		: "<< area()<< endl;
	cout<< "Keliling	: "<< circum()<< endl<< endl;
}

Square::Square(){
	sisi=0;
	jenis_shape = "Persegi";
}

Square::Square(int sisi2){
	sisi = sisi2;
	jenis_shape = "Persegi";
}
