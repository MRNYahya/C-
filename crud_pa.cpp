#include<iostream>
#include<conio.h>
#include <windows.h>
#include<math.h>
#include <fstream>

using namespace std;

struct pesanan {
    string nomormeja,pw;
	int nomakanan, nominuman, konfir;
    pesanan* prev;
    pesanan* next;
};

struct menu{
	string namamakanan,namaminuman,ukurangelas;
	int hargamakanan,hargaminuman;
	menu *next;
};



struct pesananjadi{
	string nomormeja,namamakanan,namaminuman,pw;
	int hargamakanan,hargaminuman,total,konfir;
	pesananjadi* next;
    pesananjadi* prev;
};

pesananjadi *awal = NULL, *akhir = NULL,*hps;

menu *kepala;
menu  *ekor ;
int panjangmenu = 0;

pesanan *head = NULL,*tail = NULL,*del;
int panjang_node = 0;
int pesanansdh = 0;
int tanda = 0;
int datahps = 0;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoXY(int x, int y) { 
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console,CursorPosition); 
}

void gotoX(int x){
	CursorPosition.X = x;
	SetConsoleCursorPosition(console,CursorPosition); 
}

bool isEmpty(){
	if (kepala==NULL)
		return true;
	return false;
}

bool isEmpty1(){
	if (awal==NULL)
		return true;
	return false;
}

void tampilmenu();
void login();
void showpesanan_blm(pesanan* tail);
void showpesanan(pesanan* tail,pesananjadi *akhir);
void showpesanan_sdh();
void hpsdata(pesanan **head,pesanan **tail);

//====================ADMIN=========================//

void datamenu( string namamkn, string namamnm, int hargamkn, int hargamnm){
    struct menu *menu1;
    menu1->namamakanan = namamkn;
    menu1->hargamakanan = hargamkn;
    menu1->namaminuman = namamnm;
    menu1->hargaminuman = hargamnm;
} 

void menumasuk(string namamakan,string namaminum, int hargamakan, int hargaminum){
	menu *masuk = new menu;
	datamenu(namamakan, namaminum, hargamakan, hargaminum);
	masuk->next = NULL;
	if (isEmpty()){
		kepala = masuk;
		kepala->next = NULL;
	}
	else{
		masuk->next = kepala;
		kepala = masuk;
	}
	
	panjangmenu++;
}

void konfirpesanan(pesanan *tail,pesananjadi **awal, pesananjadi **akhir){
	string a;
	tanda = 0;
	system("cls");
	if (tail == NULL) {
		system("cls");
		gotoXY(60,5);cout<<"==================== Daftar Menu =================="<<endl;
		gotoXY(60,6);cout<<"++                Belum Ada Pesanan              ++"<<endl;
		gotoXY(60,7);cout<<"==================================================="<<endl;
	}
	else {
		gotoXY(60,5);cout<<"================= Daftar Menu ================="<<endl;;
		gotoXY(60,6);cout<<"-----------------------------------------------"<<endl;
		for (int x = 0; x<panjang_node;x++){
			ulang:
			pesananjadi *jadi  = new pesananjadi();
			cout<<"\n";
			cout<<"\t\t\t\t\t\t\t    ===============================================" << endl;
	        cout<<"\t\t\t\t\t\t\t                      No pesanan "<< x+1<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        cout<<"\t\t\t\t\t\t\t    No Meja        : "<<tail->nomormeja<<endl;
	        cout<<"\t\t\t\t\t\t\t    No Makanan     : "<<tail->nomakanan<<endl;
	        cout<<"\t\t\t\t\t\t\t    No Minuman     : "<<tail->nominuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    --------------Pesanan Anda Belum Siap----------"<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        cout<<"\t\t\t\t\t\t\t      Tekan PIN Untuk Konfirmasi Pesanan >> "; cin >> a;
	        if (a == "110011"){
	        	cout<<"\t\t\t\t\t\t\t         Pesanan "<<x+1<< " Berhasil Di  Konfirmasi    "<<endl;
	        	cout<<"\t\t\t\t\t\t\t    -----------------------------------------------"<<endl;
	        	tail->konfir = 1;
	        	datahps++;
	        	struct menu *makan;
				makan = kepala ;
				struct menu *minum;
				minum = kepala ;

				for (int x = 1 ; x <= panjangmenu;x++){
					
					if(tail->nomakanan != x){
						makan = makan->next;
						minum = minum->next;
					}else{
						jadi->namamakanan  = makan->namamakanan;
						jadi->hargamakanan = makan->hargamakanan;
						jadi->namaminuman  = minum->namaminuman;
						jadi->hargaminuman = minum->hargaminuman;
						jadi->nomormeja = tail->nomormeja;
						jadi->pw = tail->pw;
						
					}
				}
				if(*awal == NULL) {
					*awal = jadi;
					*akhir = jadi;
					jadi = jadi->next;
					tail = tail->prev;
	        		pesanansdh++;
				} else {
					jadi->prev = NULL;
					jadi->next = *awal;
					(*awal)->prev = jadi;
					(*awal) = jadi;
					jadi = jadi->next;
					tail = tail->prev;
	        		pesanansdh++;
				}
	        	
			}
	        else{
	        	system("cls");
	        	cout<<"\n\n\n\n\t\t\t\t\t\t\t    --------------Pesanan GAGAL di Konfirmasi----------"<<endl;
	        	cout<<"\t\t\t\t\t\t\t                        Enter Kembali : ";
	            getch();
	    		goto ulang;
	        	
			}
		}
	}
	return;
}

