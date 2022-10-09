#include<iostream>
using namespace std;

//int tambah(int a, int b){
//	return a + b;
//}

// fungsi kuadrat biasanya
//int kuadrat(int angka){
//	return (angka) * (angka);
//}



// ================================================================== 
// fungsi kuadrat dengan pointer
//void kuadrat(int *angka){
//	cout << "alamat angka : " << angka << endl;
//	*angka = (*angka) * (*angka);
//}



// ================================================================== 
// fungsi kuadrat dengan reference
//void kuadrat(int &angka){
//	cout << "alamat angka : " << &angka << endl;
//	angka = (angka) * (angka);
//}

// jika kita tidak menggunakan struct untuk membuat data mahasiswa
//string nama[50];
//int nim[50];
//double ipk[50];

typedef struct {
	double kalkulus;
	double sdaa;
}dataNilai;

struct Mahasiswa{
	string nama;
	int nim;
	double ipk;
	dataNilai nilai;
};

// fungsi tambah data menggunakan pointer [ akses struct pointer itu menggunakan operator arrow -> ]
void tambahData(Mahasiswa *mhs, int *jumlah){
	for(int i = 0; i < *jumlah;i++){
		cout << "Masukan Nama : ";cin >> mhs->nama;
		cout << "Masukan NIM  : ";cin >> mhs->nim;
		cout << "Masukan IPK  : ";cin >> mhs->ipk;
		cout << "Nilai Kalkulus : "; cin>> mhs->nilai.kalkulus;
		cout << "Nilai SDAA     : "; cin>> mhs->nilai.sdaa;
		mhs++;
	}
}

int main(){
	
// =================================================================== 
//menginput string bisa menggunakan spasi
//	string nama,kata;
//	int angka;
//	cout << "Masukan angka : ";cin >> angka;
//	cout << "Masukan nama : ";fflush(stdin);getline(cin,nama);
//	cout << "Masukan kata : ";cin >> kata;
//	
//	cout << "Nama  : " << nama << endl;
//	cout << "Angka : " << angka << endl;
//	cout << "Kata  : " << kata << endl;
	
	
	
// =================================================================== 
//   latihan array struct dengan pointer
	int indexTerakhir = 0,jumlah;
	cout << "Masukan jumlah mahasiswa : "; cin >> jumlah;
	Mahasiswa mhs[jumlah];
	
	tambahData(&mhs[0],&jumlah); 
//  karena parameternya itu tipenya pointer, jadi data yang kita input ke parameter itu alamat variablenya
	
	cout << "================================================" << endl;
	for(int i = 0; i < jumlah;i-=-1){
		cout << "Nama : " << mhs[i].nama << endl;
		cout << "NIM  : " << mhs[i].nim << endl;
		cout << "IPK  : " << mhs[i].ipk << endl;
		cout << "Nilai Kalkulus : " << mhs[i].nilai.kalkulus << endl;
		cout << "Nilai SDAA     : " << mhs[i].nilai.sdaa << endl;
	}
	cout << "Masukan Nama : ";cin >> mhs.nama;
	cout << "Masukan NIM  : ";cin >> mhs.nim;
	cout << "Masukan IPK  : ";cin >> mhs.ipk;
	
    
    
    
// =================================================================== 
//   latihan pointer 
//	int angka = 10;
// vvariable pointer
//	int *ptr;
//	ptr = &angka;
	
//	cout << "Angka : " << angka << endl;
//	cout << "Alamat angka : " << &angka << endl;
//	cout << "Pointer angka : " << ptr << endl;
    
// ddereferencing
//	cout << "Akses nilai angka dari pointer : " << *ptr << endl; // 072
    
//	int angka1 = 2;
//	kuadrat(&angka1);
//	angka1 = kuadrat(angka1); // jika menggunakan fungsi kuadrat biasanya
//	cout << "alamat angka1 : " << &angka1 << endl;
//	cout << "angka1 : " << angka1 << endl;
//	
	
//	*ptr = 20;
//	cout << "Angka : " << angka << endl;
//	cout << "Akses nilai angka dari pointer : " << *ptr << endl;
    
    
    
// =================================================================== 
// llatihan reference
//	int a = 30;
//	int &b = a;
	
//	cout << "nilai a : " << a << endl;
//	cout << "alamat a : " << &a << endl;
	
//	b = 50;
//	cout << "alamat b : " << &b << endl;
//	kuadrat(b);
//	cout << "nilai b : " << b << endl;
//	cout << "nilai a : " << a << endl;
//	cout << "nilai b : " << b << endl;
//	cout << "alamat a : " << &a << endl;
//	cout << "alamat b : " << &b << endl;
}
