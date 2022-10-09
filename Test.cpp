#include <iostream>
using namespace std;
int main(){
// Variabel Nomor 1
// Mendeklarasikan variabel No array berbentuk Interger
int No[1] = {01};
// Mendeklarasikan variabel Nama_lengkap array berbentuk String
string Nama_Lengkap[1] = {"Steven Alesandro Nesta"};
// Mendeklarasikan variabel umur array berbentuk float
float umur[1] = {20};
// mendeklarasikan index array berbentuk interger
int a;
//Mendeklarasikan array 2d berbentuk interger
int arr[2][5];
//Mendeklarasikan pointer array berbentuk interger 
int(*p)[5];
//Mendeklarasikan Baris, kolom, x dan y berbentuk interger
int baris,kolom, x, y;
//memasukkan nilai array menjadi alamat pointernya 
p = arr;
//Nomor 1
cout<<"NO. 1"<<endl;
//Melakukan perlulangan untuk menampilkan array 1 d dengan 3 tipe data berbeda dan jika variable lebih dari 1 maka perulangan berhenti 
for (a=0;a<1; a++){
//menampilkan data array 
cout<<"No : "<<No[a]<<endl;
cout<<"Nama : "<<Nama_Lengkap[a]<<endl;
cout<<"umur : "<<umur[a]<<endl;
}
cout<<endl;
//No 2
cout<<"NO. 2"<<endl;
// Memasukkan Bris dan kolom yg diinginkan
cout <<"Masukkan Baris : ";
cin >> baris;
cout << "Masukkan Kolom : ";
cin >> kolom;
// melakukan perulangan jika baris dan kolom sudah diisi dan jika x lebih dari baris dan lebih dari kolom maka perulangan akan berhenti
for(x=0;x<baris; x++){
for(y=0;y<kolom; y++){
// menampilkan baris ke - berapa dan ke - berapa 
cout<<"Baris "<<x+1<<", Kolom "<<y+1<<" = ";
//memasukkan array 
cin>>arr[x][y];
}
cout<<endl;
}
// Menampilkan Hasil dari 2d array
cout<<" Hasil : "<<endl;
// melakukan perulangan untuk menampilkan 2d array
for(x = 0; x <baris ; x++){
 for(y = 0; y<kolom; y++){
 //nilai array yg telah diubah menjadi alamat pointernya akan ditampilkan 
 cout<<*(*(p+x)+y)<< " ";
 }
 // menandakan kalimatnya berehenti di satu line
 cout << endl;
 }
 // jika programnya sudah selesai maka kembali ke 0 dan selesai
 return 0;
}
