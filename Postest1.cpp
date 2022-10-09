#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct makanan{char nama[20],harga[20];};
makanan batasmaks[100];
int batas,jumlah,indeks;


void inputdata()
{
   int z;
   cout << "\nJumlah Menu yang ingin ditambah : ";
   cin >> jumlah;
   indeks = 0;

   for(z=0;z<jumlah;z++)
   {
      indeks = indeks + 1;
      cout << "\nMenu " << indeks << endl;
      cout << "Nama\t: ";
      cin >> batasmaks[batas].nama;
      cout << "Harga\t: ";
      cin >> batasmaks[batas].harga;
      batas ++;}

   system("cls");
}

void kembali()
{
   cout<<"\n===============================================";
   cout << "\n               <Enter : kembali>";
   getch();
}

void menu()
{
   int i;
   indeks = 0;

   cout << "\n================= Daftar Menu =================\n";
   cout << "No. \tNama.\t\t\tHarga." << endl;
   for(i=0;i<batas;i++)
   {
      indeks = indeks + 1;
      cout << indeks << ". ";
      cout << batasmaks[i].nama << "\t\t\t| Rp. ";
      cout << batasmaks[i].harga << endl;
   }
   cout<<"\n===============================================\n";
}

void lihatdata()
{
   int i;
   indeks = 0;

   cout << "\n================= Daftar Menu =================\n";
   cout << "No. \tNama.\t\t\tHarga." << endl;
   for(i=0;i<batas;i++)
   {
      indeks = indeks + 1;
      cout << indeks <<".  ";
      cout << batasmaks[i].nama << "\t\t\t| Rp. ";
      cout << batasmaks[i].harga << endl;
   }
   kembali();
}

void editdata()
{
   int j;

   menu();
   cout << "Edit Menu nomor : ";
   cin >> indeks;
   j = indeks - 1;

   cout << "Nama\t: ";
   cin >> batasmaks[j].nama;
   cout << "Harga\t: ";
   cin >> batasmaks[j].harga;
   
   system("cls");
   cout << "Data Berhasil di Ubah";
   lihatdata();
}

void hapusdata()
{
   int y;

   menu();
   cout << "Hapus Menu nomor : ";
   cin >> indeks;
   y = indeks - 1;
   batas--;

   for(int i=y;i<batas;i++)
   {
      batasmaks[i]=batasmaks[i+1];
   }
   
   system("cls");
   cout << "\nData Berhasil di Hapus!!\n";
   lihatdata();
}

int main(){
   int pilih;

   awal:
   system("cls");
   cout << "\n================= PILIH MENU ==================";
   cout << "\n| 1. Tambah Daftar Makanan                    |";
   cout << "\n| 2. Lihat Daftar Makanan                     |";
   cout << "\n| 3. Edit Menu                                |";
   cout << "\n| 4. Hapus Menu                               |";
   cout << "\n| 5. Keluar                                   |";
   cout << "\n===============================================";
   cout << "\n\nPilih : ";
   cin >> pilih;

   while (pilih != 5)
   {
      switch(pilih)
      {
         case 1:
            system("cls");
            inputdata();
            goto awal;
         case 2:
            system("cls");
            lihatdata();
            goto awal;
         case 3:
            system("cls");
            editdata();
            goto awal;
         case 4:
            system("cls");
            hapusdata();
            goto awal;
         default:
            cout<<"\nError: Pilih 1 sampai 5 !!!\nEnter...";
            getch();
            system("cls");
            goto awal;
      }
   }
   cout << "\n===============================================\n";
   cout << "               Program Selesai " <<endl;
   cout << "===============================================";
	return 0;
}
