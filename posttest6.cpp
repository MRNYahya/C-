#include<iostream>
#include<math.h>
using namespace std;

struct db {
    int pk;
    string name;
    string element;
    string weapon;
    char tier;
    db* prev;
    db* next;
};

string newname;
string newelement;
string newweapon;
char newtier;

db *head_node = new db();
db *tail_node = new db();
int panjang_node = 5;

void algoMergeID(db *arr, int left, int mid, int right, bool order) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	db Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = arr[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = arr[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (order) {
		while (g < n1 && h < n2) {
			if (Left[g].pk <= Right[h].pk) {
				arr[i] = Left[g];
				g++;
			} else {
				arr[i] = Right[h];
				h++;
			}
			i++;
		}
	} else {
		while (g < n1 && h < n2) {
			if (Left[g].pk >= Right[h].pk) {
				arr[i] = Left[g];
				g++;
			} else {
				arr[i] = Right[h];
				h++;
			}
			i++;
		}
	}
	
	while (g < n1) {
		arr[i] = Left[g];
		g++;
		i++;
	}
	
	while (h < n2) {
		arr[i] = Right[h];
		h++;
		i++;
	}
}

void declareMergeID(db *arr, int left, int right, bool order) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		declareMergeID(arr, left, mid, order);
		declareMergeID(arr, mid + 1, right, order);
		
		algoMergeID(arr, left, mid, right, order);
	}
}

void algoMergeName(db *arr, int left, int mid, int right, bool order) {
	int g, h, i;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	
	db Left[n1], Right[n2];
	
	for (g = 0; g < n1; g++)
		Left[g] = arr[left + g];
	for (h = 0; h < n2; h++)
		Right[h] = arr[mid + 1 + h];
	
	g = 0;
	h = 0;
	i = left;
	if (order) {
		while (g < n1 && h < n2) {
			if (Left[g].name <= Right[h].name) {
				arr[i] = Left[g];
				g++;
			} else {
				arr[i] = Right[h];
				h++;
			}
			i++;
		}
	} else {
		while (g < n1 && h < n2) {
			if (Left[g].name >= Right[h].name) {
				arr[i] = Left[g];
				g++;
			} else {
				arr[i] = Right[h];
				h++;
			}
			i++;
		}
	}
	
	while (g < n1) {
		arr[i] = Left[g];
		g++;
		i++;
	}
	
	while (h < n2) {
		arr[i] = Right[h];
		h++;
		i++;
	}
}

void declareMergeName(db *arr, int left, int right, bool order) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		declareMergeName(arr, left, mid, order);
		declareMergeName(arr, mid + 1, right, order);
		
		algoMergeName(arr, left, mid, right, order);
	}
}

