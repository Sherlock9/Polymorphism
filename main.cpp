#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "shape.h"
#include "rect.h"
#include "circle.h"
#include "square.h"

using namespace std;
void main_menu();
void tampil_bentuk();
void tambah_bentuk();
void hapus_bentuk();
void tampil_semua();
void tampil_lingkaran();
void tampil_persegi();
void tampil_persegipanjang();

vector <Shape*> shape;

int pilihan;

int main(){
	
	/*Shape* a=new Circle();
	((Circle*)a)->jari=10;
	cout<<a->area()<<endl;
	cout<<a->circum()<<endl;
	
	Shape* b=new Square();
	((Square*)b)->sisi=10;
	cout<<b->area()<<endl;
	cout<<b->circum()<<endl;
	
	Shape* c=new Rect();
	((Rect*)c)->panjang=10;
	((Rect*)c)->lebar=5;
	cout<<c->area()<<endl;
	cout<<c->circum()<<endl;*/
	
	main_menu();
	
	return 0;
}


//menu utama=============================================================================


void main_menu(){
	system("CLS");
	fflush stdin;
	
	cout<< "Program Inheritance dan Polimorphism"<<endl;
	cout<< "1. Tampilkan Bentuk"<<endl;
	cout<< "2. Tambah Bentuk"<<endl;
	cout<< "3. Hapus Bentuk"<<endl;
	cout<< "4. Keluar"<<endl;
	cout<< "Masukan pilihan anda (berupa angka 1-4):"<<endl;
	cin>> pilihan;
	cout<< endl;
	
	switch(pilihan){
		case 1:
			tampil_bentuk();
			break;
		case 2:
			tambah_bentuk();
			break;
		case 3:
			hapus_bentuk();
			break;
		case 4:
			exit(0);
			break;
	}
}

//tampil bentuk===========================================================================

void tampil_bentuk(){
	system("CLS");
	fflush stdin;
	
	cout<< "Menu Tampilkan Bentuk"<<endl;
	cout<< "1. Tampilkan Semua Bentuk"<<endl;
	cout<< "2. Tampilkan Lingkaran"<<endl;
	cout<< "3. Tampilkan Persegi"<<endl;
	cout<< "4. Tampilkan Persegi Panjang"<<endl;
	cout<< "5. Kembali ke Menu Utama"<<endl;
	cout<< "Masukan pilihan anda (berupa angka 1-5):"<<endl;
	cin>> pilihan;
	cout<< endl;
	
	switch(pilihan){
		case 1:
			tampil_semua();
			break;
		case 2:
			tampil_lingkaran();
			break;
		case 3:
			tampil_persegi();
			break;
		case 4:
			tampil_persegipanjang();
			break;
		case 5:
			main_menu();
			break;
	}
}

//tambah bentuk===========================================================================

void tambah_bentuk(){
	while (1){
		//system("CLS");
		fflush stdin;
		
		cout<< "Menu Tambah Bentuk"<<endl;
		cout<< "1. Tambah Lingkaran"<<endl;
		cout<< "2. Tambah Persegi"<<endl;
		cout<< "3. Tambah Persegi Panjang"<<endl;
		cout<< "4. Kembali ke Menu Utama"<<endl;
		cout<< "Masukan pilihan anda (berupa angka 1-4):"<<endl;
		cin>> pilihan;
		cout<< endl;
		
		switch(pilihan){
			case 1:
				int jari;
				cout<< "Masukkan jari-jari: "<<endl;
				cin>> jari;
				shape.push_back(new Circle(jari));
				break;
			case 2:
				int sisi;
				cout<< "Masukkan sisi:"<< endl;
				cin>> sisi;
				shape.push_back(new Square(sisi));
				break;
			case 3:
				int panjang, lebar;
				cout<< "Masukkan panjang:"<< endl;
				cin>> panjang;
				cout<< "Masukkan lebar:"<< endl;
				cin>> lebar;
				shape.push_back(new Rect(panjang, lebar));
				break;
			case 4:
				main_menu();
				break;
		}
	}
}

//hapus bentuk===========================================================================

