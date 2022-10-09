#include <iostream> 
using namespace std; 
main(){ 
	int array[8]={12, 4, 5, 33, 91, 9, 1, 81}; 
	int swap, i, j; 
	cout << "Data sebelum diurutkan: " << endl; 
	
	for(i=0;i<8;i++){ 
		cout << " " << array[i]; 
	} 
	for(i=0; i<8; i++){ 
		for(j=0; j<8; j++){ 
			if(array[j]>array[j+1]){ 
				swap = array[j]; 
				array[j] = array[j+1]; 
				array[j+1] = swap; 
			} 
		} 
	} 
	cout << endl << endl << "Data sesudah diurutkan: " << 
	endl; 
	for(i=0;i<8;i++){ 
	cout << " " << array[i]; 
	} 
} 
