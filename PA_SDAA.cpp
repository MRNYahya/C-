#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

struct pemesanan {
    int hargamakan, hargaminum;
    string namamakan, namaminum, saos, level, toping, ukurangelas;
    pemesanan* prev;
    pemesanan* next;
};


pemesanan* head = new pemesanan();
pemesanan* tail = new pemesanan();
int panjang_node = 5;

string namamakanBaru, namaminumBaru, saosBaru, levelBaru, topingBaru, ukurangelasBaru;
int hargamakanBaru, hargaminumBaru, hargaTotal;


void MergeHarga(pemesanan *mkn, int left, int mid, int right, bool asde) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	pemesanan Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = mkn[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = mkn[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (asde) {
		while (g < n1 && h < n2) {
			if (Left[g].hargamakan <= Right[h].hargamakan) {
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
			if (Left[g].hargamakan >= Right[h].hargamakan) {
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

void mergeSortHarga(pemesanan *mkn, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortHarga(mkn, left, mid, asde);
		mergeSortHarga(mkn, mid + 1, right, asde);
		
		MergeHarga(mkn, left, mid, right, asde);
	}
}

void MergeNama(pemesanan *mkn, int left, int mid, int right, bool asde) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	pemesanan Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = mkn[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = mkn[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (asde) {
		while (g < n1 && h < n2) {
			if (Left[g].namamakan <= Right[h].namamakan) {
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
			if (Left[g].namamakan >= Right[h].namamakan) {
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

void mergeSortNama(pemesanan *mkn, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortNama(mkn, left, mid, asde);
		mergeSortNama(mkn, mid + 1, right, asde);
		
		MergeNama(mkn, left, mid, right, asde);
	}
}

int jumpSearchHarga(pemesanan *mkn, int x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(mkn[min(step, n)-1].hargamakan < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mkn[prev].hargamakan < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mkn[prev].hargamakan == x) {
        return prev;
    }
	return -1;
}

int jumpSearchNama(pemesanan *mkn, string x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(mkn[min(step, n)-1].namamakan < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mkn[prev].namamakan < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mkn[prev].namamakan == x) {
        return prev;
    }
	return -1;
}

void show(pemesanan* nilai) {
    int indeks = 1;

    system("cls");
    cout << "\n================= Daftar Menu =================\n";
	cout << "-----------------------------------------------" << endl;
    for(int i = 0; i < panjang_node; i++) {
        printf("               No pemesanan [ %d ]\n", indeks);
        cout << "-----------------------------------------------" << endl;
        printf("Nama   : %s\n", nilai->namamakan.c_str());
        printf("Harga  : %d\n", nilai->hargamakan);
        printf("Toping  : %s\n", nilai->toping.c_str());
        printf("Level  : %s\n", nilai->level.c_str());
        printf("Saos   : %s\n", nilai->saos.c_str());
        cout << "-----------------------------------------------" << endl;
        nilai = nilai->next;
        indeks++;
    }
    
}

void sort(pemesanan* nilai) {
    pemesanan info[panjang_node];
    pemesanan* nilai_tampung = nilai;
    pemesanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].namamakan = nilai->namamakan;
		info[i].hargamakan = nilai->hargamakan;
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
			nilai_tampung->namamakan = info[i].namamakan;
			nilai_tampung->hargamakan = info[i].hargamakan;
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

void tambahmakan(pemesanan **kepala, pemesanan **ekor) {
    pemesanan* nilai_baru = new pemesanan();
    int indeks = 1;

    ulang:
    system("cls");
    cout << "\n================= Tambah Data =================\n";
	cout << " ------------------ pemesanan -----------------" << endl;
    if(*kepala != NULL) {
		cout << "\n|  Data No. ";
		cin >> indeks;
		if(indeks > panjang_node) {
			indeks = panjang_node + 1;
		}
	}
    cout << "|  1) Nama pemesanan  : ";
    cin >> nilai_baru->namamakan;
    cout << "|  2) Harga pemesanan : ";
    cin >> nilai_baru->hargamakan;
    cout << "|  3) Toping        : ";
    cin >> nilai_baru->toping;
    cout << "|  4) Level         : ";
    cin >> nilai_baru->level;
    cout << "|  5) Saos          : ";
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
        pemesanan* data_sementara = *kepala;
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

void tambahminum(pemesanan **kepala, pemesanan **ekor) {
    pemesanan* nilai_baru = new pemesanan();
    int indeks = 1;

    ulang:
    system("cls");
    cout << "\n================= Tambah Data =================\n";
	cout << "  ------------------ Minuman -----------------" << endl;
    if(*kepala != NULL) {
		cout << "\n|  Data No. ";
		cin >> indeks;
		if(indeks > panjang_node) {
			indeks = panjang_node + 1;
		}
	}
    cout << "|  1) Nama Minuman   : ";
    cin >> nilai_baru->namaminum;
    cout << "|  2) Harga Minuman  : ";
    cin >> nilai_baru->hargaminum;
    cout << "|  3) Ukuran Gelas   : ";
    cin >> nilai_baru->ukurangelas;

    
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
        pemesanan* data_sementara = *kepala;
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

void ubahmakan(pemesanan *node_ke_n) {
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
    cin >> namamakanBaru;
    cout << "2) Harga Baru  : ";
    cin >> hargamakanBaru;
    cout << "2) Toping Baru  : ";
    cin >> topingBaru;
    cout << "4) Level Baru  : ";
    cin >> levelBaru;
    cout << "5) Saos Baru   : ";
    cin >> saosBaru;

    node_ke_n->namamakan = namamakanBaru;
    node_ke_n->hargamakan = hargamakanBaru;
    node_ke_n->toping = topingBaru;
    node_ke_n->level = levelBaru;
    node_ke_n->saos = saosBaru;

    cout << "-----------------------------------------------";
}

void ubahminum(pemesanan *node_ke_n) {
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
    cin >> namaminumBaru;
    cout << "2) Harga Baru  : ";
    cin >> hargaminumBaru;
    cout << "3) Ukuran gelas Baru  : ";
    cin >> ukurangelasBaru;

    node_ke_n->namaminum = namaminumBaru;
    node_ke_n->hargaminum  = hargaminumBaru;
    node_ke_n->toping = topingBaru;
    node_ke_n->ukurangelas = ukurangelasBaru;

    cout << "-----------------------------------------------";
}

void hapus(pemesanan **kepala, pemesanan **ekor) {
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
        pemesanan* data_sementara = *kepala;
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

void searchHargaMakan(pemesanan *nilai){
    int x;
    pemesanan info[panjang_node];
    pemesanan* nilai_tampung = nilai;
    pemesanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].namamakan = nilai->namamakan;
		info[i].hargamakan = nilai->hargamakan;
        info[i].toping = nilai->toping;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
		nilai = nilai->next;
	}

    mergeSortHarga(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->namamakan = info[i].namamakan;
		nilai_tampung->hargamakan = info[i].hargamakan;
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
        printf("Nama   : %s\n", info[indeks].namamakan.c_str());
        printf("Harga  : %d\n", info[indeks].hargamakan);
        printf("Toping : %s\n", info[indeks].toping.c_str());
        printf("Level  : %s\n", info[indeks].level.c_str());
        printf("Saos   : %s\n", info[indeks].saos.c_str());
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void searchNamaMakan(pemesanan *nilai){
    string x;
    pemesanan info[panjang_node];
    pemesanan* nilai_tampung = nilai;
    pemesanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].namamakan = nilai->namamakan;
		info[i].hargamakan = nilai->hargamakan;
        info[i].toping = nilai->toping;
		info[i].level = nilai->level;
		info[i].saos = nilai->saos;
		nilai = nilai->next;
	}

    mergeSortNama(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->namamakan = info[i].namamakan;
		nilai_tampung->hargamakan = info[i].hargamakan;
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
        printf("Nama   : %s\n", info[indeks].namamakan.c_str());
        printf("Harga  : %d\n", info[indeks].hargamakan);
        printf("Toping : %s\n", info[indeks].toping.c_str());
        printf("Level  : %s\n", info[indeks].level.c_str());
        printf("Saos   : %s\n", info[indeks].saos.c_str());
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void searchHargaMinum(pemesanan *nilai){
    int x;
    pemesanan info[panjang_node];
    pemesanan* nilai_tampung = nilai;
    pemesanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].namaminum = nilai->namaminum;
		info[i].hargaminum = nilai->hargaminum;
        info[i].ukurangelas = nilai->ukurangelas;
		nilai = nilai->next;
	}

    mergeSortHarga(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->namaminum = info[i].namaminum;
		nilai_tampung->hargaminum = info[i].hargaminum;
        nilai_tampung->ukurangelas = info[i].ukurangelas;
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
        printf("Nama   : %s\n", info[indeks].namaminum.c_str());
        printf("Harga  : %d\n", info[indeks].hargaminum);
        printf("Ukuran Gelas : %s\n", info[indeks].ukurangelas.c_str());
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void searchNamaMinum(pemesanan *nilai){
    string x;
    pemesanan info[panjang_node];
    pemesanan* nilai_tampung = nilai;
    pemesanan* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].namaminum = nilai->namaminum;
		info[i].hargaminum = nilai->hargaminum;
        info[i].ukurangelas = nilai->ukurangelas;
		nilai = nilai->next;
	}

    mergeSortNama(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->namaminum = info[i].namaminum;
		nilai_tampung->hargaminum = info[i].hargaminum;
        nilai_tampung->ukurangelas = info[i].ukurangelas;
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
        printf("Nama   : %s\n", info[indeks].namamakan.c_str());
        printf("Harga  : %d\n", info[indeks].hargamakan);
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
    enum opsi{NAMA_SEARCH_MAKAN = 1, HARGA_SEARCH_MAKAN, NAMA_SEARCH_MINUM, HARGA_SEARCH_MINUM};

    cout << "\n=============== Daftar Seaching ===============\n";
	cout << "-----------------------------------------------" << endl;
    cout << "1) Cari Nama" << endl;
    cout << "2) Cari Harga" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Pilih : ";cin >> pilih;
    switch(pilih) {
        case NAMA_SEARCH_MAKAN:
            searchNamaMakan(head);
            break;
        case HARGA_SEARCH_MAKAN:
            searchHargaMakan(head);
            break;
        case NAMA_SEARCH_MINUM:
            searchNamaMinum(head);
            break;
        case HARGA_SEARCH_MINUM:
            searchHargaMinum(head);
            break;
        default:
            cout << "\nMasukkan Angka yang ada!!!";
            getch();
            goto ulang;
    }
}

int main() {
    pemesanan* nilai_Dua = new pemesanan();
    pemesanan* nilai_Tiga = new pemesanan();
    pemesanan* nilai_Empat = new pemesanan();
    
    head->namamakan = "Ayam";
    head->hargamakan = 5000;
    head->toping = "-";
    head->level = "4";
    head->saos = "Saos_Keju";
    head->prev = NULL;
    head->next = nilai_Dua;

    nilai_Dua->namamakan = "NasGor";
    nilai_Dua->hargamakan = 12000;
    nilai_Dua->toping = "sosis";
    nilai_Dua->level = "2";
    nilai_Dua->saos = "Sambal";
    nilai_Dua->prev = head;
    nilai_Dua->next = nilai_Tiga;

    nilai_Tiga->namamakan = "MieGor";
    nilai_Tiga->hargamakan = 12000;
    nilai_Tiga->toping = "Pentol";
    nilai_Tiga->level = "1";
    nilai_Tiga->saos = "Sambal";
    nilai_Tiga->prev = nilai_Dua;
    nilai_Tiga->next = nilai_Empat;

    nilai_Empat->namamakan = "Lalapan";
    nilai_Empat->hargamakan = 18000;
    nilai_Empat->toping = "tahu,tempe,terong";
    nilai_Empat->level = "-";
    nilai_Empat->saos = "Sambal_Terasi";
    nilai_Empat->prev = nilai_Tiga;
    nilai_Empat->next = tail;

    tail->namamakan = "Bebek";
    tail->hargamakan = 20000;
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
    cout << "\n| 1. Tambah Daftar pemesanan                    |";
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
            tambahmakan(&head, &tail);
            break;
        case LIHAT:
            show(head);
            break;
        case EDIT:
            ubahmakan(head);
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
