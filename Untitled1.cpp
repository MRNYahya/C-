#include<iostream>
using namespace std;

struct makanan{
	string nama_makanan;
	int harga_makanan;
};

struct menu{
	string menu_makanan;
	struct makanan menu;
};

struct menu warung[10];

int main(){
	int i=0;
	makanan mkn;

	cout<<"Masukkan Nama Makanan: "; cin >> mkn.nama_makanan;
	cout<<"Masukkan Harga Makanan: "; cin >> mkn.harga_makanan;
	
	cout<<endl;
	cout << "Nama Makanan :"<<warung[i].nama_makanan;
	cout << "Harga Makanan :"<<warung[i].harga_makanan;
}
