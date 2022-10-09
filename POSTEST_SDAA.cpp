#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<string.h>

using namespace std;

typedef struct buku
{
	char nama[30], alamat[30], tglsewa[30], judul[30];
	char email[40];
	char no_id[20];
	int id;
}

buku;

int main()
{
	float id;
	FILE *fp,*ft;
	char idk, pilih;
	buku stu;
	long int recsize;
	
	fp=fopen("Sewa.DAT","rb+");
	if(fp==NULL)
	{
		fp=fopen("Sewa.DAT","wb+");
	if(fp==NULL)
	{
	cout<<("File gagal diakses")<<endl;
	}
}
	recsize=sizeof(stu);
	while(!(pilih=='5'))
	{
		system("cls");
		cout<<"+----------------------------------------------------------+"<<endl;
		cout<<"|                    Penyewaan Buku Cia                    |"<<endl;
		cout<<"+----------------------------------------------------------+"<<endl;
		cout<<"|  Berikut syarat penyewaan buku :                         |"<<endl;
		cout<<"|  [1] Penyewa harus mengisi data jika ingin menyewa buku. |"<<endl;
		cout<<"|  [2] Buku yang telah disewa akan menjadi tanggung jawab  |"<<endl;
		cout<<"|      penyewa buku tersebut.                              |"<<endl;
		cout<<"|  [3] Jika buku mengalami kerusakan atau hilang saat      |"<<endl;
		cout<<"|      pengembalian, maka penyewa akan dikenakan denda.    |"<<endl;
		cout<<"|  [4] Denda akan dikenakan kepada penyewa jika buku dalam |"<<endl;
		cout<<"|      keadaan rusak, hilang, atau terlambat dikembalikan. |"<<endl;
		cout<<"|  [5] Jika penyewa meminjamkan buku kepada orang lain     |"<<endl;
		cout<<"|      tanpa mengembalikan pada tempat sewa, maka penyewa  |"<<endl;
		cout<<"|      akan tetap bertanggung jawab atas buku tersebut     |"<<endl;
		cout<<"|      (jika rusak atau hilang).                           |"<<endl;
		cout<<"|  [6] Tempat penyewaan ini telah membatasi jumlah buku    |"<<endl;
		cout<<"|      yang dapat dipinjam oleh individu, yaitu maksimal   |"<<endl;
		cout<<"|      3 buku (jika penyewa ingin meminjam lagi, diharap-  |"<<endl;
		cout<<"|      kan untuk menyelesaikan buku yang telah disewa ter- |"<<endl;
		cout<<"|      lebih dahulu).                                      |"<<endl;
		cout<<"+----------------------------------------------------------+"<<endl;
		cout<<"|  Menu :                                                  |"<<endl;
		cout<<"|  [1] Input Data Sewa                                     |"<<endl;
		cout<<"|  [2] Delete Data Sewa                                    | "<<endl;
		cout<<"|  [3] Update Data Sewa                                    | "<<endl;
		cout<<"|  [4] Tampilkan Data Sewa                                 | "<<endl;
		cout<<"|  [5] Keluar                                              | "<<endl;
		cout<<"+----------------------------------------------------------+"<<endl;
		cout<<"|  Silahkan Pilih : "<<endl;

		fflush(stdin);
		scanf("%c",&pilih);
		cout<<"+----------------------------------------------------------+"<<endl;
		switch(pilih)
		{
			case'1':
				fseek(fp,0,SEEK_END);
				idk='Y';
				while(idk=='Y'||idk=='y')
				{
					system("cls");
					cout<<"+--------------------------------------------------+"<<endl;
					cout<<"|            Input Penyewaan Buku Cia              |"<<endl;
					cout<<"+--------------------------------------------------+"<<endl;
					printf("\n| Nama               : ");scanf("%s",&stu.nama);
					printf("\n| Alamat             : ");scanf("%s",&stu.alamat);
					printf("\n| Email              : ");scanf("%s",&stu.email);
					printf("\n| ID Penyewa         : ");scanf("%s",&stu.no_id);
					printf("\n| Judul Buku         : ");scanf("%s",&stu.judul);
					printf("\n| Tanggal Penyewaan  : ");scanf("%d",&stu.tglsewa);
					fwrite(&stu,recsize,1,fp);
					printf("\n+--------------------------------------------------+");
					printf("\n|        Apakah Anda Ingin Mengulang [Y/T]?        |");
					fflush(stdin);
					idk=getchar();
				}
				break;
				
			case'2':
				idk='Y';
				while(idk=='Y'||idk=='y')
				{
					system("cls");
					printf("\n+--------------------------------------------------+");
					printf("\n|            Delete Penyewaan Buku Cia             |");
					printf("\n+--------------------------------------------------+");
					printf("\n| Nama               : ");scanf("%s",&stu.nama);
					printf("\n| Alamat             : ");scanf("%s",&stu.alamat);
					printf("\n| Email              : ");scanf("%s",&stu.email);
					printf("\n| ID Penyewa         : ");scanf("%s",&stu.no_id);
					printf("\n| Judul Buku         : ");scanf("%s",&stu.judul);
					printf("\n| Tanggal Penyewaan  : ");scanf("%d",&stu.tglsewa);
					printf("\n+--------------------------------------------------+");
					ft=fopen("Sewa.DAT","wb");
					rewind(fp);
					while(fread(&stu,recsize,1,fp)==1)
					{
						if(stu.id!=0)
						fwrite(&stu,recsize,1,ft);
					}
					fclose(fp);
					fclose(ft);
					
					remove("Sewa.DAT");
					rename("NewSewa.DAT","Sewa.DAT");
					fp=fopen("NewSewa.DAT","wb+");
					printf("\n|        Apakah Anda Ingin Mengulang [Y/T]?        |");
					fflush(stdin);
					idk=getchar();
				}
			break;
				
			case'3':
			idk='Y';
			while(idk=='Y'||idk=='y')
			{
				system("cls");
				printf("\n");
				printf("+--------------------------------------------------+");
				printf("\n|            Update Penyewaan Buku Cia             |");
				printf("\n+--------------------------------------------------+");
				printf("\n| Nama               : ");scanf("%s",&stu.nama);
				printf("\n| Alamat             : ");scanf("%s",&stu.alamat);
				printf("\n| Email              : ");scanf("%s",&stu.email);
				printf("\n| ID Penyewa         : ");scanf("%s",&stu.no_id);
				printf("\n| Judul Buku         : ");scanf("%s",&stu.judul);
				printf("\n| Tanggal Penyewaan  : ");scanf("%d",&stu.tglsewa);
				printf("\n+--------------------------------------------------+");
				printf("\n| Apakah Anda ingin mengulang [Y/N] ?              |");
				
				fflush(stdin);
				idk=getchar();
			}
			break;
			
			case'4':
				rewind(fp);
				
				system("cls");
				printf("\n+--------------------------------------------------+");
				printf("\n|             Data Penyewaan Buku Cia              |");
				printf("\n+--------------------------------------------------+");
				while(fread(&stu,recsize,1,fp)==1)
				{
					cout<<"\n|  Nama Penyewa : "<<stu.nama;
					cout<<"\n|  Alamat       : "<<stu.alamat;
					cout<<"\n|  Email        : "<<stu.email;
					cout<<"\n|  Id           : "<<stu.no_id;
					cout<<"\n|  Judul Buku   : "<<stu.judul;
					cout<<"\n|  Tanggal Sewa : "<<stu.tglsewa;
					printf("\n+--------------------------------------------------+");
					printf("\n| Apakah Anda ingin mengulang [Y/N] ?              |");
				
					fflush(stdin);
					idk=getchar();
			}
			break;
			
			case'5':
			{
				system("cls");
			}
			break;
		}
	}
}
