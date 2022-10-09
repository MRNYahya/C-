#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include<math.h>

using namespace std;

struct Makanan {
    int harga,level;
    string nama,alamat,saos;
    Makanan* next;
};

Makanan* nilai_n = new Makanan();
int panjang_node = 5;

string namaBaru,alamatBaru,saosBaru;
int hargaBaru,levelBaru;


void MergeHarga(Makanan *mkn, int left, int mid, int right, bool asde) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	Makanan Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = mkn[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = mkn[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (asde) {
		while (g < n1 && h < n2) {
			if (Left[g].harga <= Right[h].harga) {
				mkn[i] = Left[g];
				g++;
			} else {
				mkn[i] = Right[h];
				h++;
			}
			i++;
		}
	} else {
		while (g < n1 && h < n2) {
			if (Left[g].harga >= Right[h].harga) {
				mkn[i] = Left[g];
				g++;
			} else {
				mkn[i] = Right[h];
				h++;
			}
			i++;
		}
	}
	
	while (g < n1) {
		mkn[i] = Left[g];
		g++;
		i++;
	}
	
	while (h < n2) {
		mkn[i] = Right[h];
		h++;
		i++;
	}
}

void mergeSortHarga(Makanan *mkn, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortHarga(mkn, left, mid, asde);
		mergeSortHarga(mkn, mid + 1, right, asde);
		
		MergeHarga(mkn, left, mid, right, asde);
	}
}

void MergeNama(Makanan *mkn, int left, int mid, int right, bool asde) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	Makanan Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = mkn[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = mkn[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (asde) {
		while (g < n1 && h < n2) {
			if (Left[g].nama <= Right[h].nama) {
				mkn[i] = Left[g];
				g++;
			} else {
				mkn[i] = Right[h];
				h++;
			}
			i++;
		}
	} else {
		while (g < n1 && h < n2) {
			if (Left[g].nama >= Right[h].nama) {
				mkn[i] = Left[g];
				g++;
			} else {
				mkn[i] = Right[h];
				h++;
			}
			i++;
		}
	}
	
	while (g < n1) {
		mkn[i] = Left[g];
		g++;
		i++;
	}
	
	while (h < n2) {
		mkn[i] = Right[h];
		h++;
		i++;
	}
}

void mergeSortNama(Makanan *mkn, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortNama(mkn, left, mid, asde);
		mergeSortNama(mkn, mid + 1, right, asde);
		
		MergeNama(mkn, left, mid, right, asde);
	}
}

int jumpSearchHarga(Makanan *mkn, int x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(mkn[min(step, n)-1].harga < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mkn[prev].harga < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mkn[prev].harga == x) {
        return prev;
    }
	return -1;
}

int jumpSearchNama(Makanan *mkn, string x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(mkn[min(step, n)-1].nama < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mkn[prev].nama < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mkn[prev].nama == x) {
        return prev;
    }
	return -1;
}

void show(Makanan* nilai) {
    int indeks = 1;

    system("cls");
    cout << "\n================= Daftar Menu =================\n";
	cout << "-----------------------------------------------" << endl;
    while(nilai != NULL){
        printf("               No Makanan [ %d ]\n", indeks);
        cout << "-----------------------------------------------" << endl;
        printf("Nama   : %s\n", nilai->nama.c_str());
        printf("Harga  : %d\n", nilai->harga);
        printf("Level  : %d\n", nilai->level);
        printf("Saos   : %s\n", nilai->saos.c_str());
        printf("Alamat : %s\n", nilai->alamat.c_str());
        cout << "-----------------------------------------------" << endl;
        nilai = nilai->next;
        indeks++;
    }
    
}

