#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

struct menu {
    string namamakanan,namaminuman;
    int hargamakanan,hargaminuman;
    menu *next;
};

void MergeHarga(menu *mkn, int left, int mid, int right, bool asde) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	menu Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = mkn[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = mkn[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (asde) {
		while (g < n1 && h < n2) {
			if (Left[g].hargamakanan <= Right[h].hargamakanan and Left[g].hargaminuman <= Right[h].hargaminuman) {
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
			if (Left[g].hargamakanan >= Right[h].hargamakanan and Left[g].hargaminuman >= Right[h].hargaminuman) {
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

void mergeSortHarga(menu *mkn, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortHarga(mkn, left, mid, asde);
		mergeSortHarga(mkn, mid + 1, right, asde);
		
		MergeHarga(mkn, left, mid, right, asde);
	}
}

int jumpSearchHarga(menu *mkn, int x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(mkn[min(step, n)-1].hargamakanan < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mkn[prev].hargamakanan < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mkn[prev].hargamakanan == x) {
        return prev;
    }

    while(mkn[min(step, n)-1].hargaminuman < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mkn[prev].hargaminuman < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mkn[prev].hargaminuman == x) {
        return prev;
    }
	return -1;
}

void searchHarga(menu *nilai){
    int x,panjang_node;
    menu info[panjang_node];
    menu* nilai_tampung = nilai;
    menu* data_sebelumnya = nilai;

    for (int i = 0; i < panjang_node; i++) {
		info[i].namamakanan = nilai->namamakanan;
		info[i].hargamakanan = nilai->hargamakanan;
        info[i].namaminuman = nilai->namaminuman;
		info[i].hargaminuman = nilai->hargaminuman;
		nilai = nilai->next;
	}

    mergeSortHarga(info, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		nilai_tampung->namamakanan = info[i].namamakanan;
		nilai_tampung->hargamakanan = info[i].hargamakanan;
        nilai_tampung->namaminuman = info[i].namaminuman;
		nilai_tampung->hargaminuman = info[i].hargaminuman;
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
        printf("Nama   : %s\n", info[indeks].namamakanan.c_str());
        printf("Harga  : %d\n", info[indeks].hargamakanan);
        printf("Nama   : %s\n", info[indeks].namaminuman.c_str());
        printf("Harga  : %s\n", info[indeks].hargaminuman);
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}