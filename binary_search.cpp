#include <iostream>
using namespace std;
int main(){
	int arr[100],beg,mid,i,n,num,end,x=0,index;
	cout<<"Berapa banyak data = ";
	cin>>n;
	cout<<"Inputkan data : \n";
	for(i=0;i<n;i++){
		cout<<"Data ke "<<i+1<<": ";
		cin>>arr[i];
	}
	
	beg = 0;
	end=n-1;
	index= -1;
	cout<<"Data yang dimasukkan : ";
	for(int a=0;a<n;a++ ){
		cout<<arr[a]<<" ";
	}
	cout<<endl<<endl;
	cout<<"Data yang dicari : ";
	cin>>num;
	while(beg<=end){
		mid=(end+beg)/2;
		x++;
		if(arr[mid]==num){
			index= mid +1;
			break;
		}
		else{
		}
	}
	if(num>arr[mid]){
		beg= mid+1;
	}
	else{
		end= mid-1;
	}
		cout<<"\nProses pencarian terjadi sebanyak : "<<x;
	if(index != -1){
		cout<<"\nElemen ditemukan pada lokasi : "<<index;
	}
	else{
		cout<<"\nElement Tidak ditemukan";
	}
	
	return 0;
}
