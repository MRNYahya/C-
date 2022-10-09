#include<iostream>
#include<conio.h>
#include <windows.h>
#include<math.h>
#include <fstream>

using namespace std;

struct pesanan {
    string nomormeja;
	int nomakanan, nominuman, konfir;
    pesanan* prev;
    pesanan* next;
};

struct menu{
	string namamakanan,namaminuman;
	int hargamakanan,hargaminuman;
	menu *next;
};



struct pesananjadi{
	string nomormeja,namamakanan,namaminuman;
	int hargamakanan,hargaminuman,total,konfir;
	pesananjadi* next;
    pesananjadi* prev;
};

pesananjadi *awal = NULL, *akhir = NULL,*stp;

menu *kepala;
menu  *ekor ;
int panjangmenu = 0;

pesanan *head = NULL,*tail = NULL,*del;
int panjang_node = 0;
int pesanan_sdh = 0;

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

void login();
void showpesanan_blm(pesanan* tail);
void showpesanan(pesanan* tail,pesananjadi *akhir);
void showpesanan_sdh(pesananjadi *akhir);

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

void konfirpesanan(pesanan *tail){
	string a;
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
	        	tail = tail->prev;
	        	pesanan_sdh++;
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
}

void hpsdatamasuk(pesanan **head,pesanan **tail){
	if(*head == *tail){
		*head = NULL;
		*tail = NULL;
		return;
	}
	del = *tail;
	*tail = (*tail)->prev;
	(*tail)->next = NULL;
	delete del;	
	panjang_node--;
}

void masukanpesanan(pesananjadi **awal, pesananjadi **akhir){
	pesananjadi *jadi  = new pesananjadi();
	if (tail == NULL) {
		return;
	}
	else{
		for (int y = 1; y <=panjang_node; y++){
			struct menu *makan;
			makan = kepala ;
			struct menu *minum;
			minum = kepala ;
			for (int x = 1 ; x <=panjangmenu;x++){
				if(tail->nomakanan != x){
					makan = makan->next;
					minum = minum->next;
				}else{
					jadi->namamakanan  = makan->namamakanan;
					jadi->hargamakanan = makan->hargamakanan;
					jadi->namaminuman  = minum->namaminuman;
					jadi->hargaminuman = minum->hargaminuman;
					jadi->nomormeja = tail->nomormeja;
					if (*awal == NULL) {
						*awal = jadi;
						*akhir = jadi;
					} else {
						jadi->prev = NULL;
						jadi->next = *awal;
						(*awal)->prev = jadi;
						(*awal) = jadi;
					}
				}
			}
			tail = tail->prev;
		}
	}
	return;
}