int jumpSearchID(db *arr, int x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(arr[min(step, n)-1].pk < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(arr[prev].pk < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(arr[prev].pk == x) {
        return prev;
    }
	return -1;
}

int jumpSearchName(db *arr, string x, int n) {
	int step = sqrt(n);
	int prev = 0;

	while(arr[min(step, n)-1].name < x) {
		prev = step;
		step += sqrt(n);
		if (prev >= n) {
            return -1;
        }
	}

	while(arr[prev].name < x) {
		prev++;
		if(prev == min(step, n)) {
            return -1;
        }
	}
	if(arr[prev].name == x) {
        return prev;
    }
	return -1;
}

void show(db *value) {
    int indeks = 1;

    system("cls");
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nMy Database" << endl;
    cout << "<><><><><><><><><><><><><><><>\n";
    for(int i = 0; i < panjang_node; i++) {
        printf("\nData No. %d\n", indeks);
        printf("ID\t: %d\n", value->pk);
        printf("Name\t: %s\n", value->name.c_str());
        printf("Element\t: %s\n", value->element.c_str());
        printf("Weapon\t: %s\n", value->weapon.c_str());
        printf("Tier\t: %c\n", value->tier);
        value = value->next;
        indeks++;
    }
    cout << "\n<><><><><><><><><><><><><><><>";
}

void sort(db *value) {
    db infochara[panjang_node];
    db* value_tampung = value;
    db* data_sebelumnya = value;

    for (int i = 0; i < panjang_node; i++) {
		infochara[i].pk = value->pk;
		infochara[i].name = value->name;
		infochara[i].element = value->element;
		infochara[i].weapon = value->weapon;
		infochara[i].tier = value->tier;
		value = value->next;
	}

    ngulang:
    system("cls");
    int choice;
    enum opsi{ID_ASCEND = 1, ID_DESCEND, NAME_ASCEND, NAME_DESCEND};

    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nSort Database" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\n1) ID (Ascending)" << endl;
    cout << "2) ID (Descending)" << endl;
    cout << "3) Name (Ascending)" << endl;
    cout << "4) Name (Descending)" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\n\nChoice : ";
    cin >> choice;
    switch(choice) {
        case ID_ASCEND:
            cout << "\n<><><><><><><><><><><><><><><>";
            declareMergeID(infochara, 0, panjang_node - 1, true);
            goto reset_linkedlist;
            break;
        case ID_DESCEND:
            cout << "\n<><><><><><><><><><><><><><><>";
            declareMergeID(infochara, 0, panjang_node - 1, false);
            goto reset_linkedlist;
            break;
        case NAME_ASCEND:
            cout << "\n<><><><><><><><><><><><><><><>";
            declareMergeName(infochara, 0, panjang_node - 1, true);
            goto reset_linkedlist;
            break;
        case NAME_DESCEND:
            cout << "\n<><><><><><><><><><><><><><><>";
            declareMergeName(infochara, 0, panjang_node - 1, false);
            goto reset_linkedlist;
            break;
        default:
            cout << "\nChoose Correctly!";
            cout << "\n\n";
            system("pause");
            goto ngulang;
    }
    reset_linkedlist:
		for(int i = 0; i < panjang_node; i++) {
			value_tampung->pk = infochara[i].pk;
			value_tampung->name = infochara[i].name;
			value_tampung->element = infochara[i].element;
			value_tampung->weapon = infochara[i].weapon;
			value_tampung->tier = infochara[i].tier;
			if (i == 0) {
				data_sebelumnya = value_tampung;
			} else {
				data_sebelumnya->next = value_tampung;
				data_sebelumnya = data_sebelumnya->next;
			}
			value_tampung = value_tampung->next;
		}
        cout << "\nDatabase Sorted!" << endl;
        cout << "<><><><><><><><><><><><><><><>\n\n";
}

void searchID(db *value) {
    int choice;
    db infochara[panjang_node];
    db* value_tampung = value;
    db* data_sebelumnya = value;

    for(int i = 0; i < panjang_node; i++) {
        infochara[i].pk = value->pk;
		infochara[i].name = value->name;
		infochara[i].element = value->element;
		infochara[i].weapon = value->weapon;
		infochara[i].tier = value->tier;
		value = value->next;
    }
    declareMergeID(infochara, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		value_tampung->pk = infochara[i].pk;
		value_tampung->name = infochara[i].name;
		value_tampung->element = infochara[i].element;
		value_tampung->weapon = infochara[i].weapon;
		value_tampung->tier = infochara[i].tier;
		if (i == 0) {
			data_sebelumnya = value_tampung;
		} else {
			data_sebelumnya->next = value_tampung;
			data_sebelumnya = data_sebelumnya->next;
		}
		value_tampung = value_tampung->next;
	}

    system("cls");
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nSearch by ID" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nInput ID You Want To Search :" << endl;
    cin >> choice;
    cout << "<><><><><><><><><><><><><><><>" << endl;
    int indeks = jumpSearchID(infochara, choice, panjang_node);
    if (indeks != -1) {
        printf("ID\t: %d\n", infochara[indeks].pk);
        printf("Name\t: %s\n", infochara[indeks].name.c_str());
        printf("Element\t: %s\n", infochara[indeks].element.c_str());
        printf("Weapon\t: %s\n", infochara[indeks].weapon.c_str());
        printf("Tier\t: %c\n", infochara[indeks].tier);
    } else {
        cout << "Data Not Found!" << endl;
    }
    cout << "<><><><><><><><><><><><><><><>";
}

void searchName(db *value) {
    string choice;
    db infochara[panjang_node];
    db* value_tampung = value;
    db* data_sebelumnya = value;

    for(int i = 0; i < panjang_node; i++) {
        infochara[i].pk = value->pk;
		infochara[i].name = value->name;
		infochara[i].element = value->element;
		infochara[i].weapon = value->weapon;
		infochara[i].tier = value->tier;
		value = value->next;
    }
    declareMergeName(infochara, 0, panjang_node - 1, true);
    for (int i = 0; i < panjang_node; i++) {
		value_tampung->pk = infochara[i].pk;
		value_tampung->name = infochara[i].name;
		value_tampung->element = infochara[i].element;
		value_tampung->weapon = infochara[i].weapon;
		value_tampung->tier = infochara[i].tier;
		if (i == 0) {
			data_sebelumnya = value_tampung;
		} else {
			data_sebelumnya->next = value_tampung;
			data_sebelumnya = data_sebelumnya->next;
		}
		value_tampung = value_tampung->next;
	}

    system("cls");
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nSearch by Name" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nInput Name You Want To Search :" << endl;
    cin >> choice;
    cout << "<><><><><><><><><><><><><><><>" << endl;
    int indeks = jumpSearchName(infochara, choice, panjang_node);
    if (indeks != -1) {
        printf("ID\t: %d\n", infochara[indeks].pk);
        printf("Name\t: %s\n", infochara[indeks].name.c_str());
        printf("Element\t: %s\n", infochara[indeks].element.c_str());
        printf("Weapon\t: %s\n", infochara[indeks].weapon.c_str());
        printf("Tier\t: %c\n", infochara[indeks].tier);
    } else {
        cout << "Data Not Found!" << endl;
    }
    cout << "<><><><><><><><><><><><><><><>";
}

void search() {
    ngulang:
    system("cls");
    int choice;
    enum opsi{ID_SEARCH = 1, NAME_SEARCH};

    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nSearch Data" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\n1) By ID" << endl;
    cout << "2) By Name" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\n\nChoice : ";
    cin >> choice;
    switch(choice) {
        case ID_SEARCH:
            searchID(head_node);
            break;
        case NAME_SEARCH:
            searchName(head_node);
            break;
        default:
            cout << "\nChoose Correctly!";
            cout << "\n\n";
            system("pause");
            goto ngulang;
    }
}

void add(db **head, db **tail) {
    db *value_baru = new db();
    int index = 1;

    system("cls");
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nAdd a Data" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    if(*head != NULL) {
		cout << "\nData No. ";
		cin >> index;
		if(index > panjang_node) {
			index = panjang_node + 1;
		}
	}
    cout << "1)\tID : ";
    cin >> value_baru->pk;
    cout << "2)\tName : ";
    cin >> value_baru->name;
    cout << "3)\tElement : ";
    cin >> value_baru->element;
    cout << "4)\tWeapon Type : ";
    cin >> value_baru->weapon;
    cout << "5)\tTier : ";
    cin >> value_baru->tier;

	if(*head == NULL){
		*head = value_baru;
		*tail = value_baru;
		panjang_node++;
		return;
	}

    if(index == 1) {
        value_baru->prev = NULL;
        value_baru->next = *head;
        (*head)->prev = value_baru;
        (*head) = value_baru;
    } else if(index == panjang_node + 1) {
        value_baru->prev = *tail;
        value_baru->next = NULL;
        (*tail)->next = value_baru;
        *tail = value_baru;
    } else {
        db* data_sementara = *head;
        for(int i = 1; i < index; i++) {
            data_sementara = data_sementara->next;
        }
        value_baru->prev = data_sementara->prev;
        value_baru->next = data_sementara;
        data_sementara->prev->next = value_baru;
        data_sementara->prev = value_baru;
    }
    panjang_node++;
    cout << "<><><><><><><><><><><><><><><>";
}

void update(db *node_keN) {
    int choice;

    ngulang:
    system("cls");
    show(head_node);
    cout << "\nChoose by Data Number : ";
    cin >> choice;
    for (int i = 0; i < choice - 1; i++) {
        node_keN = node_keN->next;
	}

    cout << "<><><><><><><><><><><><><><><>";
    cout << "\n1)\tNew Name : ";
    cin >> newname;
    cout << "2)\tNew Element : ";
    cin >> newelement;
    cout << "3)\tNew Weapon Type : ";
    cin >> newweapon;
    cout << "4)\tNew Tier : ";
    cin >> newtier;
    
    node_keN->name = newname;
    node_keN->element = newelement;
    node_keN->weapon = newweapon;
    node_keN->tier = newtier;

    cout << "<><><><><><><><><><><><><><><>";
}

void del(db **head, db **tail) {
    int choice;
    system("cls");
    show(head_node);

    if (*head == NULL) {
		cout << "\nNo Data!";
        cout << "\nDelete Failed";
        cout << "\n<><><><><><><><><><><><><><><>";
		return;
	} else {
        db* data_sementara = *head;
		if(*head == *tail) {
			*head = NULL;
			*tail = NULL;
			return;
		}
        cout << "\nChoose by Data Number : ";
        cin >> choice;
        cout << "<><><><><><><><><><><><><><><>";
		if(choice == 1) {
			*head = data_sementara->next;
			(*head)->prev = NULL;
			delete data_sementara;
			panjang_node--;
		} else if(choice == panjang_node) {
			data_sementara = *tail;
			*tail = data_sementara->prev;
			(*tail)->next = NULL;
			delete data_sementara;
			panjang_node--;
		} else {
			for(int i = 1; i < choice; i++) {
				data_sementara = data_sementara->next;
			}
			data_sementara->next->prev = data_sementara->prev;
			data_sementara->prev->next = data_sementara->next;
			delete data_sementara;
			panjang_node--;
		}
        cout << "\nDelete Success";
        cout << "\n<><><><><><><><><><><><><><><>";
	}
}

main() {
    db* value_keDua = new db();
    db* value_keTiga = new db();
    db* value_keEmpat = new db();
    
    head_node->pk = 500;
    head_node->name = "Eula";
    head_node->element = "Cryo";
    head_node->weapon = "Claymore";
    head_node->tier = 's';
    head_node->prev = NULL;
    head_node->next = value_keDua;

    value_keDua->pk = 69;
    value_keDua->name = "Diluc";
    value_keDua->element = "Pyro";
    value_keDua->weapon = "Claymore";
    value_keDua->tier = 's';
    value_keDua->prev = head_node;
    value_keDua->next = value_keTiga;

    value_keTiga->pk = 1989;
    value_keTiga->name = "Kokusei";
    value_keTiga->element = "Electro";
    value_keTiga->weapon = "Sword";
    value_keTiga->tier = 'a';
    value_keTiga->prev = value_keDua;
    value_keTiga->next = value_keEmpat;

    value_keEmpat->pk = 1;
    value_keEmpat->name = "Ayaka";
    value_keEmpat->element = "Cryo";
    value_keEmpat->weapon = "Sword";
    value_keEmpat->tier = 's';
    value_keEmpat->prev = value_keTiga;
    value_keEmpat->next = tail_node;

    tail_node->pk = 37;
    tail_node->name = "Yanfei";
    tail_node->element = "Pyro";
    tail_node->weapon = "Catalyst";
    tail_node->tier = 'a';
    tail_node->prev = value_keEmpat;
    tail_node->next = NULL;

    ngulang:
    system("cls");
    int choice;
    enum opsi{LIHAT = 1, URUT, CARI, TAMBAH, UBAH, HAPUS};

    cout << "<><><><><><><><><><><><><><><>";
    cout << "\nMy Genshin Impact Database" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\n1) Show Database" << endl;
    cout << "2) Sort Database" << endl;
    cout << "3) Search Data" << endl;
    cout << "4) Add a Data" << endl;
    cout << "5) Change a Data" << endl;
    cout << "6) Delete a Data" << endl;
    cout << "0) Exit" << endl;
    cout << "<><><><><><><><><><><><><><><>";
    cout << "\n\nChoice : ";
    cin >> choice;
    switch(choice) {
        case LIHAT:
        system("cls");
            show(head_node);
            break;
        case URUT:
            sort(head_node);
            break;
        case CARI:
            search();
            break;
        case TAMBAH:
            add(&head_node, &tail_node);
            break;
        case UBAH:
            update(head_node);
            break;
        case HAPUS:
            del(&head_node, &tail_node);
            break;
        case 0:
            exit(0);
        default:
            cout << "\nChoose Correctly!";
    }
    cout << "\n\n";
    system("pause");
    goto ngulang;
}