void hpsdata(pesanan **head,pesanan **tail){
	panjang_node--;
	if(*head == *tail){
		*head = NULL;
		*tail = NULL;
		return;
		}
	del = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	delete del;
}

int admin(pesanan *tail){
	system("cls");
	ulang:
	char pilih;
	system("cls");
	gotoXY(60,4);cout<<"==================== ADMIN ===================="<<endl;
    gotoXY(60,5);cout<<"|| 1. Konfirmasi Pesanan                     ||"<<endl;
    gotoXY(60,6);cout<<"|| 2. Lihat Antrian                          ||"<<endl;
    gotoXY(60,7);cout<<"|| 3. Lihat Pesanan Siap                     ||"<<endl;
    gotoXY(60,8);cout<<"|| 0. Keluar                                 ||"<<endl;
    gotoXY(60,9);cout<<"==============================================="<<endl;
    gotoXY(60,10);cout<<"  Pilih : ";cin>>pilih;
    switch(pilih){
    	case '1':{
    		konfirpesanan(tail,&awal,&akhir);
    		if(tail != NULL){
	    		for (int y = 0; y < datahps; y++){
    				hpsdata(&head,&tail);
				}
			}
			break;
		}
		case '2':{
			showpesanan_blm(tail);
			break;
		}
		case '3':{
			showpesanan_sdh();
			break;
		}
		case '0':
           login();
        default:
            system("cls");
            gotoXY(70,10);cout << "Pilih nomor yang ada!!!"<<endl;
            gotoXY(70,11);cout << "Enter Kembali : ";
            getch();
    		goto ulang;
    }
	cout << "\n\t\t\t\t\t\t\t\tEnter Kembali : ";
    getch();
	goto ulang;
}