void sort(Makanan* nilai, int panjang_node) {
    Makanan info[panjang_node];
    Makanan* nilai_tampung = nilai;
    Makanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].nama = nilai->nama;
		info[i].harga = nilai->harga;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
		info[i].alamat = nilai->alamat;
		nilai = nilai->next;
	}

    ulang:
    system("cls");
    int pilih;
    enum opsi{Harga_Asc = 1, Harga_Des, Nama_Asc, Nama_Desc};

    cout << "\n================ Daftar Sorting ===============\n";
	cout << "-----------------------------------------------" << endl;
    cout << "1) Harga (Ascending)" << endl;
    cout << "2) Harga (Descending)" << endl;
    cout << "3) Nama (Ascending)" << endl;
    cout << "4) Nama (Descending)" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Pilih : ";cin >> pilih;
    
    switch(pilih) {
        case Harga_Asc:
            cout << "\n-----------------------------------------------";
            mergeSortHarga(info, 0, panjang_node - 1, true);
            goto reset_linkedlist;
            break;
        case Harga_Des:
            cout << "\n-----------------------------------------------";
            mergeSortHarga(info, 0, panjang_node - 1, false);
            goto reset_linkedlist;
            break;
        case Nama_Asc:
            cout << "\n-----------------------------------------------";
            mergeSortNama(info, 0, panjang_node - 1, true);
            goto reset_linkedlist;
            break;
        case Nama_Desc:
            cout << "\n-----------------------------------------------";
            mergeSortNama(info, 0, panjang_node - 1, false);
            goto reset_linkedlist;
            break;
        default:
            cout << "\nPilih nomor yang ada!!!";
            getch();
            goto ulang;
    }
    reset_linkedlist:
		for(int i = 0; i < panjang_node; i++) {
			nilai_tampung->nama = info[i].nama;
			nilai_tampung->harga = info[i].harga;
			nilai_tampung->level = info[i].level;
			nilai_tampung->saos = info[i].saos;
			nilai_tampung->alamat = info[i].alamat;
			if (i == 0) {
				data_sebelumnya = nilai_tampung;
			} else {
				data_sebelumnya->next = nilai_tampung;
				data_sebelumnya = data_sebelumnya->next;
			}
			nilai_tampung = nilai_tampung->next;
		}
        cout << "\n             Berhasil Diurutkan" << endl;
        cout << "-----------------------------------------------";
}

void tambah(Makanan** nilai1, Makanan* nilai2, int panjang_node) {
    Makanan* nilai_baru = new Makanan();
    Makanan info[panjang_node];

    for (int i = 0; i < panjang_node; i++) {
		info[i].nama = nilai2->nama;
		info[i].harga = nilai2->harga;
		info[i].level = nilai2->level;
		info[i].saos = nilai2->saos;
		info[i].alamat = nilai2->alamat;
		nilai2 = nilai2->next;
	}

    ulang:
    system("cls");
    cout << "\n================= Tambah Data =================\n";
	cout << "-----------------------------------------------" << endl;
    cout << "1) Nama   : ";
    cin >> nilai_baru->nama;
    cout << "2) Harga  : ";
    cin >> nilai_baru->harga;
    cout << "3) Level  : ";
    cin >> nilai_baru->level;
    cout << "4) Saos   : ";
    cin >> nilai_baru->saos;
    cout << "5) Alamat : ";
    cin >> nilai_baru->alamat;
    
    for(int i = 0; i < panjang_node; i++) {
        if(info[i].nama == nilai_baru->nama) {
            cout << "-----------------------------------------------";
            cout << "\n               Data Sudah Ada\n";
            cout << "-----------------------------------------------";
            goto ulang;
        } else {
            continue;
        }
    }
    if(*nilai1 == NULL) {
        *nilai1 = nilai_baru;
        panjang_node++;
        return;
    }
    Makanan *data_sementara = *nilai1;
    while(data_sementara->next != NULL) {
        data_sementara = data_sementara->next;
    }
    data_sementara->next = nilai_baru;
    panjang_node++;
}

void ubah(Makanan* nilai) {
    ulang:
    int nomor;
    
    system("cls");
    show(nilai);
    cout << "\n================== Edit Data ==================\n";
	cout << "-----------------------------------------------" << endl;
    
    cout << "Edit Menu Nomor : ";
	cin >> nomor;
    cout << "-----------------------------------------------";

    for (int i = 0; i < nomor - 1; i++) {
        nilai = nilai->next;
	}

    cout << "\n1) Nama Baru   : ";
    cin >> namaBaru;
    cout << "2) Harga Baru  : ";
    cin >> hargaBaru;
    cout << "3) Level Baru  : ";
    cin >> levelBaru;
    cout << "4) Saos Baru   : ";
    cin >> saosBaru;
    cout << "5) Alamat Baru : ";
    cin >> alamatBaru;

    nilai->nama = namaBaru;
    nilai->harga = hargaBaru;
    nilai->level = levelBaru;
    nilai->saos = saosBaru;
    nilai->alamat = alamatBaru;

    cout << "-----------------------------------------------";
}