int admin(){
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
    		konfirpesanan(tail);
    		masukanpesanan(&awal,&akhir);
			break;
		}
		case '2':{
			showpesanan_blm(tail);
			break;
		}
		case '3':{
			showpesanan_sdh(akhir);
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

//====================USER==========================//

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
			if (Left[g].hargamakanan <= Right[h].hargamakanan) {
				mkn[i] = Left[g];
				g++;
			} else {
				mkn[i] = Right[h];
				h++;
			}
			i++;
		}
		while (g < n1 && h < n2) {
			if (Left[g].hargaminuman >= Right[h].hargaminuman) {
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
		while (g < n1 && h < n2) {
			if (Left[g].hargaminuman <= Right[h].hargaminuman) {
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
	return -1;
}

void searchHarga(menu *nilai){
    int x;
    menu info[panjangmenu];
    menu* nilai_tampung = nilai;
    menu* data_sebelumnya = nilai;

    for (int i = 0; i < panjangmenu; i++) {
		info[i].namamakanan = nilai->namamakanan;
		info[i].hargamakanan = nilai->hargamakanan;
        info[i].namaminuman = nilai->namaminuman;
		info[i].hargaminuman = nilai->hargaminuman;
		nilai = nilai->next;
	}

    mergeSortHarga(info, 0, panjangmenu - 1, true);
    for (int i = 0; i < panjangmenu; i++) {
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
    int indeks = jumpSearchHarga(info, x, panjangmenu);
    if (indeks != -1) {
		printf("Nama Makanan  : %s\n", info[indeks].namamakanan.c_str());
        printf("Harga Makanan : %d\n", info[indeks].hargamakanan);
    } else {
        cout << "Harga tidak ditemukan pada menu!!!" << endl;
    }
    cout << "-----------------------------------------------";
}

void sort(menu* nilai) {
    menu info[panjangmenu];
    menu* nilai_tampung = nilai;
    menu* data_sebelumnya = nilai;

    for (int i = 0; i < panjangmenu; i++) {
		info[i].namamakanan = nilai->namamakanan;
		info[i].hargamakanan = nilai->hargamakanan;
		info[i].namaminuman = nilai->namaminuman;
		info[i].hargaminuman = nilai->hargaminuman;
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
    cout << "-----------------------------------------------" << endl;
    cout << "Pilih : ";cin >> pilih;
    
    switch(pilih) {
        case Harga_Asc:
            cout << "\n-----------------------------------------------";
            mergeSortHarga(info, 0, panjangmenu - 1, true);
            goto reset_linkedlist;
            break;
        case Harga_Des:
            cout << "\n-----------------------------------------------";
            mergeSortHarga(info, 0, panjangmenu - 1, false);
            goto reset_linkedlist;
            break;
        default:
            cout << "\nPilih nomor yang ada!!!";
            getch();
            goto ulang;
    }
    reset_linkedlist:
		for(int i = 0; i < panjangmenu; i++) {
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
        cout << "\n             Berhasil Diurutkan" << endl;
        cout << "-----------------------------------------------";
}

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


void showpesanan_sdh(pesananjadi *akhir){
	system("cls");
	if (akhir == NULL) {
		system("cls");
		gotoXY(60,5);cout<<"==================== Daftar Menu =================="<<endl;
		gotoXY(60,6);cout<<"++                Belum Ada Pesanan              ++"<<endl;
		gotoXY(60,7);cout<<"==================================================="<<endl;
		return;
	}else{
		system("cls");
	    gotoXY(60,5);cout<<"================= Daftar Menu ================="<<endl;;
		gotoXY(60,6);cout<<"-----------------------------------------------"<<endl;
		for (int x = 0; x<pesanan_sdh;x++){
	        cout<<"\n";
			cout<<"\t\t\t\t\t\t\t    ===============================================" << endl;
	        cout<<"\t\t\t\t\t\t\t                      No pesanan "<< x+1<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        cout<<"\t\t\t\t\t\t\t    No Meja       : "<<akhir->nomormeja<<endl;
	        cout<<"\t\t\t\t\t\t\t    Nama Makanan  : "<<akhir->namamakanan<<endl;
	        cout<<"\t\t\t\t\t\t\t    Nama Minuman  : "<<akhir->namaminuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    Harga Makanan : Rp."<<akhir->hargamakanan<<endl;
	        cout<<"\t\t\t\t\t\t\t    Harga Minuman : Rp."<<akhir->hargaminuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    Total         : Rp."<<akhir->hargamakanan+awal->hargaminuman<<endl;
	        cout<<"\t\t\t\t\t\t\t    --------------Pesanan Ini Sudah Siap-----------"<<endl;
	        cout<<"\t\t\t\t\t\t\t    -----------------------------------------------" << endl;
	        akhir = akhir->prev;
		}
	}
}

void showpesanan_blm(pesanan* tail){
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
    gotoXY(48,15);cout<<"++========================== Tambah Data ===========================++"<<endl;
	gotoXY(48,16);cout<<"++--------------------------  Data No."<<panjang_node+1<<"  ---------------------------++"<<endl;
	gotoXY(48,17);cout<<"++==================================================================++"<<endl;
	gotoXY(48,18);cout<<"\n";
    gotoXY(48,19);cout<<"                       1. Nomor Meja Anda  >> ";cin >> baru->nomormeja;
	gotoXY(48,20);cout<<"                       2. Nomor Makanan    >> ";cin >> baru->nomakanan;
	gotoXY(48,21);cout<<"                       3. Nomor Minuman    >> ";cin >> baru->nominuman;
	gotoXY(48,22);cout<<"======================================================================"<<endl;
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
    gotoXY(60,14);cout<<"================= PILIH MENU =================="<<endl;
    gotoXY(60,15);cout<<"|| 1. menu                                   ||"<<endl;
    gotoXY(60,16);cout<<"|| 2. Lihat Antrian                          ||"<<endl;
    gotoXY(60,17);cout<<"|| 3. Lihat Pesanan Siap                     ||"<<endl;
    gotoXY(60,18);cout<<"|| 4. Search Harga Menu                      ||"<<endl;
	gotoXY(60,19);cout<<"|| 5. Sort Harga Menu                        ||"<<endl;
    gotoXY(60,20);cout<<"|| 0. Keluar                                 ||"<<endl;
    gotoXY(60,21);cout<<"==============================================="<<endl;
    gotoXY(60,22);cout<<"  Pilih : ";
    cin >> pilih;
    switch(pilih) {
        case '1':{
			
        	system("cls");
        	tampilmenu();
        	tambahpesanan(&head, &tail);
		  	showpesanan_blm(tail);
            break;
        }
        case '2':{
            showpesanan_blm(tail);
            break;
        }
        case '3':{
        	showpesanan_sdh(akhir);
			break;
		}
//        case EDIT:
//            ubah();
//            break;
        case '5':
            sort(kepala);
            break;
        case '4':
            searchHarga(kepala);
            break;
//        case HAPUS:
//            hapus(&head, &tail);
//            break;
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
			admin();
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
	menumasuk("Ayam Bakar","Es Jeruk",16000,4000);
	menumasuk("Ayam Goreng","Es Kelapa",14000,7000);
	login();
}