void MergeHargamakan(menu *mkn, int left, int mid, int right, bool asde) {
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
			if (Left[g].hargamakanan <= Right[h].hargamakanan) {
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
			if (Left[g].hargamakanan >= Right[h].hargamakanan) {
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

void mergeSortHargamakan(menu *mkn, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortHargamakan(mkn, left, mid, asde);
		mergeSortHargamakan(mkn, mid + 1, right, asde);
		
		MergeHargamakan(mkn, left, mid, right, asde);
	}
}

void MergeNamamakan(menu *mkn, int left, int mid, int right, bool asde) {
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
			if (Left[g].namamakanan <= Right[h].namamakanan) {
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
			if (Left[g].namamakanan >= Right[h].namamakanan) {
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

void mergeSortNamamakan(menu *mkn, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortNamamakan(mkn, left, mid, asde);
		mergeSortNamamakan(mkn, mid + 1, right, asde);
		
		MergeNamamakan(mkn, left, mid, right, asde);
	}
}

void sortmakan(menu* nilai,int secara) {
    menu info[panjangmenu];
    menu* nilai_tampung = nilai;
    menu* data_sebelumnya = nilai;

    for (int i = 0; i < panjangmenu; i++) {
		info[i].namamakanan = nilai->namamakanan;
		info[i].hargamakanan = nilai->hargamakanan;
		nilai = nilai->next;
	}
	if (secara == 1){
		mergeSortHargamakan(info, 0, panjangmenu -1, true);
		goto sini;
	}
	else if (secara == 2){
		mergeSortHargamakan(info, 0, panjangmenu - 1, false);
		goto sini;
	}
	else if (secara == 3){
		mergeSortNamamakan(info, 0, panjangmenu -1, true);
		goto sini;
	}
	else if (secara == 4){
		mergeSortNamamakan(info, 0, panjangmenu - 1, false);
		goto sini;
	}
    sini:
		for(int i = 0; i < panjangmenu; i++) {
			nilai_tampung->namamakanan = info[i].namamakanan;
			nilai_tampung->hargamakanan = info[i].hargamakanan;
			if (i == 0) {
				data_sebelumnya = nilai_tampung;
			} else {
				data_sebelumnya->next = nilai_tampung;
				data_sebelumnya = data_sebelumnya->next;
			}
			nilai_tampung = nilai_tampung->next;
		}
}

void MergeHargaminum(menu *mnm, int left, int mid, int right, bool asde) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	menu Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = mnm[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = mnm[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (asde) {
		while (g < n1 && h < n2) {
			if (Left[g].hargaminuman <= Right[h].hargaminuman) {
				mnm[i] = Left[g];
				g++;
			} else {
				mnm[i] = Right[h];
				h++;
			}
			i++;
		}
	} else {
		while (g < n1 && h < n2) {
			if (Left[g].hargaminuman >= Right[h].hargaminuman) {
				mnm[i] = Left[g];
				g++;
			} else {
				mnm[i] = Right[h];
				h++;
			}
			i++;
		}

	}
	
	while (g < n1) {
		mnm[i] = Left[g];
		g++;
		i++;
	}
	
	while (h < n2) {
		mnm[i] = Right[h];
		h++;
		i++;
	}
}

void mergeSortHargaminum(menu *mnm, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortHargaminum(mnm, left, mid, asde);
		mergeSortHargaminum(mnm, mid + 1, right, asde);
		
		MergeHargaminum(mnm, left, mid, right, asde);
	}
}

void MergeNamaminum(menu *mnm, int left, int mid, int right, bool asde) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	menu Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = mnm[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = mnm[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (asde) {
		while (g < n1 && h < n2) {
			if (Left[g].namaminuman <= Right[h].namaminuman) {
				mnm[i] = Left[g];
				g++;
			} else {
				mnm[i] = Right[h];
				h++;
			}
			i++;
		}
	} else {
		while (g < n1 && h < n2) {
			if (Left[g].namaminuman >= Right[h].namaminuman) {
				mnm[i] = Left[g];
				g++;
			} else {
				mnm[i] = Right[h];
				h++;
			}
			i++;
		}

	}
	
	while (g < n1) {
		mnm[i] = Left[g];
		g++;
		i++;
	}
	
	while (h < n2) {
		mnm[i] = Right[h];
		h++;
		i++;
	}
}

void mergeSortNamaminum(menu *mnm, int left, int right, bool asde) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSortNamaminum(mnm, left, mid, asde);
		mergeSortNamaminum(mnm, mid + 1, right, asde);
		
		MergeNamaminum(mnm, left, mid, right, asde);
	}
}

void sortminum(menu* nilai,int secara) {
    menu info[panjangmenu];
    menu* nilai_tampung = nilai;
    menu* data_sebelumnya = nilai;

    for (int i = 0; i < panjangmenu; i++) {
		info[i].namaminuman = nilai->namaminuman;
		info[i].hargaminuman = nilai->hargaminuman;
		nilai = nilai->next;
    }
    if (secara == 1){
		mergeSortHargaminum(info, 0, panjangmenu -1, true);
		goto sini;
	}
	else if (secara == 2){
		mergeSortHargaminum(info, 0, panjangmenu - 1, false);
		goto sini;
	}
	else if (secara == 3){
		mergeSortNamaminum(info, 0, panjangmenu -1, true);
		goto sini;
	}
	else if (secara == 4){
		mergeSortNamaminum(info, 0, panjangmenu - 1, false);
		goto sini;
	}
    sini:
		for(int i = 0; i < panjangmenu; i++) {
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
}

int jumpSearchNamamakan(menu *mkn, string x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(mkn[min(step, n)-1].namamakanan < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mkn[prev].namamakanan < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mkn[prev].namamakanan == x) {
        return prev;
    }
	return -1;
}

void searchNamamakan(menu *nilai){
    string x;
    menu info[panjangmenu];
    menu* nilai_tampung = nilai;
    menu* data_sebelumnya = nilai;

    for (int i = 0; i < panjangmenu; i++) {
		info[i].namamakanan = nilai->namamakanan;
		info[i].hargamakanan = nilai->hargamakanan;
		nilai = nilai->next;
	}

    mergeSortNamamakan(info, 0, panjangmenu - 1, true);
    for (int i = 0; i < panjangmenu; i++) {
		nilai_tampung->namamakanan = info[i].namamakanan;
		nilai_tampung->hargamakanan = info[i].hargamakanan;
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
    cout << "Masukkan Nama Makanan yang ingin dicari : ";
    cin >> x;
    cout << "-----------------------------------------------" << endl;
    int indeks = jumpSearchNamamakan(info, x, panjangmenu);
    if (indeks != -1) {
		printf("Nama Makanan  : %s\n", info[indeks].namamakanan.c_str());
        printf("Harga Makanan : %d\n", info[indeks].hargamakanan);
    } else {
        cout << "Nama tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

int jumpSearchNamaminum(menu *mnm, string x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(mnm[min(step, n)-1].namaminuman < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(mnm[prev].namaminuman < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(mnm[prev].namaminuman == x) {
        return prev;
    }
	return -1;
}

void searchNamaminum(menu *nilai){
    string x;
    menu info[panjangmenu];
    menu* nilai_tampung = nilai;
    menu* data_sebelumnya = nilai;

    for (int i = 0; i < panjangmenu; i++) {
		info[i].namaminuman = nilai->namaminuman;
		info[i].hargaminuman = nilai->hargaminuman;
		nilai = nilai->next;
	}

    mergeSortNamaminum(info, 0, panjangmenu - 1, true);
    for (int i = 0; i < panjangmenu; i++) {
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
    cout << "Masukkan Nama Makanan yang ingin dicari : ";
    cin >> x;
    cout << "-----------------------------------------------" << endl;
    int indeks = jumpSearchNamaminum(info, x, panjangmenu);
    if (indeks != -1) {
		printf("Nama Makanan  : %s\n", info[indeks].namaminuman.c_str());
        printf("Harga Makanan : %d\n", info[indeks].hargaminuman);
    } else {
        cout << "Nama tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void updatedata(string ganti,pesanan *head){
    bool ketemu=false;
    while(head!=NULL)
    {
        if(head->pw == ganti){
            ketemu = true;
            system("cls");
            tampilmenu();
            cout<<"\n";
	        cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
	        cout<<"\t\t\t\t\t\t\t    --------------------Ubah Pesanan---------------"<<endl;
	        cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
	        cout<<"\t\t\t\t\t\t\t    No Meja      : "<<tail->nomormeja<<endl;
	        cout<<"\t\t\t\t\t\t\t    No Makanan   : "<<head->nomakanan<<endl;
	        cout<<"\t\t\t\t\t\t\t    No Minuman   : "<<head->nominuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    ------------Pesanan Yang Ingin di Ubah---------"<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------"<< endl;
	        cout<<"\t\t\t\t\t\t                   1. Nomor Makanan    >> ";cin >> head->nomakanan;
			cout<<"\t\t\t\t\t\t                   2. Nomor Minuman    >> ";cin >> head->nominuman;
			cout<<"\t\t\t\t\t\t\t    ------------Pesanan Berhasil di Ubah-----------"<<endl;
			cout<<"\t\t\t\t\t\t\t    -----------------------------------------------"<< endl;
        }
    head=head->next;
    }
    if(ketemu == false)
    {
    	system("cls");
        cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
        cout<<"\t\t\t\t\t\t\t    ------------Pesanan Tidak Di temukan-----------"<<endl;
        cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
        return;
    }
}

//=========================//
int hapus(string dihapus){
    struct pesanan *head, *sebelum;
    head=head;
    while(head!=NULL)
    {
        if(head->pw==dihapus)
        {
            if(head==head)
            {
                head=head->next;
                return 1;
            }
            else
            {
                sebelum->next=head->next;
                return 1;
            }
        }
        else
        {
            sebelum=head;
            head= head->next;
        }
        system("cls");
        cout<<"\n";
        cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
        cout<<"\t\t\t\t\t\t\t    --------------Pesanan Anda Terhapus------------"<<endl;
        cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
        panjang_node--;
    }
    system("cls");
    cout<<"\n";
    cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
    cout<<"\t\t\t\t\t\t\t    ------------Pesanan Tidak Di temukan-----------"<<endl;
    cout<<"\t\t\t\t\t\t\t    ==============================================="<< endl;
    return 0;
}

//====================USER==========================//

void tampilmenu (){
	struct menu *lihat ;
	lihat = kepala ;
	gotoXY(20,2);cout<<"+====================================================================================================================+"<<endl;
	gotoXY(20,3);cout<<"+==========================================================CAFE C2Y==================================================+"<<endl;
	gotoXY(20,4);cout<<"+====================================================================================================================+"<<endl;
	gotoXY(20,5);cout<<"\n"<<endl;
	gotoXY(20,6);cout<<"  No \t Makanan \t\t Harga Makanan \t\t No \t\t Minuman \t\t Harga Minuman "<<endl;
	for (int x = 0;x<panjangmenu;x++){
		gotoXY(20,x+7);cout<<"  "<<x+1<<".    \t "<<lihat->namamakanan << "\t\t Rp." << lihat->hargamakanan << "\t\t "  <<x+1<<".\t\t " << lihat->namaminuman<< "\t\t Rp." << lihat->hargaminuman<<endl;
		lihat = lihat->next;
	}cout<<"\n"<<endl;
}


void showpesanan_sdh(){
	system("cls");
	struct pesananjadi *lihat = akhir;
	if (lihat == NULL) {
		system("cls");
		gotoXY(60,5);cout<<"==================== Daftar Menu =================="<<endl;
		gotoXY(60,6);cout<<"++                Belum Ada Pesanan              ++"<<endl;
		gotoXY(60,7);cout<<"==================================================="<<endl;
		return;
	}else{
		system("cls");
	    gotoXY(60,5);cout<<"================= Daftar Menu ================="<<endl;;
		gotoXY(60,6);cout<<"-----------------------------------------------"<<endl;
		for (int x = 0; x<pesanansdh;x++){
	        cout<<"\n";
			cout<<"\t\t\t\t\t\t\t    ===============================================" << endl;
	        cout<<"\t\t\t\t\t\t\t                      No pesanan "<< x+1<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        cout<<"\t\t\t\t\t\t\t    No Meja       : "<<lihat->nomormeja<<endl;
	        cout<<"\t\t\t\t\t\t\t    Nama Makanan  : "<<lihat->namamakanan<<endl;
	        cout<<"\t\t\t\t\t\t\t    Nama Minuman  : "<<lihat->namaminuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    Harga Makanan : Rp."<<lihat->hargamakanan<<endl;
	        cout<<"\t\t\t\t\t\t\t    Harga Minuman : Rp."<<lihat->hargaminuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    Total         : Rp."<<lihat->hargamakanan+lihat->hargaminuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    --------------Pesanan Ini Sudah Siap-----------"<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        lihat = lihat->prev;
		}
	}	
}

void showpesanan_blm(pesanan *tail){
	if (tail == NULL) {
		system("cls");
		gotoXY(60,5);cout<<"==================== Daftar Menu =================="<<endl;
		gotoXY(60,6);cout<<"++                Belum Ada Pesanan              ++"<<endl;
		gotoXY(60,7);cout<<"==================================================="<<endl;
		return;
	}else{
	    system("cls");
	   	gotoXY(60,5);cout<<"================= Daftar Menu ================="<<endl;;
		gotoXY(60,6);cout<<"-----------------------------------------------"<<endl;
		for (int x = 0; x<panjang_node;x++){
			cout<<"\n";
			cout<<"\t\t\t\t\t\t\t    ===============================================" << endl;
	        cout<<"\t\t\t\t\t\t\t                      No pesanan "<< x+1<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        cout<<"\t\t\t\t\t\t\t    No Meja      : "<<tail->nomormeja<<endl;
	        cout<<"\t\t\t\t\t\t\t    No Makanan   : "<<tail->nomakanan<<endl;
	        cout<<"\t\t\t\t\t\t\t    No Minuman   : "<<tail->nominuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    ---------------Pesanan Ini Belum Siap----------"<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        tail = tail->prev;
		}		
	}
	
}

void tambahpesanan(pesanan **head, pesanan **tail) {
    pesanan* baru = new pesanan();
    cout<<"\t\t\t\t\t\t    ++========================== Tambah Data ===========================++"<<endl;
	cout<<"\t\t\t\t\t\t    ++--------------------------  Data No."<<panjang_node+1<<"  ---------------------------++"<<endl;
	cout<<"\t\t\t\t\t\t    ++==================================================================++"<<endl;
	cout<<"\n";
    cout<<"\t\t\t\t\t\t                           1. Nomor Meja Anda  >> ";cin >> baru->nomormeja;
	cout<<"\t\t\t\t\t\t                           2. Nomor Makanan    >> ";cin >> baru->nomakanan;
	cout<<"\t\t\t\t\t\t                           3. Nomor Minuman    >> ";cin >> baru->nominuman;
	cout<<"\t\t\t\t\t\t      ------------------------------------------------------------------" << endl;
	cout<<"\t\t\t\t\t\t                       Masukan 3 Angka Untuk Pin Anda    >> ";cin >> baru->pw;
	baru->konfir = 0;
	if (*head == NULL) {
		*head = baru;
		*tail = baru;
	} else {
		baru->prev = NULL;
		baru->next = *head;
		(*head)->prev = baru;
		(*head) = baru;
	}
    panjang_node++;
    ;
}

int user() {
	
    ulang:
    system("cls");
    char pilih;
	tampilmenu();
    cout<<"\t\t\t\t\t\t\t    ================= PILIH MENU =================="<<endl;
    cout<<"\t\t\t\t\t\t\t    || 1. Pemesanan                              ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    || 2. Lihat Antrian                          ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    || 3. Lihat Pesanan Siap                     ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    || 4. Ubah Pesanan                           ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    || 5. Hapus Pesanan                          ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    || 6. Urutkan Menu                           ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    || 7. Cari Nama Menu                         ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    || 0. Keluar                                 ||"<<endl;
    cout<<"\t\t\t\t\t\t\t    ==============================================="<<endl;
    cout<<"\t\t\t\t\t\t\t      Pilih : ";
    cin >> pilih;
    switch(pilih) {
        case '1':{
			if (tanda == 2){
				system("cls");
				gotoXY(70,6);cout << "Pesanan Harus Di Konfirmasi Terlebih Dahulu!!!"<<endl;
            	break;	
			}
			else{
				tanda = 1;
				system("cls");
	        	tampilmenu();
	        	tambahpesanan(&head, &tail);
	        	showpesanan_blm(tail);
	            break;
			}
        	
        }    
        case '2':{
            showpesanan_blm(tail);
            break;
        }
		case '3':{
		    showpesanan_sdh();
			break;
		}
        case '4':{
        	string ganti;
            showpesanan_blm(tail);
            if (panjang_node > 0){
            	cout<<"\n\n"<<endl;
	            cout<<"\t\t\t\t\t\t\t    ================= Ubah Pesanan =================="<<endl;
	            cout<<"\t\t\t\t\t\t                   Masukan PIN Pesanan Anda    >> ";cin >> ganti;
	            updatedata(ganti,head);
			}
			break;
        }
        case '5':{
            string dihapus;
            showpesanan_blm(tail);
            if (panjang_node > 0){
            	cout<<"\n\n"<<endl;
	            cout<<"\t\t\t\t\t\t\t    ================= Hapus Pesanan ==============="<<endl;
	            cout<<"\t\t\t\t\t\t                   Masukan PIN Pesanan Anda    >> ";cin >> dihapus;
	            hapus(dihapus);
			}
            break;
        }
        case '6':{
        	awal:
		    system("cls");
		    int secara;
		    if (tanda == 1){
		    	system("cls");
				gotoXY(70,6);cout << "Pesanan Harus Di Konfirmasi Terlebih Dahulu!!!"<<endl;
            	break;	
			}
			else{
				tanda++;
			    cout<<"\n\n"<<endl;
			    cout<<"\t\t\t\t\t\t\t    ================ Daftar Sorting ==============="<<endl;
				cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
			    cout<<"\t\t\t\t\t\t\t    || 1. Harga Termurah - Termahal              ||"<<endl;
	    		cout<<"\t\t\t\t\t\t\t    || 2. Harga Termahal - Termurah              ||"<<endl;
				cout<<"\t\t\t\t\t\t\t    || 3. Nama Terkecil - Terbesar               ||"<<endl;
	    		cout<<"\t\t\t\t\t\t\t    || 4. Nama Terbesar - Terkecil               ||"<<endl;
	    		cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	    		cout<<"\n";
	    		cout<<"\t\t\t\t\t\t\t          Pilih : ";cin >> secara;
			    cout<<"\t\t\t\t\t\t\t    ==============================================="<<endl;
			    
			    switch(secara) {
			        case 1:
			        	sortminum(kepala,secara);
			            sortmakan(kepala,secara);
			            break;
			        case 2:
						sortmakan(kepala,secara);
						sortminum(kepala,secara);
			            break;
					case 3:
			        	sortminum(kepala,secara);
			            sortmakan(kepala,secara);
			            break;
			        case 4:
						sortmakan(kepala,secara);
						sortminum(kepala,secara);
			            break;
			        default:
			        	system("cls");
			            gotoXY(70,10);cout << "Pilih nomor yang ada!!!"<<endl;
	            		gotoXY(70,11);cout << "Enter Kembali : ";
			            getch();
			            goto awal;
			            break;
			        }
			    break;
			}
		}
        case '7':{
			int secara;
			system("cls");
            cout<<"\n\n"<<endl;
			cout<<"\t\t\t\t\t\t\t    ================ Daftar Sorting ==============="<<endl;
			cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
			cout<<"\t\t\t\t\t\t\t    || 1. Cari Nama Makanan                      ||"<<endl;
			cout<<"\t\t\t\t\t\t\t    || 2. Cari Nama Minuman                      ||"<<endl;
			cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
			cout<<"\n";
			cout<<"\t\t\t\t\t\t\t          Pilih : ";cin >> secara;
			cout<<"\t\t\t\t\t\t\t    ==============================================="<<endl;
			
			switch(secara) {
				case 1:
					searchNamamakan(kepala);
					break;
				case 2:
					searchNamaminum(kepala);
					break;
				default:
					system("cls");
					gotoXY(70,10);cout << "Pilih nomor yang ada!!!"<<endl;
					gotoXY(70,11);cout << "Enter Kembali : ";
					getch();
					goto awal;
					break;
				}
			break;
		}
        case '0':
           login();
        default:
            system("cls");
            gotoXY(70,10);cout << "Pilih nomor yang ada!!!"<<endl;
            gotoXY(70,11);cout << "Enter Kembali : ";
            getch();
    		goto ulang;
    }
	cout << "\n\t\t\t\t\t\t\t\tEnter Kembali : ";
    getch();
	goto ulang;
    
}




//====================AWAL==========================//

void login(){
	string pin,pil;
	ulang:
	system("cls");
	gotoXY(60,3);cout<<"++========================================++"<<endl;
	gotoXY(60,4);cout<<"++-----------------Login------------------++"<<endl;
	gotoXY(60,5);cout<<"++========================================++"<<endl;
	gotoXY(60,6);cout<<"++                1. User                 ++"<<endl;
	gotoXY(60,7);cout<<"++                2. Admin                ++"<<endl;
	gotoXY(60,8);cout<<"++----------------------------------------++"<<endl;
	gotoXY(60,9);cout<<"++ >> ";cin>>pil;
	if (pil == "1"){
		user();
	}
	else if (pil == "2"){
		system("cls");
		gotoXY(70,10);cout<<"Masukan Pin Admin : ";cin>>pin;
		if (pin == "110011"){
			admin(tail);
		}else{
			system("cls");
	    	gotoXY(70,10);cout << "Pilih nomor yang ada!!!"<<endl;
	    	gotoXY(70,11);cout << "Enter Kembali : ";
	    	getch();
			login();
		}
	}
	else{
		system("cls");
	    gotoXY(70,10);cout << "Pilih nomor yang ada!!!"<<endl;
	    gotoXY(70,11);cout << "Enter Kembali : ";
	    getch();
	    goto ulang;
	}
}

int main(){
	menumasuk("Ayam_Bakar","Es_Jeruk",16000,4000);
	menumasuk("Ayam_Goreng","Es_Kelapa",14000,7000);
	menumasuk("Nasgor_Biasa","Es_Teh_Manis",16000,4000);
	menumasuk("Nasgor_Udang","Lemon_Tea",18000,6000);
	menumasuk("Nasgor_Sosis","Mineral_Water",18000,4000);
	menumasuk("Nasgor_Spesial","Soft_Drink",21000,7000);
	menumasuk("Roti_Bakar","Es_Milo",12000,8000);
	menumasuk("Siomay_Goreng","Es_Teh_Susu",12000,8000);
	menumasuk("Kentang_Goreng","Soda_Gembira",10000,10000);
	menumasuk("Sosis_Goreng","Es_Sirup",10000,9000);
	menumasuk("Pisang_Keju","Jus_Alpukat",14000,10000);
	menumasuk("Onion_Ring","Jus_Jambu",15000,10000);
	menumasuk("Lumpia_Goreng","Jus_Jeruk",3000,10000);
	menumasuk("Beef_Burger","Jus_Sirsak",10000,10000);
	menumasuk("Chicken_Burger","Jus_Mangga",10000,10000);
	menumasuk("Indomie_Polos","Greentea",6000,15000);
	menumasuk("Indomie_Telor","Tarotea",8000,15000);
	menumasuk("Indomie_Sosis","Teh_Sosro",9000,8000);
	menumasuk("Indomie_Bakso","Kopi_Hangat",9000,10000);
	menumasuk("Indomie_Keju","Es_Kopi",9000,10000);
    
	login();
	
}

