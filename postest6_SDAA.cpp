#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

struct Makanan {
    int harga;
    string nama,saos,level,toping;
    Makanan* prev;
    Makanan* next;
};

Makanan* head = new Makanan();
Makanan* tail = new Makanan();
int panjang_node = 5;

string namaBaru,saosBaru,levelBaru,topingBaru;
int hargaBaru;


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
    for(int i = 0; i < panjang_node; i++) {
        printf("               No Makanan [ %d ]\n", indeks);
        cout << "-----------------------------------------------" << endl;
        printf("Nama   : %s\n", nilai->nama.c_str());
        printf("Harga  : %d\n", nilai->harga);
        printf("Toping  : %s\n", nilai->toping.c_str());
        printf("Level  : %s\n", nilai->level.c_str());
        printf("Saos   : %s\n", nilai->saos.c_str());
        cout << "-----------------------------------------------" << endl;
        nilai = nilai->next;
        indeks++;
    }
    
}

void sort(Makanan* nilai) {
    Makanan info[panjang_node];
    Makanan* nilai_tampung = nilai;
    Makanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].nama = nilai->nama;
		info[i].harga = nilai->harga;
        info[i].toping = nilai->toping;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
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
            nilai_tampung->toping = info[i].toping;
			nilai_tampung->level = info[i].level;
			nilai_tampung->saos = info[i].saos;
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

void tambah(Makanan **kepala, Makanan **ekor) {
    Makanan* nilai_baru = new Makanan();
    int indeks = 1;

    ulang:
    system("cls");
    cout << "\n================= Tambah Data =================\n";
	cout << "-----------------------------------------------" << endl;
    if(*kepala != NULL) {
		cout << "\nData No. ";
		cin >> indeks;
		if(indeks > panjang_node) {
			indeks = panjang_node + 1;
		}
	}
    cout << "1) Nama   : ";
    cin >> nilai_baru->nama;
    cout << "2) Harga  : ";
    cin >> nilai_baru->harga;
    cout << "3) Toping  : ";
    cin >> nilai_baru->toping;
    cout << "4) Level  : ";
    cin >> nilai_baru->level;
    cout << "5) Saos   : ";
    cin >> nilai_baru->saos;
    
    if(*kepala == NULL){
		*kepala = nilai_baru;
		*ekor = nilai_baru;
		panjang_node++;
		return;
	}

    if(indeks == 1) {
        nilai_baru->prev = NULL;
        nilai_baru->next = *kepala;
        (*kepala)->prev = nilai_baru;
        (*kepala) = nilai_baru;
    } else if(indeks == panjang_node + 1) {
        nilai_baru->prev = *ekor;
        nilai_baru->next = NULL;
        (*ekor)->next = nilai_baru;
        *ekor = nilai_baru;
    } else {
        Makanan* data_sementara = *kepala;
        for(int i = 1; i < indeks; i++) {
            data_sementara = data_sementara->next;
        }
        nilai_baru->prev = data_sementara->prev;
        nilai_baru->next = data_sementara;
        data_sementara->prev->next = nilai_baru;
        data_sementara->prev = nilai_baru;
    }
    panjang_node++;
    cout << "-----------------------------------------------";
}

void ubah(Makanan *node_ke_n) {
    int nomor;

    ulang:
    system("cls");
    show(head);
    cout << "\n================== Edit Data ==================\n";
	cout << "-----------------------------------------------" << endl;
    
    cout << "Edit Menu Nomor : ";
	cin >> nomor;
    cout << "-----------------------------------------------";
    for (int i = 0; i < nomor - 1; i++) {
        node_ke_n = node_ke_n->next;
	}

    cout << "\n1) Nama Baru   : ";
    cin >> namaBaru;
    cout << "2) Harga Baru  : ";
    cin >> hargaBaru;
    cout << "2) Toping Baru  : ";
    cin >> topingBaru;
    cout << "4) Level Baru  : ";
    cin >> levelBaru;
    cout << "5) Saos Baru   : ";
    cin >> saosBaru;

    node_ke_n->nama = namaBaru;
    node_ke_n->harga = hargaBaru;
    node_ke_n->toping = topingBaru;
    node_ke_n->level = levelBaru;
    node_ke_n->saos = saosBaru;

    cout << "-----------------------------------------------";
}

