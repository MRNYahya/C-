#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Buah {
	int pk;
	string buah;
	string harga;
};


int getOption(){
	int input;
	//system("cls");
	cout << "\nProgram Toko Buah" << endl;
	cout << "====================" << endl;
	cout << "1. Tambah Buah" << endl;
	cout << "2. Tampilkan daftar buah" << endl;
	cout << "3. Ubah data buah" << endl;
	cout << "4. Hapus data buah" << endl;
	cout << "5. Selesai" << endl;
	cout << "====================" << endl;
	cout << "Pilih [1-5] : ";
	cin >> input;
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); //untuk enter kebawah agar buah dan harga tidak tertulis bersebelahan
	return input;
}


void cekDatabase(fstream &data){
	data.open("data.bin", ios::out | ios::in | ios::binary);
	
	// cek file apakah ada atau tidak
	if (data.is_open()){
		cout << "database ada" << endl;
	} else {
		cout << "database tidak ada" << endl;
		data.close();
		data.open("data.bin", ios::trunc| ios::out | ios::in | ios::binary);
	}
}


void writeData(fstream &data, int posisi, Buah &inputBuah){
	data.seekp((posisi - 1)*sizeof(Buah), ios::beg);
	data.write(reinterpret_cast<char*>(&inputBuah), sizeof(Buah));
}


int getDataSize(fstream &data){
	int start, end;
	data.seekg(0,ios::beg);
	start = data.tellg();
	data.seekg(0,ios::end);
	end = data.tellg();
	return (end-start)/sizeof(Buah);
}


Buah readData(fstream &data, int posisi){
	Buah readBuah;
	data.seekg((posisi - 1)*sizeof(Buah),ios::beg);
	data.read(reinterpret_cast<char*>(&readBuah), sizeof(Buah));
	return readBuah;
}

void addDataBuah(fstream &data){
	
	Buah inputBuah, lastBuah;
	
	int size = getDataSize(data);
	
	cout << "ukuran data : " << size << endl;
	
	if(size == 0){
		inputBuah.pk = 1;
	} else {
		lastBuah = readData(data,size);
		cout << "pk =" << lastBuah.pk << endl;
		inputBuah.pk = lastBuah.pk + 1;
	}
	
	//readData(data,size);
	
	inputBuah.pk = 1;
	cout << "Buah: ";
	getline(cin, inputBuah.buah);
	cout << "Harga: ";
	getline(cin, inputBuah.harga);
	
	writeData(data,size+1,inputBuah);
	
}


int main(){
	
	fstream data;
	
	cekDatabase(data);
	
	int pilihan = getOption();
	char is_continue;
	
	enum option{CREATE = 1 , READ, UPDATE, DELETE, FINISH};
	
	while(pilihan != FINISH){
			
		switch(pilihan){
			case CREATE:
				cout << "Tambah buah" << endl;
				addDataBuah(data); //ini pemanggilan menunya
				break;
			case READ:
				cout << "Tampilkan daftar buah" << endl;
				break;	
			case UPDATE:
				cout << "Ubah data buah" << endl;
				break;
			case DELETE:
				cout << "Hapus data buah" << endl;
				break;
			default:
				cout << "Nomor yang anda masukkan salah!" << endl;
				break;
		}
		
		label_continue:
		
		cout << "Lanjutkan?(Y/N) : ";
		cin >> is_continue;
		if ( (is_continue == 'Y') | (is_continue == 'y') ){
			pilihan = getOption();
		} else if ( (is_continue == 'N') | (is_continue == 'n') ){
			break;
		} else {
			goto label_continue;
		}
		
		
	}
	
	cout << "Program selesai :)" << endl;
	 
	cin.get();
	return 0;
}
