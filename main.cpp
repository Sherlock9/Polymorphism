/*
Credit to Evans Jahja, Dedy Van Houten, Jelita Asian
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <regex>

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
void read_db();
void write_db();

vector <Shape*> shape;

regex numbers ("[0-9]+");
smatch sm;

string input;
int pilihan;

bool AreaCmp(Shape* a, Shape* b)
{
    return a->area() < b->area();
}

bool CircumCmp(Shape* a, Shape* b)
{
    return a->circum() < b->circum();
}

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
	
    read_db();
	main_menu();
	
	return 0;
}


//menu utama=============================================================================


void main_menu()
{
    bool menu_loop = true;
    while (menu_loop)
    {
        system("CLS");
        fflush stdin;
        
        cout<< "Program Inheritance dan Polimorphism"<<endl;
        cout<< "1. Tampilkan Bentuk"<<endl;
        cout<< "2. Tambah Bentuk"<<endl;
        cout<< "3. Hapus Bentuk"<<endl;
        cout<< "4. Keluar"<<endl;
        cout<< "Masukan pilihan anda (berupa angka 1-4):"<<endl;
        cin>> input;
        cout<< endl;
        
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
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
                write_db();
                exit(0);
                break;
        }
    }
}

//tampil bentuk===========================================================================

void tampil_bentuk()
{
    system("CLS");
    bool menu_loop = true;
    while (menu_loop)
    {
        fflush stdin;
        
        cout<< "Menu Tampilkan Bentuk"<<endl;
        cout<< "1. Tampilkan Semua Bentuk"<<endl;
        cout<< "2. Tampilkan Lingkaran"<<endl;
        cout<< "3. Tampilkan Persegi"<<endl;
        cout<< "4. Tampilkan Persegi Panjang"<<endl;
        cout<< "5. Kembali ke Menu Utama"<<endl;
        cout<< "Masukan pilihan anda (berupa angka 1-5):"<<endl;
        cin>> input;
        cout<< endl;
        
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
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
}

//tambah bentuk===========================================================================

void tambah_bentuk()
{
    string input;
    system("CLS");
    bool menu_loop = true;
    while (menu_loop)
    {
		fflush stdin;
		
		cout<< "Menu Tambah Bentuk"<<endl;
		cout<< "1. Tambah Lingkaran"<<endl;
		cout<< "2. Tambah Persegi"<<endl;
		cout<< "3. Tambah Persegi Panjang"<<endl;
		cout<< "4. Kembali ke Menu Utama"<<endl;
		cout<< "Masukan pilihan anda (berupa angka 1-4):"<<endl;
		cin>> input;
		cout<< endl;
		
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
		switch(pilihan){
			case 1:
				int jari;
				cout<< "Masukkan jari-jari: "<<endl;
				cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) jari = stoi(input);
                else continue;
                
				shape.push_back(new Circle(jari));
				break;
			case 2:
				int sisi;
				cout<< "Masukkan sisi:"<< endl;
				cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) sisi = stoi(input);
                else continue;
                
				shape.push_back(new Square(sisi));
				break;
			case 3:
				int panjang, lebar;
				cout<< "Masukkan panjang:"<< endl;
				cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) panjang = stoi(input);
                else continue;
                
				cout<< "Masukkan lebar:"<< endl;
				cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) lebar = stoi(input);
                else continue;
                
				shape.push_back(new Rect(panjang, lebar));
				break;
			case 4:
				main_menu();
				break;
		}
	}
}

//hapus bentuk===========================================================================

void hapus_bentuk()
{
    string input;
    system("CLS");
    bool menu_loop = true;
    while (menu_loop)
    {
        fflush stdin;
        
        cout<< "Menu Hapus Bentuk"<<endl;
        cout<< "1. Hapus Lingkaran"<<endl;
        cout<< "2. Hapus Persegi"<<endl;
        cout<< "3. Hapus Persegi Panjang"<<endl;
        cout<< "4. Kembali ke Menu Utama"<<endl;
        cout<< "Masukan pilihan anda (berupa angka 1-4):"<<endl;
        cin>> input;
        cout<< endl;
        
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
        switch(pilihan){
            int i;
            case 1:
                int jari;
                cout<< "Masukkan jari-jari: "<< endl;
                cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) jari = stoi(input);
                else continue;
                
                for (i=0; i<shape.size(); i++){
                        if (shape[i]->jenis_shape=="Lingkaran"){
                            if(((Circle*)shape[i])->jari==jari){
                                shape.erase(shape.begin()+i);
                                cout<< "FOUND AND DELETED"<< endl<< endl;
                            }
                        }
                        shape[i]->detail();	
                        }
                break;
            case 2:
                int sisi;
                cout<< "Masukkan sisi: "<< endl;
                cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) sisi = stoi(input);
                else continue;
                
                for (i=0; i<shape.size(); i++){
                        if (shape[i]->jenis_shape=="Persegi"){
                            if(((Square*)shape[i])->sisi==sisi){
                                shape.erase(shape.begin()+i);
                                cout<< "FOUND AND DELETED"<< endl<< endl;
                            }
                        }
                        shape[i]->detail();	
                        }
                break;
            case 3:
                int panjang,lebar;
                cout<< "Masukkan panjang :"<< endl;
                cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) panjang = stoi(input);
                else continue;
                
                cout<< "Masukkan lebar: "<< endl;
                cin>> input;
                cout<< endl;
                
                if ( regex_match(input, sm, numbers) ) lebar = stoi(input);
                else continue;
                
                for (i=0; i<shape.size(); i++){
                        if (shape[i]->jenis_shape=="Persegi Panjang"){
                            if(((Rect*)shape[i])->panjang==panjang && ((Rect*)shape[i])->lebar==lebar){
                                shape.erase(shape.begin()+i);
                                cout<< "FOUND AND DELETED"<< endl<< endl;
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
}

//tampil semua===========================================================================

void tampil_semua()
{
    system("CLS");
    bool menu_loop = true;
    while (menu_loop)
    {
        fflush stdin;
        
        cout<< "Menu Tampilkan Semua Bentuk"<<endl;
        cout<< "1. Urutkan Berdasarkan Luas"<<endl;
        cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
        cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
        cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
        cin>> input;
        cout<< endl;
        
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
        switch(pilihan){
            int i;
            case 1:
                sort(shape.begin(), shape.end(), AreaCmp);
                for (i=0; i<shape.size(); i++){
                        shape[i]->detail();	
                        }
                break;
            case 2:
                sort(shape.begin(), shape.end(), CircumCmp);
                for (i=0; i<shape.size(); i++){
                        shape[i]->detail();	
                        }
                break;
            case 3:
                tampil_bentuk();
                break;
        }
    }
}

//tampil lingkaran===========================================================================

void tampil_lingkaran()
{
    system("CLS");
    bool menu_loop = true;
    while (menu_loop)
    {
        fflush stdin;
        
        cout<< "Menu Tampilkan Lingkaran"<<endl;
        cout<< "1. Urutkan Berdasarkan Luas"<<endl;
        cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
        cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
        cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
        cin>> input;
        cout<< endl;
        
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
        switch(pilihan){
            int i;
            case 1:
                sort(shape.begin(), shape.end(), AreaCmp);
                for (i=0; i<shape.size(); i++){
                    if (shape[i]->jenis_shape=="Lingkaran"){
                    shape[i]->detail();	
                    }
                }
                break;
            case 2:
                sort(shape.begin(), shape.end(), CircumCmp);
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
}

//tampil persegi===========================================================================

void tampil_persegi()
{
    system("CLS");
    bool menu_loop = true;
    while (menu_loop)
    {
        fflush stdin;
        
        cout<< "Menu Tampilkan Persegi"<<endl;
        cout<< "1. Urutkan Berdasarkan Luas"<<endl;
        cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
        cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
        cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
        cin>> input;
        cout<< endl;
        
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
        switch(pilihan){
            int i;
            case 1:
                sort(shape.begin(), shape.end(), AreaCmp);
                for (i=0; i<shape.size(); i++){
                        if (shape[i]->jenis_shape=="Persegi"){
                        shape[i]->detail();	
                        }
                    }
                break;
            case 2:
                sort(shape.begin(), shape.end(), CircumCmp);
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
}

//tampil persegipanjang===========================================================================

void tampil_persegipanjang()
{
    system("CLS");
    bool menu_loop = true;
    while (menu_loop)
    {
        fflush stdin;
        
        cout<< "Menu Tampilkan Persegi Panjang"<<endl;
        cout<< "1. Urutkan Berdasarkan Luas"<<endl;
        cout<< "2. Urutkan Berdasarkan Keliling"<<endl;
        cout<< "3. Kembali ke Menu Tampilkan Bentuk"<<endl;
        cout<< "Masukan pilihan anda (berupa angka 1-3):"<<endl;
        cin>> input;
        cout<< endl;
        
        if ( regex_match(input, sm, numbers) ) pilihan = stoi(input);
        else continue;
        
        switch(pilihan){
            int i;
            case 1:
                sort(shape.begin(), shape.end(), AreaCmp);
                for (i=0; i<shape.size(); i++){
                        if (shape[i]->jenis_shape=="Persegi Panjang"){
                        shape[i]->detail();	
                        }
                    }
                break;
            case 2:
                sort(shape.begin(), shape.end(), CircumCmp);
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
}

void read_db()
{
    string shape_id;
    string filename;
    int jari;
    int sisi;
    int panjang;
    int lebar;
    
    filename = "circle.txt";
    ifstream circle_file(filename.c_str());
    if (circle_file.is_open())
    {
        while (getline(circle_file, shape_id))
        {
            jari = atoi( shape_id.c_str() );
            shape.push_back( new Circle(jari) ); 
        }
    }
    else cout << "Unable to open file";
    circle_file.close();
    
    filename = "square.txt";
    ifstream square_file(filename.c_str());
    if (square_file.is_open())
    {
        while (getline(square_file, shape_id))
        {
            sisi = atoi( shape_id.c_str() );
            shape.push_back( new Square(sisi) ); 
        }
    }
    else cout << "Unable to open file";
    square_file.close();
    
    filename = "rectangle.txt";
    ifstream rect_file(filename.c_str());
    if (rect_file.is_open())
    {
        while (!rect_file.eof())
        {
            getline(rect_file,shape_id,'\t');
            if (shape_id == "") { break; }
            panjang = atoi( shape_id.c_str() );
            getline(rect_file,shape_id,'\n');
            lebar = atoi( shape_id.c_str() );
            shape.push_back( new Rect(panjang, lebar) );
        }
    }
    else cout << "Unable to open file";
    rect_file.close();
}

void write_db()
{
    string filename;
    string jenis;
    ofstream db_file;
    int sz = shape.size();
    
    filename = "circle.txt";
    db_file.open(filename.c_str(),ios::out);
    db_file.close();
    filename = "square.txt";
    db_file.open(filename.c_str(),ios::out);
    db_file.close();
    filename = "rectangle.txt";
    db_file.open(filename.c_str(),ios::out);
    db_file.close();
    
    for (int i = 0; i<sz; i++)
    {
        jenis = shape[i]->jenis_shape;
        if ( jenis == "Lingkaran" ) 
        {
            filename = "circle.txt";
            db_file.open(filename.c_str(), ios::out | ios::app);
            if (db_file.is_open())
            {
                db_file << ((Circle *)shape[i])->jari << endl;
            }
            else cout << "Unable to open file";
            db_file.close();
        }
        else if ( jenis == "Persegi" ) 
        {
            filename = "square.txt";
            db_file.open(filename.c_str(), ios::out | ios::app);
            if (db_file.is_open())
            {
                db_file << ((Square *)shape[i])->sisi << endl;
            }
            else cout << "Unable to open file";
            db_file.close();
        }
        else if ( jenis == "Persegi Panjang" ) 
        {
            filename = "rectangle.txt";
            db_file.open(filename.c_str(), ios::out | ios::app);
            if (db_file.is_open())
            {
                db_file << ((Rect *)shape[i])->panjang << "\t" << ((Rect *)shape[i])->lebar << endl;
            }
            else cout << "Unable to open file";
            db_file.close();
        }
    }
}