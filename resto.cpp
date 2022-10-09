#include <iostream>
#include <conio.h>

using namespace std;

struct resto{
	char nama[30];
	int no;
};

int pilih,pilih1,jumlah,i,indeks,j,swap;

resto rst[30];

void tambah(){
	cout <<"Masukkan jumlah inputan:";
	cin >> jumlah;
	
	for(i = 0;i<jumlah;i++){
		cout << "Nama : ";cin >>rst[i].nama;cout;
		cout << "No   : ";cin >>rst[i].no;cout <<endl;
	}
}

void lihat(){
	for(i=0;i<jumlah;i++){
		cout<<"\n\nMenu ke-"<< i+1 <<endl;
		cout <<"Nama : "<< rst[i].nama<<endl;
		cout <<"No   : "<< rst[i].no<<endl;
	}
}

void edit(){
	cout << "Masukkan nomor menu yang di ubah :";cin >> j;cout << endl;
	indeks = j-1;
	cout << "Nama : ";cin>>rst[indeks].nama;cout<<endl;
	cout << "No   : ";cin>>rst[indeks].no;cout<<endl;
}

void hapus(){
	int y;
	
	cout<< "Hapus Menu Nomor : ";
	cin >> indeks;
	y = indeks-1;
	jumlah--;
	
	for(i = y;i<jumlah;i++){
		rst[i]=rst[i+1];
	}
	cout<<"\nData Berhasil Dihapus!!";
	
}


int main(){
	
	menu:
	cout<< "PILIH MENU"<<endl;
	cout<< "1. Tambah Daftar Makanan"<<endl;
	cout<< "2. Lihat Daftar Makanan"<<endl;
	cout<< "3. Edit Menu"<<endl;
	cout<< "4. Hapus Menu"<<endl;
	cout<< "5. Sorting"<<endl;
	cout<< "6. Keluar"<<endl;
	cout<< "----------------------------------";
	cout<< "\n Pilih : ";
	cin >> pilih;
	
	while (pilih != 6){
		switch(pilih){
			case 1:
				cout<<"pilihan 1";
				tambah();
				goto menu;
			case 2:
				cout<<"pilihan 2";
				lihat();
				goto menu;
			case 3:
				cout<<"pilihan 3";
				edit();
				goto menu;
			case 4:
				cout<<"pilihan 4";
				hapus();
				goto menu;
			case 5:
				ulang:
				cout<<"pilihan 5";
				cout<<"\n1.Ascending\n2.Descending"<<endl;
				cin >> pilih1;
				if (pilih1 == 1){
					for(int i=1; i<y; i++){
						int key = x[i];
						int j = i-1;
						while(j>=0 && x[j] > key){
							x[j+1] = x[j];
							j--;
						}
						x[j+1] = key;
						cout<<"proses sorting"<<endl;
						for(int m=0;m<y;m++){
						cout<<x[m]<<" ";
					    }
					    cout<<endl;
					}
					cout<<"hasil akhir"<<endl;
					for(int m=0;m<y;m++){
						cout<<x[m]<<" ";
					}
					goto menu;
				}
				else if (pilih1 == 2){
					sortdescending();
					goto menu;
				}
				else{
					cout << "Masukkan pilihan yang ada !!!";
					goto ulang;
				}
			default:
				cout<<"Masukkan Angka 1-4 aja !!!";

		}
	}
	
}