void hapus_bentuk(){
	system("CLS");
	fflush stdin;
	
	cout<< "Menu Hapus Bentuk"<<endl;
	cout<< "1. Hapus Lingkaran"<<endl;
	cout<< "2. Hapus Persegi"<<endl;
	cout<< "3. Hapus Persegi Panjang"<<endl;
	cout<< "4. Kembali ke Menu Utama"<<endl;
	cout<< "Masukan pilihan anda (berupa angka 1-4):"<<endl;
	cin>> pilihan;
	cout<< endl;
	
	switch(pilihan){
		int i;
		case 1:
			int jari;
			cout<< "Masukkan jari-jari: "<< endl;
			cin>> jari;
			
			for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Lingkaran"){
						if(((Circle*)shape[i])->jari==jari){
							shape.erase(shape.begin()+i);
						}
					}
					shape[i]->detail();	
					}
			break;
		case 2:
			int sisi;
			cout<< "Masukkan sisi: "<< endl;
			cin>> sisi;
			
			for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Persegi"){
						if(((Square*)shape[i])->sisi==sisi){
							shape.erase(shape.begin()+i);
						}
					}
					shape[i]->detail();	
					}
			break;
		case 3:
			int panjang,lebar;
			cout<< "Masukkan panjang :"<< endl;
			cin>> panjang;
			cout<< "Masukkan lebar: "<< endl;
			cin>> lebar;
			
			for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Persegi Panjang"){
						if(((Rect*)shape[i])->panjang==panjang && ((Rect*)shape[i])->lebar==lebar){
							shape.erase(shape.begin()+i);
						}
					}
					shape[i]->detail();	
					}
			break;
		case 4:
			main_menu();
			break;
	}
}

//tampil semua===========================================================================

void tampil_semua(){
	system("CLS");
	fflush stdin;
	
	cout<< "Menu Tampilkan Semua Bentuk"<<endl;
	cout<< "1. Urutkan Berdasarkan Luas"<<endl;
	cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
	cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
	cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
	cin>> pilihan;
	cout<< endl;
	
	switch(pilihan){
		int i;
		case 1:
			
			for (i=0; i<shape.size(); i++){
					shape[i]->detail();	
					}
			break;
		case 2:
			
			for (i=0; i<shape.size(); i++){
					shape[i]->detail();	
					}
			break;
		case 3:
			tampil_bentuk();
			break;
	}
}

//tampil lingkaran===========================================================================

void tampil_lingkaran(){
	system("CLS");
	fflush stdin;
	
	cout<< "Menu Tampilkan Lingkaran"<<endl;
	cout<< "1. Urutkan Berdasarkan Luas"<<endl;
	cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
	cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
	cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
	cin>> pilihan;
	cout<< endl;
	
	switch(pilihan){
		int i;
		case 1:
			
				for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Lingkaran"){
					shape[i]->detail();	
					}
				}
			break;
		case 2:

				for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Lingkaran"){
					shape[i]->detail();	
					}
				}
			break;
		case 3:
			tampil_bentuk();
			break;
	}
}

//tampil persegi===========================================================================

void tampil_persegi(){
	system("CLS");
	fflush stdin;
	
	cout<< "Menu Tampilkan Persegi"<<endl;
	cout<< "1. Urutkan Berdasarkan Luas"<<endl;
	cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
	cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
	cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
	cin>> pilihan;
	cout<< endl;
	
	switch(pilihan){
		int i;
		case 1:
			
			for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Persegi"){
					shape[i]->detail();	
					}
				}
			break;
		case 2:
			
			for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Persegi"){
					shape[i]->detail();	
					}
				}
			break;
		case 3:
			tampil_bentuk();
			break;
	}
}

//tampil persegipanjang===========================================================================

void tampil_persegipanjang(){
	system("CLS");
	fflush stdin;
	
	cout<< "Menu Tampilkan Persegi Panjang"<<endl;
	cout<< "1. Urutkan Berdasarkan Luas"<<endl;
	cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
	cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
	cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
	cin>> pilihan;
	cout<< endl;
	
	switch(pilihan){
		int i;
		case 1:
			
			for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Persegi Panjang"){
					shape[i]->detail();	
					}
				}
			break;
		case 2:
			
			for (i=0; i<shape.size(); i++){
					if (shape[i]->jenis_shape=="Persegi Panjang"){
					shape[i]->detail();	
					}
				}
			break;
		case 3:
			tampil_bentuk();
			break;
	}
}
