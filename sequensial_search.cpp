#include <iostream>
using namespace std;
int main(){
	int dataku[10]={7,9,2,10,15,4,5,10,13,11};
	int caridata, i;
	bool flag;
	cout<<"SEQUENTIAL SEARCH"<<endl;
	cout<<" ----------------"<<endl;
	cout<<"Data :";
	for(int n=0;n<10;n++){
		cout<<dataku[n]<<" ";
	}
	cout<<endl;
	cout<<"Masukkan data yang ingin anda cari : ";
	cin>>caridata;
	
	for(i=0;i<10;i++){
		if(dataku[i]==caridata){
			flag = true;
			break;
		}
	}
	if(flag==1){
		cout<<"Data ditemukan pada urutan ke "<<i+1<<endl;
	}
	else{
		cout<<"Data tidak ada"<<endl;
	}
	return 0;
}