void hapus(Makanan** nilai) {
    Makanan* data_sementara = *nilai;
    Makanan* data_sebelumnya = NULL;
    int nomor;
    
    system("cls");
    cout << "\n================== Hapus Data ==================\n";
	cout << "-----------------------------------------------" << endl;
    show(*nilai);
    
    cout << "\nHapus Menu Nomor : ";
	cin >> nomor;
	
    if(nomor == 1) {
        *nilai = data_sementara->next;
        panjang_node--;
        return;
    }
    for(int i = 0; i < nomor - 2; i++) {
        data_sementara = data_sementara->next;
    }

    data_sebelumnya = data_sementara;
    data_sementara = data_sementara->next;
    data_sebelumnya->next = data_sementara->next;
    panjang_node--;

    cout << "-----------------------------------------------";
    cout << "\n            Data Berhasil Di Hapus\n";
    cout << "-----------------------------------------------";

}

void searchHarga(Makanan* nilai, int panjang_node){
    int x;
    Makanan info[panjang_node];
    Makanan* nilai_tampung = nilai;
    Makanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].nama = nilai->nama;
		info[i].harga = nilai->harga;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
		info[i].alamat = nilai->alamat;
		nilai = nilai->next;
	}

    mergeSortHarga(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->nama = info[i].nama;
		nilai_tampung->harga = info[i].harga;
		nilai_tampung->level = info[i].level;
		nilai_tampung->saos = info[i].saos;
		nilai_tampung->alamat = info[i].alamat;
		if (i == 0) {
			data_sebelumnya = nilai_tampung;
		} else {
			data_sebelumnya->next = nilai_tampung;
			data_sebelumnya = data_sebelumnya->next;
		}
		nilai_tampung = nilai_tampung->next;
	}

    system("cls");
    cout << "-----------------------------------------------" << endl;
    cout << "Masukkan Harga yang ingin dicari : ";
    cin >> x;
    cout << "-----------------------------------------------" << endl;
    int indeks = jumpSearchHarga(info, x, panjang_node);
    if (indeks != -1) {
        cout << "-----------------------------------------------"<< endl;
        printf("Nama   : %s\n", info[indeks].nama.c_str());
        printf("Harga  : %d\n", info[indeks].harga);
        printf("Level  : %d\n", info[indeks].level);
        printf("Saos   : %s\n", info[indeks].saos.c_str());
        printf("Alamat : %s\n", info[indeks].alamat.c_str());
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void searchNama(Makanan* nilai, int panjang_node){
    string x;
    Makanan info[panjang_node];
    Makanan* nilai_tampung = nilai;
    Makanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].nama = nilai->nama;
		info[i].harga = nilai->harga;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
		info[i].alamat = nilai->alamat;
		nilai = nilai->next;
	}

    mergeSortNama(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->nama = info[i].nama;
		nilai_tampung->harga = info[i].harga;
		nilai_tampung->level = info[i].level;
		nilai_tampung->saos = info[i].saos;
		nilai_tampung->alamat = info[i].alamat;
		if (i == 0) {
			data_sebelumnya = nilai_tampung;
		} else {
			data_sebelumnya->next = nilai_tampung;
			data_sebelumnya = data_sebelumnya->next;
		}
		nilai_tampung = nilai_tampung->next;
	}

    system("cls");
    cout << "-----------------------------------------------" << endl;
    cout << "Masukkan Nama yang ingin dicari : ";
    cin >> x;
    cout << "-----------------------------------------------" << endl;
    int indeks = jumpSearchNama(info, x, panjang_node);
    if (indeks != -1) {
        cout << "-----------------------------------------------"<< endl;
        printf("Nama   : %s\n", info[indeks].nama.c_str());
        printf("Harga  : %d\n", info[indeks].harga);
        printf("Level  : %d\n", info[indeks].level);
        printf("Saos   : %s\n", info[indeks].saos.c_str());
        printf("Alamat : %s\n", info[indeks].alamat.c_str());
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void search() {
    ulang:
    system("cls");
    int pilih;
    enum opsi{NAMA_SEARCH = 1, HARGA_SEARCH};

    cout << "\n=============== Daftar Seaching ===============\n";
	cout << "-----------------------------------------------" << endl;
    cout << "1) Cari Nama" << endl;
    cout << "2) Cari Harga" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Pilih : ";cin >> pilih;
    switch(pilih) {
        case NAMA_SEARCH:
            searchNama(nilai_n, panjang_node);
            break;
        case HARGA_SEARCH:
            searchHarga(nilai_n, panjang_node);
            break;
        default:
            cout << "\nMasukkan Angka yang ada!!!";
            getch();
            goto ulang;
    }
}

int main() {
    Makanan* nilai_Dua = new Makanan();
    Makanan* nilai_Tiga = new Makanan();
    Makanan* nilai_Empat = new Makanan();
    Makanan* nilai_Lima = new Makanan();
    
    nilai_n->nama = "Ayam";
    nilai_n->harga = 5000;
    nilai_n->level = 1;
    nilai_n->saos = "Saos Keju";
    nilai_n->alamat = "Jl. Wahid Hasyim";
    nilai_n->next = nilai_Dua;

    nilai_Dua->nama = "NasGor";
    nilai_Dua->harga = 12000;
    nilai_Dua->level = 1;
    nilai_Dua->saos = "Sambal";
    nilai_Dua->alamat = "Jl. Pramuka";
    nilai_Dua->next = nilai_Tiga;

    nilai_Tiga->nama = "MieGor";
    nilai_Tiga->harga = 12000;
    nilai_Tiga->level = 1;
    nilai_Tiga->saos = "Sambal";
    nilai_Tiga->alamat = "Jl. Pramuka";
    nilai_Tiga->next = nilai_Empat;

    nilai_Empat->nama = "Lalapan";
    nilai_Empat->harga = 18000;
    nilai_Empat->level = 3;
    nilai_Empat->saos = "Sambal Terasi";
    nilai_Empat->alamat = "Jl. Kebahagiaan";
    nilai_Empat->next = nilai_Lima;

    nilai_Lima->nama = "Bebek";
    nilai_Lima->harga = 15000;
    nilai_Lima->level = 2;
    nilai_Lima->saos = "Sambal, Saos, Kecap";
    nilai_Lima->alamat = "Jl. Sempaja";
    nilai_Lima->next = NULL;

    ulang:
    system("cls");
    int pilih;
    enum opsi{TAMBAH = 1, LIHAT, EDIT, SORT, SEARCH, HAPUS, KELUAR};

    system("cls");
    cout << "\n================= PILIH MENU ==================";
    cout << "\n| 1. Tambah Daftar Makanan                    |";
    cout << "\n| 2. Lihat Menu                               |";
    cout << "\n| 3. Edit Menu                                |";
    cout << "\n| 4. Sort Menu                                |";
    cout << "\n| 5. Searching Menu                           |";
    cout << "\n| 6. Hapus Menu                               |";
    cout << "\n| 7. Keluar                                   |";
    cout << "\n===============================================";
    cout << "\n\nPilih : ";
    cin >> pilih;
    
    switch(pilih) {
        case TAMBAH:
        system("cls");
            tambah(&nilai_n,nilai_n,panjang_node);
            break;
        case LIHAT:
            show(nilai_n);
            break;
        case EDIT:
            ubah(nilai_n);
            break;
        case SORT:
            sort(nilai_n,panjang_node);
            break;
        case SEARCH:
            search();
            break;
        case HAPUS:
            hapus(&nilai_n);
            break;
        case KELUAR:
            exit(0);
        default:
            cout << "\nPilih nomor yang ada!!!";
    }
    cout << "\n\n               Enter : Kembali\n";
    getch();
    goto ulang;
}
