#include<iostream>
#include<conio.h>

using namespace std;

struct Makanan{
    string nama;
    int harga,level;
};

void inputData(Makanan *mkn, int &jumlah);
void lihatData(Makanan *mkn, int *jumlah);
void editData(Makanan *mkn, int *jumlah);

void inputData(Makanan *mkn){

    cout << "Nama : ";fflush(stdin); getline(cin,mkn->nama);
    cout << "Harga : ";cin >> mkn->harga;
    cout << "Level : ";cin >> mkn->level;
    mkn++;

}
void lihatData(Makanan *mkn,int *jumlah){
	int indeks;
	indeks = 0;
	cout << "\n================= Daftar Menu =================\n";
	
    for(int i = 0; i < *jumlah; i++){
    	cout << "No Makanan [" << i+1 << "]"<< endl;
		cout << "Nama   : " << mkn[i].nama << endl;
		cout << "Harga  : " << mkn[i].harga << endl;
		cout << "Level  : " << mkn[i].level << endl;
		cout << endl;
	}
}

void editData(Makanan *mkn, int *jumlah){
	int indeks,nomor;
	
	lihatData(&mkn[0],jumlah);
	cout << "Edit Menu Nomor : ";
	cin >> indeks;
	nomor = indeks - 1;
	
	cout << "Nama Baru : ";
	cin >> mkn[nomor].nama;
	cout << "Harga Baru : ";
	cin >> mkn[nomor].harga;
	cout << "Level Baru : ";
	cin >> mkn[nomor].level;

}

void hapusData(Makanan *mkn, int &jumlah){
	int y,indeks;
	indeks =0;
    cout << "Hapus Menu nomor : ";
    cin >> indeks;
    y = indeks - 1;
    jumlah--;
    
    for(int i=y;i<jumlah;i++)
   {
      mkn[i]=mkn[i+1];
   }
}

void kembali()
{
   cout<<"===============================================";
   cout << "\n               <Enter : kembali>";
   getch();
}

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (Makanan *mkn, int low, int high){
	int pivot = mkn[high].harga;
	int i = (low - 1);
	
	for (int j = low; j <= high - 1; j++){
		
		if (mkn[j].harga < pivot){
		i++;
		swap(&mkn[i].harga, &mkn[j].harga);
		}
	}
	swap(&mkn[i + 1].harga, &mkn[high].harga);
	return (i + 1);
}

void quickSort(Makanan *mkn, int low, int high){
	if (low < high){
	
		int pi = partition(mkn, low, high);
		
		// Separately sort elements before
		// partition and after partition
		quickSort(mkn, low, pi - 1);
		quickSort(mkn, pi + 1, high);
	}
}

void printArray(Makanan *mkn, int size){
	int i;
	for (i = 0; i < size; i++){
		cout << "               No Makanan [" << i+1 << "]"<< endl;
		cout << "Nama   : " << mkn[i].nama << endl;
		cout << "Harga  : " << mkn[i].harga << endl;
		cout << "Level  : " << mkn[i].level << endl;
		//cout << "Saos   : " << mkn[i].saos << endl;
		//cout << "Alamat : " << mkn[i].alamat << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

int main(){
    int pilih,jumlah,pilihan;
    
    cout << "Masukkan Jumlah Menu : "; cin >> jumlah;
    
    Makanan mkn[jumlah];
    
    for(int i = 0;i<jumlah;i++){
        inputData(&mkn[i]);
	}
    
    awal:
    system("cls");
    cout << "\n================= PILIH MENU ==================";
    cout << "\n| 1. Lihat Daftar Makanan                     |";
    cout << "\n| 2. Edit Menu                                |";
    cout << "\n| 3. Hapus Menu                               |";
    cout << "\n| 4. Sort Menu                                |";
    cout << "\n| 5. Keluar                                   |";
    cout << "\n===============================================";
    cout << "\n\nPilih : ";
    cin >> pilih;
 
    while (pilih != 5)
    {
        if (pilih == 1){
            system("cls");
            lihatData(&mkn[0],&jumlah);
            kembali();
            goto awal;
        }
        if (pilih == 2){
            system("cls");
            editData(&mkn[0],&jumlah);
            goto awal;
        }
        if (pilih == 3){
            system("cls");
            hapusData(&mkn[0],jumlah);
            goto awal;
        }
        if (pilih == 4){
            system("cls");
        	cout << "1. Ascending\n2.Descending\nPilih : "; cin >> pilihan;
        	if (pilihan == 1){
        		int n = sizeof(mkn) / sizeof(mkn[0]);
        		quickSort(&mkn[0], 0, n - 1);
        		printArray(mkn, n);
				kembali();
				goto awal;
			}
        }
        else{
            cout<<"\nError: Pilih 1 sampai 5 !!!\nEnter...";
            //getch();
            system("cls");
            goto awal;
        
    	}
    }
    cout << "\n===============================================\n";
    cout << "               Program Selesai " <<endl;
    cout << "===============================================";
	return 0;
}