void hapus(Makanan **kepala, Makanan **ekor) {
    int nomor;
    
    system("cls");
    show(head);
	cout << "\n================== Hapus Data ==================\n";
	cout << "-----------------------------------------------" << endl;
    if (*kepala == NULL) {
		cout << "\nNo Data!";
        cout << "\nDelete Failed";
        cout << "-----------------------------------------------" << endl;
		return;
	} else {
        Makanan* data_sementara = *kepala;
		if(*kepala == *ekor) {
			*kepala = NULL;
			*ekor = NULL;
			return;
		}

        cout << "\nHapus Menu Nomor : ";
	    cin >> nomor;
        cout << "-----------------------------------------------" << endl;

		if(nomor == 1) {
			*kepala = data_sementara->next;
			(*kepala)->prev = NULL;
			delete data_sementara;
			panjang_node--;
		} else if(nomor == panjang_node) {
			data_sementara = *ekor;
			*ekor = data_sementara->prev;
			(*ekor)->next = NULL;
			delete data_sementara;
			panjang_node--;
		} else {
			for(int i = 1; i < nomor; i++) {
				data_sementara = data_sementara->next;
			}
			data_sementara->next->prev = data_sementara->prev;
			data_sementara->prev->next = data_sementara->next;
			delete data_sementara;
			panjang_node--;
		}
    cout << "-----------------------------------------------";
    cout << "\n            Data Berhasil Di Hapus\n";
    cout << "-----------------------------------------------";
	}
}

void searchHarga(Makanan *nilai){
    int x;
    Makanan info[panjang_node];
    Makanan* nilai_tampung = nilai;
    Makanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].nama = nilai->nama;
		info[i].harga = nilai->harga;
        info[i].toping = nilai->toping;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
		nilai = nilai->next;
	}

    mergeSortHarga(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->nama = info[i].nama;
		nilai_tampung->harga = info[i].harga;
        nilai_tampung->toping = info[i].toping;
		nilai_tampung->level = info[i].level;
		nilai_tampung->saos = info[i].saos;
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
        printf("Toping : %s\n", info[indeks].toping.c_str());
        printf("Level  : %s\n", info[indeks].level.c_str());
        printf("Saos   : %s\n", info[indeks].saos.c_str());
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void searchNama(Makanan *nilai){
    string x;
    Makanan info[panjang_node];
    Makanan* nilai_tampung = nilai;
    Makanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].nama = nilai->nama;
		info[i].harga = nilai->harga;
        info[i].toping = nilai->toping;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
		nilai = nilai->next;
	}

    mergeSortNama(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->nama = info[i].nama;
		nilai_tampung->harga = info[i].harga;
        nilai_tampung->toping = info[i].toping;
		nilai_tampung->level = info[i].level;
		nilai_tampung->saos = info[i].saos;
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
        printf("Toping : %s\n", info[indeks].toping.c_str());
        printf("Level  : %s\n", info[indeks].level.c_str());
        printf("Saos   : %s\n", info[indeks].saos.c_str());
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
            searchNama(head);
            break;
        case HARGA_SEARCH:
            searchHarga(head);
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
    
    head->nama = "Ayam";
    head->harga = 5000;
    head->toping = "-";
    head->level = "4";
    head->saos = "Saos_Keju";
    head->prev = NULL;
    head->next = nilai_Dua;

    nilai_Dua->nama = "NasGor";
    nilai_Dua->harga = 12000;
    nilai_Dua->toping = "sosis";
    nilai_Dua->level = "2";
    nilai_Dua->saos = "Sambal";
    nilai_Dua->prev = head;
    nilai_Dua->next = nilai_Tiga;

    nilai_Tiga->nama = "MieGor";
    nilai_Tiga->harga = 12000;
    nilai_Tiga->toping = "Pentol";
    nilai_Tiga->level = "1";
    nilai_Tiga->saos = "Sambal";
    nilai_Tiga->prev = nilai_Dua;
    nilai_Tiga->next = nilai_Empat;

    nilai_Empat->nama = "Lalapan";
    nilai_Empat->harga = 18000;
    nilai_Empat->toping = "tahu,tempe,terong";
    nilai_Empat->level = "-";
    nilai_Empat->saos = "Sambal_Terasi";
    nilai_Empat->prev = nilai_Tiga;
    nilai_Empat->next = tail;

    tail->nama = "Bebek";
    tail->harga = 20000;
    tail->toping = "tahu,tempe,terong";
    tail->level = "-";
    tail->saos = "Sambal Terasi";
    tail->prev = nilai_Empat;
    tail->next = NULL;

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
            tambah(&head, &tail);
            break;
        case LIHAT:
            show(head);
            break;
        case EDIT:
            ubah(head);
            break;
        case SORT:
            sort(head);
            break;
        case SEARCH:
            search();
            break;
        case HAPUS:
            hapus(&head, &tail);
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